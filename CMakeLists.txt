cmake_minimum_required(VERSION 4.2.3)
project(heart)

find_package(SDL3 REQUIRED)

add_executable(heart)

target_sources(heart
  PRIVATE
    src/main.c
    src/ast.c
    src/cli_options.c
    src/graphics.c
    src/utils.c
)

target_link_libraries(heart
  PRIVATE
  ${SDL3_LIBRARIES}
)

target_include_directories(heart
  PRIVATE
#  ${SDL3_INCLUDE_DIRS}
    include/
)


target_compile_options(heart
  PRIVATE
  -Wall -Wextra -Werror -g3 -O0)

