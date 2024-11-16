cmake_minimum_required(VERSION 3.1.0)

project(ASTRenderer VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Find the required packages
find_package(Qt5 COMPONENTS Widgets REQUIRED)

# Add the main executable (ASTRenderer)
add_executable(ASTRenderer main.cpp)
target_link_libraries(ASTRenderer PRIVATE Qt5::Widgets)

# Add Flex and Bison processing for HTML2AST
find_package(BISON REQUIRED)
find_package(FLEX REQUIRED)

# Process the Bison and Flex files to generate C++ files
BISON_TARGET(Parser HTML2AST.y ${CMAKE_CURRENT_BINARY_DIR}/HTML2AST.tab.cpp)
FLEX_TARGET(Scanner HTML2AST.l ${CMAKE_CURRENT_BINARY_DIR}/HTML2AST.lex.cpp)
ADD_FLEX_BISON_DEPENDENCY(Scanner Parser)

# Add the 'consumer' target
add_executable(consumer
    ${BISON_Parser_OUTPUTS}
    ${FLEX_Scanner_OUTPUTS}
    HTML2AST.h
)
target_include_directories(consumer PRIVATE ${CMAKE_CURRENT_BINARY_DIR})

# Add the 'producer' target
add_executable(producer NetworkManager.cpp NetworkManager.h)
target_link_libraries(producer PRIVATE curl)
