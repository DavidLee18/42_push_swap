CC := cc

CFLAGS := -Wall -Wextra -Werror -g

BFLAGS := -Lft_printf -lftprintf

NAME := push_swap

BONUS_NAME := checker

SRCS := src/etc.c src/gc.c src/gc2.c src/gc3.c \
	src/main.c src/sort.c src/stack.c \
	src/stack2.c src/sort2.c src/stack3.c src/etc2.c \
	src/sort3.c src/sort4.c src/sort5.c src/sort6.c \
	src/sort7.c src/sort8.c src/sort9.c

BONUS_SRCS := src/etc.c src/gc.c src/gc2.c src/gc3.c \
	src/stack.c src/stack2.c src/stack3.c \
	src/main_bonus.c src/exec_bonus.c src/exec2_bonus.c

OBJS := $(patsubst src/%.c,build/%.o,$(SRCS))

BONUS_OBJS := $(patsubst src/%.c,build/%.o,$(BONUS_SRCS))

all: $(NAME)


$(NAME): $(OBJS)
	make -C ft_printf
	$(CC) $(OBJS) $(BFLAGS) -o $(NAME)


$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -c $(patsubst build/%.o,src/%.c,$@)
	mkdir -p build
	mv $(patsubst build/%.o,%.o,$@) $@


clean:
	rm -rf build/
	make clean -C ft_printf


fclean: clean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)
	make fclean -C ft_printf

bonus: $(BONUS_NAME)


$(BONUS_NAME): $(BONUS_OBJS)
	make -C ft_printf
	$(CC) $(BONUS_OBJS) $(BFLAGS) -o $(BONUS_NAME)


$(BONUS_OBJS): $(BONUS_SRCS)
	$(CC) $(CFLAGS) -c $(patsubst build/%.o,src/%.c,$@)
	mkdir -p build
	mv $(patsubst build/%.o,%.o,$@) $@


re: fclean all


.PHONY: all clean fclean re
