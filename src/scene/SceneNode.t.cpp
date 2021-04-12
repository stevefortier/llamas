#include "SceneNode.hpp"

#include <catch2/catch.hpp>

using namespace llama;

TEST_CASE("Single Node") {
    auto node = SceneNode("single");
    CHECK(node.getName().compare("single") == 0);
}
