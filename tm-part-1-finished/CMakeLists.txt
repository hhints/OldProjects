cmake_minimum_required(VERSION 3.24)
project(gdrive)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(gdrive
        Actor.cpp
        Actor.h
        freeglut.h
        freeglut_ext.h
        freeglut_std.h
        GameConstants.h
        GameController.cpp
        GameController.h
        GameWorld.cpp
        GameWorld.h
        GraphObject.h
        main.cpp
        SoundFX.h
        SpriteManager.h
        StudentWorld.cpp
        StudentWorld.h)
