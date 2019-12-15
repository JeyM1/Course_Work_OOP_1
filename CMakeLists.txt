cmake_minimum_required(VERSION 3.15)
project(Course_Work_OOP_1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -gdwarf-3")

add_executable(Course_Work_OOP_1 main.cpp
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
        FileHandler/TypesHandler.cpp FileHandler/TypesHandler.h
        Exception.h
        )