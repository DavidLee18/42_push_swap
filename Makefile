CC := cc

CFLAGS := -Wall -Wextra -Werror -foptimize-sibling-calls -O2 -g

BFLAGS := -Lft_printf -lftprintf

NAME := push_swap

SRCS := src/etc.c src/gc.c src/gc2.c src/heap.c src/heap2.c \
	src/heap3.c src/main.c src/sort.c src/stack.c \
	src/stack2.c

OBJS := $(patsubst src/%.c,build/%.o,$(SRCS))

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
	make fclean -C ft_printf


re: fclean all


.PHONY: all clean fclean re
