cmake_minimum_required(VERSION 3.18)

include(FetchContent)

FetchContent_Declare(
  catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  #v2.13.5
  GIT_TAG        42e368dd0aedc122798008d8c4f583fea3296a97
)

#FetchContent_Declare(
#  cereal
#  GIT_REPOSITORY https://github.com/USCiLab/cereal.git
#  GIT_TAG        02eace19a99ce3cd564ca4e379753d69af08c2c8
#)

#FetchContent_Declare(
#  doxygen
#  GIT_REPOSITORY https://github.com/doxygen/doxygen.git
#  GIT_TAG        ef9b20ac7f8a8621fcfc299f8bd0b80422390f4b
#)

FetchContent_Declare(
  entt
  GIT_REPOSITORY https://github.com/skypjack/entt.git
  #v3.7.0
  GIT_TAG        1e07b981f0b305400f854084c61c4efe2fd36206
)

#FetchContent_Declare(
#  rttr
#  GIT_REPOSITORY https://github.com/rttrorg/rttr.git
#  GIT_TAG        e338d9aa47f6c7da97be88df3aaa48ac9c5fe6c6
#)

FetchContent_MakeAvailable(
	catch2
#	cereal
#	doxygen
	entt
#	rttr
	)
