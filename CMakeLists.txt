cmake_minimum_required(VERSION 3.13)
project(push_swap)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "-Wall -Wextra -Werror -foptimize-sibling-calls -O2 -g")
add_subdirectory(ft_printf)
set(SOURCE_FILES
		src/etc.c
		src/gc.c
		src/gc2.c
		src/heap.c
		src/heap2.c
		src/heap3.c
		src/heap4.c
		src/main.c
		src/sort.c
		src/stack.c
		src/stack2.c
)
add_executable(push_swap ${SOURCE_FILES})
target_link_libraries(push_swap ft_printf)