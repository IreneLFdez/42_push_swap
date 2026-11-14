#include "../push_swap.h"
#include <assert.h>
#include <stdio.h>

/* ========================================= */
/*              TEST UTILITIES               */
/* ========================================= */

int	g_tests = 0;
int	g_failures = 0;

#define CHECK(condition, description) \
	do \
	{ \
		g_tests++; \
		if (condition) \
			printf("[PASS] %s\n", description); \
		else \
		{ \
			printf("[FAIL] %s (line %d)\n", description, __LINE__); \
			g_failures++; \
		} \
	} while (0)

/* ========================================= */
/*             TEST: total_moves             */
/* ========================================= */

void	test_total_moves(void)
{
	t_moves	moves;

	printf("\n========== TEST: total_moves ==========\n");

	/* NO MOVES */

	moves = (t_moves){0};

	CHECK(total_moves(moves) == 0,
		"Return 0 when no operations were performed");

	/* ONE OPERATION OF EACH TYPE */

	moves.sa = 1;
	moves.sb = 1;
	moves.ss = 1;
	moves.pa = 1;
	moves.pb = 1;
	moves.ra = 1;
	moves.rb = 1;
	moves.rr = 1;
	moves.rra = 1;
	moves.rrb = 1;
	moves.rrr = 1;

	CHECK(total_moves(moves) == 11,
		"Count all 11 operation types");

	/* MULTIPLE OPERATIONS */

	moves = (t_moves){0};

	moves.sa = 3;
	moves.pb = 5;
	moves.ra = 10;
	moves.rra = 2;

	CHECK(total_moves(moves) == 20,
		"Sum multiple operations correctly");

	/* ONLY PUSH OPERATIONS */

	moves = (t_moves){0};

	moves.pa = 15;
	moves.pb = 25;

	CHECK(total_moves(moves) == 40,
		"Count push operations");

	/* ONLY ROTATIONS */

	moves = (t_moves){0};

	moves.ra = 10;
	moves.rb = 20;
	moves.rr = 30;
	moves.rra = 40;
	moves.rrb = 50;
	moves.rrr = 60;

	CHECK(total_moves(moves) == 210,
		"Count all rotation operations");
}

/* ========================================= */
/*           TEST: print_strategy            */
/* ========================================= */

void	test_print_strategy(void)
{
	t_options	options;

	printf("\n========== TEST: print_strategy ==========\n");

	options.bench = 0;

	options.strategy = STRATEGY_ADAPTIVE;
	CHECK(ft_strncmp(print_strategy(options), "Adaptive", 9) == 0,
		"Return Adaptive strategy");

	options.strategy = STRATEGY_SIMPLE;
	CHECK(ft_strncmp(print_strategy(options), "Simple", 7) == 0,
		"Return Simple strategy");

	options.strategy = STRATEGY_MEDIUM;
	CHECK(ft_strncmp(print_strategy(options), "Medium", 7) == 0,
		"Return Medium strategy");

	options.strategy = STRATEGY_COMPLEX;
	CHECK(ft_strncmp(print_strategy(options), "Complex", 8) == 0,
		"Return Complex strategy");

	options.strategy = (t_strategy)-1;
	CHECK(ft_strncmp(print_strategy(options), "Error.", 7) == 0,
		"Handle invalid strategy");
}

/* ========================================= */
/*          TEST: print_adaptive             */
/* ========================================= */

void	test_print_adaptive(void)
{
	printf("\n========== TEST: print_adaptive ==========\n");

	CHECK(ft_strncmp(print_adaptive(0.0), "O(n2)", 6) == 0,
		"0% disorder selects O(n2)");

	CHECK(ft_strncmp(print_adaptive(10.0), "O(n2)", 6) == 0,
		"10% disorder selects O(n2)");

	CHECK(ft_strncmp(print_adaptive(19.99), "O(n2)", 6) == 0,
		"19.99% disorder selects O(n2)");

	CHECK(ft_strncmp(print_adaptive(20.0), "O(n√n)", 8) == 0,
		"20% disorder selects O(n√n)");

	CHECK(ft_strncmp(print_adaptive(35.0), "O(n√n)", 8) == 0,
		"35% disorder selects O(n√n)");

	CHECK(ft_strncmp(print_adaptive(49.99), "O(n√n)", 8) == 0,
		"49.99% disorder selects O(n√n)");

	CHECK(ft_strncmp(print_adaptive(50.0), "O(n log n)", 11) == 0,
		"50% disorder selects O(n log n)");

	CHECK(ft_strncmp(print_adaptive(75.0), "O(n log n)", 11) == 0,
		"75% disorder selects O(n log n)");

	CHECK(ft_strncmp(print_adaptive(100.0), "O(n log n)", 11) == 0,
		"100% disorder selects O(n log n)");

	CHECK(ft_strncmp(print_adaptive(-1.0), "Error.", 7) == 0,
		"Negative disorder returns Error");
}

/* ========================================= */
/*          TEST: print_complexity            */
/* ========================================= */

void	test_print_complexity(void)
{
	t_options	options;

	printf("\n========== TEST: print_complexity ==========\n");

	options.bench = 0;

	/* ADAPTIVE */

	options.strategy = STRATEGY_ADAPTIVE;

	CHECK(ft_strncmp(print_complexity(options, 10.0), "O(n2)", 6) == 0,
		"Adaptive complexity with low disorder");

	CHECK(ft_strncmp(print_complexity(options, 35.0), "O(n√n)", 8) == 0,
		"Adaptive complexity with medium disorder");

	CHECK(ft_strncmp(print_complexity(options, 80.0), "O(n log n)", 11) == 0,
		"Adaptive complexity with high disorder");

	/* SIMPLE */

	options.strategy = STRATEGY_SIMPLE;

	CHECK(ft_strncmp(print_complexity(options, 80.0), "O(n2)", 6) == 0,
		"Simple strategy returns O(n2)");

	/* MEDIUM */

	options.strategy = STRATEGY_MEDIUM;

	CHECK(ft_strncmp(print_complexity(options, 80.0), "O(n√n)", 8) == 0,
		"Medium strategy returns O(n√n)");

	/* COMPLEX */

	options.strategy = STRATEGY_COMPLEX;

	CHECK(ft_strncmp(print_complexity(options, 10.0), "O(n log n)", 11) == 0,
		"Complex strategy returns O(n log n)");

	/* INVALID */

	options.strategy = (t_strategy)-1;

	CHECK(ft_strncmp(print_complexity(options, 50.0), "Error.", 7) == 0,
		"Invalid strategy returns Error");
}

/* ========================================= */
/*             TEST: print_bench              */
/* ========================================= */

void	test_print_bench(void)
{
	t_options	options;
	t_moves		moves;

	printf("\n========== TEST: print_bench ==========\n");

	options.bench = 1;
	options.strategy = STRATEGY_ADAPTIVE;

	moves = (t_moves){0};

	moves.sa = 2;
	moves.sb = 1;
	moves.ss = 1;
	moves.pa = 5;
	moves.pb = 5;
	moves.ra = 3;
	moves.rb = 2;
	moves.rr = 1;
	moves.rra = 4;
	moves.rrb = 2;
	moves.rrr = 1;

	printf("\n--- BENCHMARK OUTPUT TEST ---\n");

	print_bench(35.0, options, moves);

	printf("\nExpected values:\n");
	printf("Disorder: 35.000000%%\n");
	printf("Strategy: Adaptive / O(n√n)\n");
	printf("Total operations: 27\n");

	CHECK(total_moves(moves) == 27,
		"Benchmark receives correct total operation count");

	CHECK(ft_strncmp(print_strategy(options), "Adaptive", 9) == 0,
		"Benchmark receives correct strategy");

	CHECK(ft_strncmp(print_complexity(options, 35.0), "O(n√n)", 8) == 0,
		"Benchmark receives correct complexity");

	/* TEST DIFFERENT STRATEGY */

	options.strategy = STRATEGY_SIMPLE;

	printf("\n--- SIMPLE STRATEGY BENCHMARK ---\n");

	print_bench(10.0, options, moves);

	CHECK(ft_strncmp(print_strategy(options), "Simple", 7) == 0,
		"Print benchmark with Simple strategy");
}

/* ========================================= */
/*                    MAIN                   */
/* ========================================= */

int	main(void)
{
	printf("\n====================================\n");
	printf("         BENCHMARK TEST SUITE\n");
	printf("====================================\n");

	test_total_moves();
	test_print_strategy();
	test_print_adaptive();
	test_print_complexity();
	test_print_bench();

	printf("\n====================================\n");
	printf("              TEST RESULTS\n");
	printf("====================================\n");

	printf("Total tests: %d\n", g_tests);
	printf("Passed:      %d\n", g_tests - g_failures);
	printf("Failed:      %d\n", g_failures);

	if (g_failures == 0)
		printf("\nALL TESTS PASSED!\n");
	else
		printf("\nSOME TESTS FAILED!\n");

	printf("====================================\n");

	return (g_failures != 0);
}
