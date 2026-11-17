NAME	:= push_swap

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror
INCLUDES	:= -Iinclude -Ilibft

LIBFT		:= libft/libft.a

SRC_DIR		:= src
TEST_DIR	:= tests

SRCS		:=	$(SRC_DIR)/main.c						\
				$(SRC_DIR)/parser/parser.c				\
				$(SRC_DIR)/errors/error_handler.c		\
				$(SRC_DIR)/utils/utils.c				\
				$(SRC_DIR)/utils/stack_utils.c			\
				$(SRC_DIR)/utils/bench.c				\
				$(SRC_DIR)/sorting/simple_sort.c		\
				$(SRC_DIR)/sorting/medium_sort.c		\
				$(SRC_DIR)/sorting/complex_sort.c		\
				$(SRC_DIR)/operations/push.c			\
				$(SRC_DIR)/operations/reverse_rotate.c	\
				$(SRC_DIR)/operations/rotate.c			\
				$(SRC_DIR)/operations/swap.c

OBJS		:= $(SRCS:.c=.o)

TESTS		:= test_parser test_utils test_bench test_stack

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C libft

%.o : %.c include/push_swap.h libft/libft.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean :
	rm -f $(OBJS)
	make -C libft clean

fclean : clean
	rm -f $(NAME)
	rm -f parser_tester utils_tester bench_tester stack_tester
	make -C libft fclean

re: fclean all

bonus: all
	# rule for executing bonus files

.PHONY: all clean fclean re bonus test

#	================
#	Tester execution
#	================

parser_tester: $(TEST_DIR)/parser_tester.c $(SRC_DIR)/parser/parser.c $(SRC_DIR)/utils/utils.c $(SRC_DIR)/utils/clean.c $(SRC_DIR)/errors/error_handler.c $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) $^ -o $@

utils_tester: $(TEST_DIR)/utils_tester.c $(SRC_DIR)/utils/utils.c $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) $^ -o $@

bench_tester: $(TEST_DIR)/bench_tester.c $(SRC_DIR)/utils/bench.c $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) $^ -o $@

stack_tester: $(TEST_DIR)/stack_tester.c $(SRC_DIR)/utils/stack.c $(SRC_DIR)/utils/utils.c $(SRC_DIR)/utils/clean.c $(SRC_DIR)/parser/parser.c $(SRC_DIR)/errors/error_handler.c $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) $^ -o $@

test_parser: parser_tester
	./parser_tester

test_utils: utils_tester
	./utils_tester

test_bench: bench_tester
	./bench_tester

test_stack: stack_tester
	./stack_tester

test: $(TESTS)