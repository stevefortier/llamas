#include "SceneNode.hpp"

#include <catch2/catch.hpp>

using namespace llama;

TEST_CASE("Example", "[tag][tag2][tag3]")
{
  SECTION("First Basic test") {
    REQUIRE(true);
  }

  SECTION("Second Basic test") {
    REQUIRE(true);
  }

  SECTION("Third Basic test") {
    REQUIRE(true);
  }
}

SCENARIO("Adding and removing children on a root node", "[tag]") {
    GIVEN("A node named root") {
        auto root = SceneNode("root");

        THEN("its name should be root") {
            REQUIRE(root.getName().compare("root") == 0);
        }

        WHEN("the refcount is increased") {
            root.retain();
            THEN("the root refcount should be 1") {
                REQUIRE(root.getRefCount() == 1);
            }
        }

        WHEN("the refcount is decreased without increasing first") {
            root.release();
            THEN("the node should assert") {
                //REQUIRE()
            }
        }

        THEN("there should be no references") {
            REQUIRE(root.getRefCount() == 0);
        }

        WHEN("with a child name child") {
            auto child = std::make_shared<SceneNode>("child");
            root.addDependency(child);

            THEN("the child should have a refcount of 1") {
                REQUIRE(child->getRefCount() == 1);
            }
        }
    }
}