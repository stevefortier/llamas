
/*

package eggscape.core.world.scene;

import com.artemis.Entity;
import com.artemis.World;
import com.artemis.utils.ImmutableBag;

import eggscape.core.Logger;
import eggscape.core.Logger.Category;
import eggscape.core.world.entities.EntityFactory;
import eggscape.core.xml.SceneXmlData;
import eggscape.core.xml.XmlLoader;
import eggscape.core.xml.exceptions.XmlLoadingException;

public class SceneLoader {

    private final ScenesGraph scenesGraph = new ScenesGraph();
    private final String scenesPath;
    private final World world;
    private final XmlLoader xmlLoader;
    private final EntityFactory entityFactory;

    public SceneLoader(World world, XmlLoader xmlLoader, String scenesPath,
            EntityFactory entityFactory) {
        this.scenesPath = scenesPath;
        this.world = world;
        this.xmlLoader = xmlLoader;
        this.entityFactory = entityFactory;
    }

    public void loadSceneFromPath(String rootSceneToLoadPath) {
        // Resolve the scenes to unload/load
        updateSceneGraphWithSceneToLoad(rootSceneToLoadPath);

        // Unload outdated scenes in the order specified by the scenes graph
        for (String currentSceneToUnloadPath : scenesGraph
                .buildLevelsToUnloadList()) {
            Logger.logCenteredInfo(Category.LOADING, " Unloading scene "
                    + currentSceneToUnloadPath + " ", '-');
            unloadIndividualScene(currentSceneToUnloadPath);
            Logger.logCenteredInfo(Category.LOADING, " Unloaded scene "
                    + currentSceneToUnloadPath + " successfully ", '-');
        }

        // Load all wanted scenes that are not present, in the order specified
        // by the scenes graph
        for (String currentSceneToLoadPath : scenesGraph
                .buildLevelsToLoadList()) {
            Logger.logCenteredInfo(Category.LOADING, " Loading scene "
                    + currentSceneToLoadPath + " ", '-');
            try {
                loadIndividualScene(currentSceneToLoadPath);
            } catch (XmlLoadingException e) {
                Logger.logException(Category.LOADING, e,
                        "Exception thrown while loading scene");
            }

            Logger.logCenteredInfo(Category.LOADING, " Loaded scene "
                    + currentSceneToLoadPath + " successfully ", '-');
        }

        scenesGraph.clean();
    }

    private void updateSceneGraphWithSceneToLoad(String rootSceneToLoadPath) {
        scenesGraph.markAllScenesForRemove();
        if (rootSceneToLoadPath != null) {
            try {
                markAllRequiredScenesForAddRecursive(rootSceneToLoadPath, null);
            } catch (XmlLoadingException e) {
                Logger.logException(Category.LOADING, e,
                        "Failed to resolve dependencies to load "
                                + rootSceneToLoadPath);
            }
        }
    }

    private void markAllRequiredScenesForAddRecursive(String sceneToLoadPath,
            String parentScenePath) throws XmlLoadingException {
        SceneXmlData sceneXmlData = xmlLoader.loadScene(scenesPath + sceneToLoadPath);
        scenesGraph.markSceneForAdd(sceneToLoadPath, parentScenePath,
                sceneXmlData.getDependenciesPaths());
        for (String dependency : sceneXmlData.getDependenciesPaths()) {
            markAllRequiredScenesForAddRecursive(dependency, sceneToLoadPath);
        }
    }

    private void unloadIndividualScene(String currentSceneToUnloadPath) {
        ImmutableBag<Entity> entitiesToRemove = world.getGroupManager()
                .getEntities(currentSceneToUnloadPath);
        for (int i = 0; i < entitiesToRemove.size(); ++i) {
            world.deleteEntity(entitiesToRemove.get(i));
        }

        world.refreshEntitiesStatusAndAffiliation();
    }

    private void loadIndividualScene(String currentSceneToLoadPath)
            throws XmlLoadingException {
        SceneXmlData sceneXmlData = xmlLoader.loadScene(scenesPath + currentSceneToLoadPath);
        Entity[] createdEntities = entityFactory
                .createEntitiesFromXml(sceneXmlData.getEntities());

        for (Entity createdEntity : createdEntities) {
            createdEntity.setGroup(currentSceneToLoadPath);
            createdEntity.refresh();
        }

        world.refreshEntitiesStatusAndAffiliation();
    }
}
*/