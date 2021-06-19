#include "SceneNode.hpp"

#include <optional>
#include <vector>

namespace llama {

class ScenesGraph {

public:
    void markSceneForAdd(const std::string& sceneToAddName, std::optional<std::string> parentSceneName,
            const std::vector<std::string>& dependenciesNames);
    void markSceneForRemove(const std::string& sceneToRemoveName);
    void markAllScenesForRemove();

    void buildLevelsToUnloadList(std::vector<std::string>& levelsToUnload);
    void buildLevelsToLoadList(std::vector<std::string>& levelsToLoad);

    void clean();

private:
    std::optional<std::shared_ptr<SceneNode>> findScene(const std::string& sceneName);
    std::vector<std::shared_ptr<SceneNode>> rootNodes;
};

}