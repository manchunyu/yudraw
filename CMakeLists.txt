cmake_minimum_required(VERSION 3.31)
project(test_raylib C)

set(CMAKE_C_STANDARD 99)

include(FetchContent)

function(include_dependency libName gitURL gitTag)
    FetchContent_Declare(${libName}
            GIT_REPOSITORY ${gitURL}
                GIT_TAG    ${gitTag}
                GIT_SHALLOW TRUE
                GIT_PROGRESS TRUE
    )
   FetchContent_MakeAvailable(${libName})
endfunction()

set(LIB1 raylib)
find_package(${LIB1} QUIET)
if (NOT ${LIB1}_FOUND)
    include_dependency(${LIB1} https://github.com/raysan5/raylib.git 5.0)
endif ()

add_executable(test_raylib main.c
        utils.c)

target_include_directories(test_raylib PRIVATE ${raylib_INCLUDE_DIRS})

target_link_libraries(test_raylib PRIVATE ${LIB1})
