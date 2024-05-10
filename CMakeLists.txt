cmake_minimum_required(VERSION 3.5)

project(springHomework VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets Multimedia MultimediaWidgets REQUIRED)
# include_directories(/usr/local/opt/qt@6/include/QtMultimediaWidgets)
# include_directories(${QT_INCLUDE_DIR})

include_directories(${Qt6MultimediaWidgets_INCLUDE_DIRS})

find_package(Qt6 COMPONENTS Gui Core Sql REQUIRED)
find_package(Qt6 COMPONENTS Sql REQUIRED)
find_package(Qt6 COMPONENTS Multimedia REQUIRED)

set(PROJECT_SOURCES
        main.cpp
        geometrygame.cpp
        geometrygame.h
        geometrygame.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(springHomework
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        login.h login.cpp login.ui
        signup.h signup.cpp signup.ui
        animation_level.h animation_level.cpp animation_level.ui
        game01.h game01.cpp game01.ui
        mainpage.h mainpage.cpp mainpage.ui
        image.qrc
        square.h square.cpp
        audio.qrc
        game02.h game02.cpp game02.ui
        game03.h game03.cpp game03.ui

    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET springHomework APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(springHomework SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(springHomework
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(springHomework PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(springHomework INTERFACE Qt6::Multimedia )
target_link_libraries(springHomework ${Widgets} ${Multimedia} ${MultimediaWidgets})
target_link_libraries(springHomework INTERFACE Qt::Sql Qt6::Gui Qt::Core)
target_link_libraries(springHomework INTERFACE Qt6::Sql )

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.springHomework)
endif()
set_target_properties(springHomework PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS springHomework
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(springHomework)
endif()
