#include "SceneGraph.hpp"

#include <algorithm>
#include <vector>

namespace llama {

void ScenesGraph::markSceneForAdd(const std::string& sceneToAddName, std::optional<std::string> parentSceneName,
        const std::vector<std::string>& dependenciesNames) {
    // Validate that if a parent scene is given, it already exists in the
    // graph
    if (parentSceneName.has_value() && findScene(parentSceneName.value()).has_value()) {
        //Logger.logError(Category.LOADING,
        //        "Trying to load a scene with an invalid parent");
        return;
    }

    // Create a new scene node or use the one that we already have in the
    // graph
    auto sceneNodeBeingAdded = findScene(sceneToAddName);
    if (!sceneNodeBeingAdded.has_value()) {
        sceneNodeBeingAdded = std::make_shared<SceneNode>(sceneToAddName);
    }

    // If no parent have been specified, add the newly created node as a
    // root node
    if (!parentSceneName.has_value()) {
        rootNodes.push_back(sceneNodeBeingAdded.value());
        sceneNodeBeingAdded.value().get()->retain();
    } else {
        // Add the newly created scene node as a dependency of its parent
        auto parentSceneNode = findScene(parentSceneName.value());
        parentSceneNode.value().get()->addDependency(sceneNodeBeingAdded.value());
    }

    // Create all inexistent dependencies and link them
    for (auto dependency : dependenciesNames) {
        auto dependencyNode = findScene(dependency);
        if (!dependencyNode.has_value()) {
            dependencyNode = std::make_shared<SceneNode>(dependency);
        } else {
            // Remove the dependency from the root nodes if it's an old root
            // node
            for (auto sceneNode : rootNodes) {
                if (sceneNode->getName().compare(dependency) == 0
                    && sceneNode->getRefCount() == 0) {                
                    //rootNodes.remove(dependencyNode);
                }
            }
        }
        //sceneNodeBeingAdded.addDependency(dependencyNode);
    }
}

void ScenesGraph::markSceneForRemove(const std::string& sceneToRemoveName) {
    auto sceneToRemoveNode = findScene(sceneToRemoveName);
    if (!sceneToRemoveNode.has_value()) {
        //Logger.logError(Category.LOADING,
        //        "Trying to remove unexistant scene");
        return;
    }

    sceneToRemoveNode.value().get()->destroy();
}

void ScenesGraph::markAllScenesForRemove() {
    for (auto rootNode : rootNodes) {
        rootNode.get()->release();
    }
}

void ScenesGraph::buildLevelsToUnloadList(std::vector<std::string>& levelsToUnload) {
    std::vector<const SceneNode*> visitedNodes;
    for (auto rootNode : rootNodes) {
        rootNode.get()->buildLevelsToUnloadListRecursive(levelsToUnload, visitedNodes);
    }
    std::reverse(levelsToUnload.begin(),levelsToUnload.end());
}

void ScenesGraph::buildLevelsToLoadList(std::vector<std::string>& levelsToLoad) {
    std::vector<const SceneNode*> visitedNodes;
    for (auto rootNode : rootNodes) {
        rootNode.get()->buildLevelsToLoadListRecursive(levelsToLoad, visitedNodes);
    }
}

void ScenesGraph::clean() {
    /*Iterator<SceneNode> iter = rootNodes.iterator();
    while (iter.hasNext()) {
        SceneNode rootNode = iter.next();
        if (rootNode.getRefCount() == 0) {
            iter.remove();
        } else {
            rootNode.cleanGraphRecursive();
        }
    }*/
}

std::optional<std::shared_ptr<SceneNode>> ScenesGraph::findScene(const std::string& sceneName) {
    for (auto rootNode : rootNodes) {
        auto foundSceneNode = rootNode.get()->findScene(sceneName);
        if (foundSceneNode.get() != nullptr) {
            return foundSceneNode;
        }
    }
    return std::nullopt;
}

}
