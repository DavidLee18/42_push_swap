cmake_minimum_required(VERSION 3.13)
project(push_swap)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "-Wall -Wextra -Werror -g")
add_subdirectory(ft_printf)
set(SOURCE_FILES
		src/etc.c
		src/etc2.c
		src/gc.c
		src/gc2.c
		src/main.c
		src/sort.c
		src/sort2.c
		src/sort3.c
		src/sort4.c
		src/stack.c
		src/stack2.c
		src/stack3.c
		src/gc3.c
		src/sort5.c
)
set(BONUS_SRC
		src/etc.c
		src/gc.c
		src/gc2.c
		src/gc3.c
		src/stack.c
		src/stack2.c
		src/stack3.c
		src/main_bonus.c
		src/exec_bonus.c
		src/exec2_bonus.c
)
add_executable(push_swap ${SOURCE_FILES})
target_link_libraries(push_swap ft_printf)
add_executable(checker ${BONUS_SRC})
target_link_libraries(checker ft_printf)