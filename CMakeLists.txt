cmake_minimum_required(VERSION 3.16)

project(obserbot_gui VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        motor_tab.cpp
        motor_tab.h
        sensor_tab.cpp
        sensor_tab.h
        dashboard/dashboard_tab.cpp
        dashboard/dashboard_tab.h
        dashboard/camera_widget.cpp
        dashboard/camera_widget.h
        dashboard/scenario_widget.cpp
        dashboard/scenario_widget.h
        dashboard/motor_widget.cpp
        dashboard/motor_widget.h
        dashboard/motor_status_box.cpp
        dashboard/motor_status_box.h
        dashboard/control_widget.cpp
        dashboard/control_widget.h
)

# 먼저 실행 파일 타겟 생성
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(obserbot_gui
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(obserbot_gui SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(obserbot_gui
            ${PROJECT_SOURCES}
        )
    endif()
endif()

# config 폴더 복사 설정을 ALL_BUILD 타겟에 연결
add_custom_target(copy_config ALL
    COMMAND ${CMAKE_COMMAND} -E make_directory
        $<TARGET_FILE_DIR:obserbot_gui>/config
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/config
        $<TARGET_FILE_DIR:obserbot_gui>/config
    COMMENT "Copying config directory to output directory"
)

# config 폴더 복사가 obserbot_gui 타겟 이후에 실행되도록 의존성 추가
add_dependencies(copy_config obserbot_gui)

target_link_libraries(obserbot_gui PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.obserbot_gui)
endif()

set_target_properties(obserbot_gui PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS obserbot_gui
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(obserbot_gui)
endif()
