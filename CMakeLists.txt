cmake_minimum_required(VERSION 3.10)
project(MiniBrowser)

# Find required packages
find_package(CURL REQUIRED)
find_package(FLEX REQUIRED)
find_package(BISON REQUIRED)

# Generate parser files
BISON_TARGET(Parser src/parser/HTML2AST.y ${CMAKE_CURRENT_BINARY_DIR}/HTML2AST.tab.cpp)
FLEX_TARGET(Scanner src/parser/HTML2AST.l ${CMAKE_CURRENT_BINARY_DIR}/lex.yy.cpp)
ADD_FLEX_BISON_DEPENDENCY(Scanner Parser)

# Add executable
add_executable(minibrowser
    src/main.cpp
    src/network/NetworkManager.cpp
    ${BISON_Parser_OUTPUTS}
    ${FLEX_Scanner_OUTPUTS}
)

# Include directories
target_include_directories(minibrowser PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/src/parser   # Add this line to include the parser directory
    ${CMAKE_CURRENT_BINARY_DIR}
)

# Link libraries
target_link_libraries(minibrowser PRIVATE
    CURL::libcurl
)

# Enable C++17 for filesystem support
set_target_properties(minibrowser PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

