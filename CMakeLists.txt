cmake_minimum_required(VERSION 3.1)

project(cpp_indie_studio)

set(
  SRCS
  "srcs/main.cpp"
  "srcs/Core.cpp"
  "srcs/State.cpp"
  "srcs/MainMenu.cpp"
  "srcs/GUI.cpp"
  "srcs/Game.cpp"
  "srcs/Player.cpp"
  "srcs/Map.cpp"
  "srcs/Entity.cpp"
  "srcs/Wall.cpp"
  "srcs/PowerUp.cpp"
  "srcs/Bomb.cpp"
  "srcs/Display.cpp"
  "srcs/EventReceiver.cpp"
)

include_directories(
  "incs"
  "/usr/include/irrlicht/"
)

add_executable(
  bomberman
  ${SRCS}
)

set(IRRLICHT "Irrlicht")

target_link_libraries(
  bomberman
  ${IRRLICHT}
)
