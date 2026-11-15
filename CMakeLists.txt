cmake_minimum_required(VERSION 3.10)
project(SchemaQL_MV VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include ../DeSiGNAR/include)

add_executable(SchemaQL 
    src/main.cpp 
    src/lexer/lexer.cpp 
    src/parser/parser.cpp 
    src/semantic/semantic.cpp 
    src/codegen/codegen.cpp
)

target_link_libraries(SchemaQL PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../DeSiGNAR/build/libDesignar.a)
