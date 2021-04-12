#include "SceneNode.hpp"

#include <catch2/catch.hpp>

using namespace llama;

TEST_CASE("It did it") {
	auto node = SceneNode("empty");
    CHECK(node.getName().compare("empty") == 0);
}