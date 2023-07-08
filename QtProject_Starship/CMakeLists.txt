cmake_minimum_required(VERSION 3.5)

project(star_ship VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

#find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets Multimedia REQUIRED)
#find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets Multimedia REQUIRED)

set(PROJECT_SOURCES
        main.cpp
        starship.cpp
        starship.h
        resources.qrc
        game_scene.h
        game_scene.cpp
        main_menu.h
        main_menu.cpp
        main_menu.ui
        clock_prompt.h
        clock_prompt.cpp
        myScene.h
        myScene.cpp
        credits.h
        credits.cpp
        credits.ui
        planet.h
        planet.cpp
        coin.h
        coin.cpp

        pageswitcher.h
        pageswitcher.cpp
    
        walkthrough_page1.h
        walkthrough_page1.cpp
        walkthrough_page1.ui
    
        walkthrough_page2.h
        walkthrough_page2.cpp
        walkthrough_page2.ui

        scorewindow.h
        scorewindow.cpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(star_ship
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET star_ship APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(star_ship SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(star_ship
            ${PROJECT_SOURCES}
        )
    endif()
endif()

find_package(Qt6 REQUIRED COMPONENTS Multimedia)
target_link_libraries(star_ship PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Multimedia)
#find_package(Qt6 REQUIRED COMPONENTS Multimedia)
#target_link_libraries(mytarget PRIVATE Qt6::Multimedia)



set_target_properties(star_ship PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS star_ship
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(star_ship)
endif()
