cmake_minimum_required(VERSION 3.5)

project(Course_Work_OOP_1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fexceptions -static-libstdc++ -static-libgcc")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fexceptions")

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(Course_Work_OOP_1
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    Dialogs_AddFigures/dialog_addnewfigure.cpp
    Dialogs_AddFigures/dialog_addnewfigure.h
    Dialogs_AddFigures/dialog_addnewfigure.ui
    Dialogs_AddFigures/dialog_addnewcircle.cpp
    Dialogs_AddFigures/dialog_addnewcircle.h
    Dialogs_AddFigures/dialog_addnewcircle.ui
    Dialogs_AddFigures/dialog_addnewtriangle.cpp
    Dialogs_AddFigures/dialog_addnewtriangle.h
    Dialogs_AddFigures/dialog_addnewtriangle.ui
    Dialogs_AddFigures/dialog_addnewrectangle.cpp
    Dialogs_AddFigures/dialog_addnewrectangle.h
    Dialogs_AddFigures/dialog_addnewrectangle.ui
    Dialogs_AddFigures/dialog_addnewellipse.cpp
    Dialogs_AddFigures/dialog_addnewellipse.h
    Dialogs_AddFigures/dialog_addnewellipse.ui
    dialog_drawablewindow.cpp
    dialog_drawablewindow.h
    dialog_drawablewindow.ui
    dialog_editfigures.cpp
    dialog_editfigures.h
    dialog_editfigures.ui
    dialog_findfigure.cpp
    dialog_findfigure.h
    dialog_findfigure.ui
    Object.cpp Object.h
    Point.cpp Point.h
    Figure.cpp Figure.h
    FigureName.cpp FigureName.h
    Circle.cpp Circle.h
    Triangle.cpp Triangle.h
    Rectangle.cpp Rectangle.h
    Ellipse.cpp Ellipse.h
    ArrayOfObjectsOnScreen.cpp ArrayOfObjectsOnScreen.h
    SingleLinkedList/SL_List_Node.h SingleLinkedList/SL_List.h
    FileHandler/FileHandler.h
    Exception.h
    app_resources.qrc
    )


target_link_libraries(Course_Work_OOP_1 PRIVATE Qt5::Widgets)
