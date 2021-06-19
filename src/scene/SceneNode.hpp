
#include <memory>
#include <string>
#include <vector>

namespace llama {

class SceneNode {
public:
    SceneNode(std::string name);

    std::string getName();

    int getRefCount();
    void retain();
    void release();
    void destroy();

    void addDependency(std::shared_ptr<SceneNode> dependency);

    void buildLevelsToUnloadListRecursive(std::vector<std::string> scenesToUnloadNames,
            std::vector<const SceneNode*> visitedNodes);
    void buildLevelsToLoadListRecursive(std::vector<std::string> scenesToLoadNames,
            std::vector<const SceneNode*> visitedNodes);
    void cleanGraphRecursive();

    std::weak_ptr<SceneNode> findScene(const std::string& sceneName);

private:
    std::weak_ptr<SceneNode> findSceneRecursive(std::string scene, const SceneNode* node);

    std::string m_name;
    std::vector<std::shared_ptr<SceneNode>> m_dependencies;
    int m_refCount = 0;
    bool m_loaded = false;
};

}