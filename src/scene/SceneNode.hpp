
#include <memory>
#include <string>
#include <vector>

namespace llama
{

class SceneNode
{
public:
    SceneNode(std::string name)
    : m_name(name)
    {
    }

    std::string getName() {
        return m_name;
    }

    int getRefCount() {
        return m_refCount;
    }

    void retain() {
        if (getRefCount() == 0) {
            for (auto dependency : m_dependencies) {
                dependency->retain();
            }
        }
        m_refCount++;
    }

    void release() {
        m_refCount--;
        if (getRefCount() == 0) {
            destroy();
        }
    }

    void destroy() {
        for (auto dependency : m_dependencies) {
            dependency->release();
        }
        m_refCount = 0;
    }

/*    void addDependency(std::shared_ptr<SceneNode> dependency) {
        if (!m_dependencies.contains(dependency)) {
            m_dependencies.add(dependency);
            dependency.retain();
        }
    }
    */
/*
    void buildLevelsToUnloadListRecursive(std::vector<std::string> scenesToUnloadNames,
            List<SceneNode> visitedNodes) {
        // Don't allow scene nodes to be visited twice
        if (visitedNodes.contains(this)) {
            return;
        }
        visitedNodes.add(this);

        // Visit dependencies as well
        for (SceneNode dependency : dependencies) {
            dependency.buildLevelsToUnloadListRecursive(scenesToUnloadNames,
                    visitedNodes);
        }

        // Add this scene node to the scenes to unload list if it's loaded and
        // it shouldn't
        if (refCount == 0 && loaded) {
            scenesToUnloadNames.add(name);
        }
    }

    void buildLevelsToLoadListRecursive(List<String> scenesToLoadNames,
            List<SceneNode> visitedNodes) {
        // Don't allow scene nodes to be visited twice
        if (visitedNodes.contains(this)) {
            return;
        }
        visitedNodes.add(this);

        // Visit dependencies as well
        for (SceneNode dependency : dependencies) {
            dependency
                    .buildLevelsToLoadListRecursive(scenesToLoadNames, visitedNodes);
        }

        // Add this scene node to the scenes to load list if it's not already
        // loaded and it should
        if (refCount != 0 && !loaded) {
            scenesToLoadNames.add(name);
        }
    }
    */

/*
    void cleanGraphRecursive() {
        loaded = getRefCount() != 0;

        Iterator<SceneNode> iter = dependencies.iterator();
        while (iter.hasNext()) {
            SceneNode dependency = iter.next();
            if (dependency.getRefCount() == 0) {
                iter.remove();
            } else {
                dependency.cleanGraphRecursive();
            }
        }
    }*/

/*
    std::weak_ptr<SceneNode> findScene(const std::string& sceneName) {
        return findSceneRecursive(sceneName, this);
    }
    */

private:
    std::string m_name;
    std::vector<std::shared_ptr<SceneNode>> m_dependencies;
    int m_refCount = 0;
    bool m_loaded = false;

/*
    std::weak_ptr<SceneNode> findSceneRecursive(std::string scene, const SceneNode* node) {
        for (auto childNode : node->dependencies) {
            auto foundScene = findSceneRecursive(scene, childNode);
            if (foundScene != null) {
                return foundScene;
            }
        }
        if (node->m_name.equals(scene)) {
            return node;
        } else {
            return null;
        }
    }
    */
};

}