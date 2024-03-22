cmake_minimum_required(VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if(POLICY CMP0141)
    cmake_policy(SET CMP0141 NEW)
    set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project("fib")

# Add source to this project's executable.
file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*.h" "include/*.h")

add_executable(${PROJECT_NAME} ${SOURCES})

if(CMAKE_VERSION VERSION_GREATER 3.12)
    set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)
endif()

# Include libraries
target_link_libraries(${PROJECT_NAME} PRIVATE fmt::fmt)

file(GLOB PACKAGE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/node_modules/*")

foreach(PACKAGE_DIR ${PACKAGE_DIRS})
    if(IS_DIRECTORY ${PACKAGE_DIR})
        file(GLOB CMAKE_FILES "${PACKAGE_DIR}/CMakeLists.txt")
        if(CMAKE_FILES)
            message(STATUS "Adding package in ${PACKAGE_DIR}")
            add_subdirectory(${PACKAGE_DIR})
        endif()
    endif()
endforeach()

# Add node_modules directory to the include path
set(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} "${CMAKE_SOURCE_DIR}/node_modules")

# TODO: Add tests and install targets if needed.