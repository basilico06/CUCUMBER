cmake_minimum_required(VERSION 3.29)
project(starfish_programming_language)

set(CMAKE_CXX_STANDARD 23)

add_executable(starfish_programming_language main.cpp
        src/lexer/lexer_util.hpp
        src/syntax_analyzer/syntax_analyzer.cpp
        src/parser/parser.cpp
        src/syntax_analyzer/entity.hpp
        src/codegen/codegen.cpp
        src/codegen/codegen.cpp
        src/codegen/codegen.cpp
        src/file_writer.hpp
        src/file_writer.hpp
        src/init/init.cpp
)
