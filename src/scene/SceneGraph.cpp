

/*

package eggscape.core.world.scene;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;
import java.util.List;

import eggscape.core.Logger;
import eggscape.core.Logger.Category;

public class ScenesGraph {

    private List<SceneNode> rootNodes = new ArrayList<SceneNode>();

    public void markSceneForAdd(String sceneToAddName, String parentSceneName,
            String[] dependenciesNames) {
        // Validate that if a parent scene is given, it already exists in the
        // graph
        if (parentSceneName != null && findScene(parentSceneName) == null) {
            Logger.logError(Category.LOADING,
                    "Trying to load a scene with an invalid parent");
            return;
        }

        // Create a new scene node or use the one that we already have in the
        // graph
        SceneNode sceneNodeBeingAdded = findScene(sceneToAddName);
        if (sceneNodeBeingAdded == null) {
            sceneNodeBeingAdded = new SceneNode(sceneToAddName);
        }

        // If no parent have been specified, add the newly created node as a
        // root node
        if (parentSceneName == null) {
            rootNodes.add(sceneNodeBeingAdded);
            sceneNodeBeingAdded.retain();
        } else {
            // Add the newly created scene node as a dependency of its parent
            SceneNode parentSceneNode = findScene(parentSceneName);
            parentSceneNode.addDependency(sceneNodeBeingAdded);
        }

        // Create all inexistent dependencies and link them
        for (String dependency : dependenciesNames) {
            SceneNode dependencyNode = findScene(dependency);
            if (dependencyNode == null) {
                dependencyNode = new SceneNode(dependency);
            } else {
                // Remove the dependency from the root nodes if it's an old root
                // node
                if (rootNodes.contains(dependencyNode)
                        && dependencyNode.getRefCount() == 0) {
                    rootNodes.remove(dependencyNode);
                }
            }
            sceneNodeBeingAdded.addDependency(dependencyNode);
        }
    }

    public void markSceneForRemove(String sceneToRemoveName) {
        SceneNode sceneToRemoveNode = findScene(sceneToRemoveName);
        if (sceneToRemoveNode == null) {
            Logger.logError(Category.LOADING,
                    "Trying to remove unexistant scene");
            return;
        }

        sceneToRemoveNode.destroy();
    }

    public void markAllScenesForRemove() {
        for (SceneNode rootNode : rootNodes) {
            if (rootNode != null) {
                rootNode.release();
            }
        }
    }

    private SceneNode findScene(String sceneName) {
        for (SceneNode rootNode : rootNodes) {
            SceneNode foundSceneNode = rootNode.findScene(sceneName);
            if (foundSceneNode != null) {
                return foundSceneNode;
            }
        }
        return null;
    }

    public String[] buildLevelsToUnloadList() {
        List<String> scenesToUnloadNames = new ArrayList<String>();
        List<SceneNode> visitedNodes = new ArrayList<SceneNode>();
        for (SceneNode rootNode : rootNodes) {
            rootNode.buildLevelsToUnloadListRecursive(scenesToUnloadNames,
                    visitedNodes);
        }
        Collections.reverse(scenesToUnloadNames);
        return scenesToUnloadNames.toArray(new String[scenesToUnloadNames
                .size()]);
    }

    public String[] buildLevelsToLoadList() {
        List<String> scenesToLoadNames = new ArrayList<String>();
        List<SceneNode> visitedNodes = new ArrayList<SceneNode>();
        for (SceneNode rootNode : rootNodes) {
            rootNode.buildLevelsToLoadListRecursive(scenesToLoadNames,
                    visitedNodes);
        }
        return scenesToLoadNames.toArray(new String[scenesToLoadNames.size()]);
    }

    public void clean() {
        Iterator<SceneNode> iter = rootNodes.iterator();
        while (iter.hasNext()) {
            SceneNode rootNode = iter.next();
            if (rootNode.getRefCount() == 0) {
                iter.remove();
            } else {
                rootNode.cleanGraphRecursive();
            }
        }
    }
}*/