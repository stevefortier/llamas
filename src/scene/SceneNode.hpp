
#include <algorithm>
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

    void addDependency(std::shared_ptr<SceneNode> dependency) {
        // Assert if (m_dependencies.contains(dependency))
        m_dependencies.push_back(dependency);
        dependency->retain();
    }

    void buildLevelsToUnloadListRecursive(std::vector<std::string> scenesToUnloadNames,
            std::vector<const SceneNode*> visitedNodes) {
        // Don't allow scene nodes to be visited twice
        if (std::count(visitedNodes.begin(), visitedNodes.end(), this) > 0) {
            return;
        }
        visitedNodes.push_back(this);

        // Visit dependencies as well
        for (auto dependency : m_dependencies) {
            dependency->buildLevelsToUnloadListRecursive(scenesToUnloadNames,
                    visitedNodes);
        }

        // Add this scene node to the scenes to unload list if it's loaded and
        // it shouldn't
        if (m_refCount == 0 && m_loaded) {
            scenesToUnloadNames.push_back(m_name);
        }
    }

    void buildLevelsToLoadListRecursive(std::vector<std::string> scenesToLoadNames,
            std::vector<const SceneNode*> visitedNodes) {
        // Don't allow scene nodes to be visited twice
        if (std::count(visitedNodes.begin(), visitedNodes.end(), this) > 0) {
            return;
        }
        visitedNodes.push_back(this);

        // Visit dependencies as well
        for (auto dependency : m_dependencies) {
            dependency->buildLevelsToLoadListRecursive(scenesToLoadNames, visitedNodes);
        }

        // Add this scene node to the scenes to load list if it's not already
        // loaded and it should
        if (m_refCount != 0 && !m_loaded) {
            scenesToLoadNames.push_back(m_name);
        }
    }

    void cleanGraphRecursive() {
        m_loaded = getRefCount() != 0;
        for (auto iter = m_dependencies.begin(); iter != m_dependencies.end(); ++iter)
        {
            if ((*iter)->getRefCount() == 0) {
                m_dependencies.erase(iter);
            } else {
                (*iter)->cleanGraphRecursive();
            }
        }
    }

    std::weak_ptr<SceneNode> findScene(const std::string& sceneName) {
        return findSceneRecursive(sceneName, this);
    }

private:
    std::weak_ptr<SceneNode> findSceneRecursive(std::string scene, const SceneNode* node) {
        for (auto childNode : node->m_dependencies) {
            if (childNode->m_name.compare(scene) == 0) {
                return childNode;
            }

            auto foundScene = findSceneRecursive(scene, childNode.get());
            if (!foundScene.expired()) {
                return foundScene;
            }
        }
        return std::weak_ptr<SceneNode>();
    }

    std::string m_name;
    std::vector<std::shared_ptr<SceneNode>> m_dependencies;
    int m_refCount = 0;
    bool m_loaded = false;
};

}