NAME	:= push_swap

CC		:= cc
CFLAGS	:= -Wall -Wextra -Werror
AR		:= ar
ARFLAGS	:= rcs

LIBFT	:= libft/libft.a

SRCS	:=	main.c									\
			parser/parser.c							\
			errors/error_handler.c					\
			utils/utils.c							\
			sort_strategies/simple_sort.c			\
			operations/push.c						\
			operations/reverse_rotate.c				\
			operations/rotate.c						\
			operations/swap.c

OBJS	:= $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS) -o $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(LIBFT)

$(LIBFT):
	make -C libft

%.o : %.c push_swap.h
	$(CC) $(CFLAGS) -I. -c $< -o $@

clean :
	rm -f $(OBJS)
	make -C libft clean

fclean : clean
	rm -f $(NAME) parser_tester utils_tester bench_tester
	make -C libft fclean

re: fclean all

bonus: all
	# rule for executing bonus files

### Tester execution ###

parser_tester: tester/parser_tester.c parser/parser.c utils/utils.c $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) tester/parser_tester.c parser/parser.c utils/utils.c $(LIBFT) -o parser_tester

utils_tester: tester/utils_tester.c utils/utils.c $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) tester/utils_tester.c utils/utils.c $(LIBFT) -o utils_tester

bench_tester: tester/bench_tester.c print/bench.c $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) tester/bench_tester.c print/bench.c $(LIBFT) -o bench_tester


test_parser: parser_tester
	./parser_tester

test_utils: utils_tester
	./utils_tester

test_bench: bench_tester
	./bench_tester

test: test_parser test_utils test_bench



.PHONY: all clean fclean re bonus test