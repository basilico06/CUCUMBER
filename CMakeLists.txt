cmake_minimum_required(VERSION 3.29)
project(starfish_programming_language)

set(CMAKE_CXX_STANDARD 23)

add_executable(starfish_programming_language main.cpp
        src/lexer/lexer_util.hpp
        src/syntax_analyzer/syntax_analyzer.hpp
        src/parser/parser.cpp
        src/symble_table/symble_table_row/symble_table_row.hpp)
