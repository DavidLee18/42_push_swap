CC := cc

CFLAGS := -Wall -Wextra -Werror -g

BFLAGS := -Lft_printf -lftprintf

NAME := push_swap

BONUS_NAME := checker

SRCS := src/main.c src/sort.c \
	src/sort2.c src/etc2.c \
	src/sort3.c src/sort4.c src/sort5.c src/sort6.c \
	src/sort7.c src/sort8.c src/sort9.c

COMMON_SRCS := src/etc.c src/stack3.c src/gc2.c

BONUS_SRCS := src/main_bonus.c src/exec_bonus.c \
	src/exec2_bonus.c

OBJS := $(patsubst src/%.c,build/%.o,$(SRCS))

COMMON_OBJS := $(patsubst src/%.c,build/%.o,$(COMMON_SRCS))

BONUS_OBJS := $(patsubst src/%.c,build/%.o,$(BONUS_SRCS))

all: $(NAME)


$(NAME): $(OBJS) $(COMMON_OBJS)
	make -C ft_printf
	$(CC) $(OBJS) $(COMMON_OBJS) $(BFLAGS) -o $(NAME)


$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -c $(patsubst build/%.o,src/%.c,$@)
	mkdir -p build
	mv $(patsubst build/%.o,%.o,$@) $@


$(COMMON_OBJS): $(COMMON_SRCS)
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


$(BONUS_NAME): $(BONUS_OBJS) $(COMMON_OBJS)
	make -C ft_printf
	$(CC) $(BONUS_OBJS) $(COMMON_OBJS) $(BFLAGS) -o $(BONUS_NAME)


$(BONUS_OBJS): $(BONUS_SRCS)
	$(CC) $(CFLAGS) -c $(patsubst build/%.o,src/%.c,$@)
	mkdir -p build
	mv $(patsubst build/%.o,%.o,$@) $@


re: fclean all


.PHONY: all clean fclean re
