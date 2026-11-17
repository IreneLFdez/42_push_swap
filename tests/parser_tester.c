#include "../include/push_swap.h"
#include <stdio.h>
#include <stdlib.h>

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
/*                TEST: is_flag              */
/* ========================================= */

void	test_is_flag(void)
{
	printf("\n========== TEST: is_flag ==========\n");

	CHECK(is_flag("--adaptive") == 0,
	"Recognize --adaptive");

	CHECK(is_flag("--simple") == 1,
		"Recognize --simple");

	CHECK(is_flag("--medium") == 2,
		"Recognize --medium");

	CHECK(is_flag("--complex") == 3,
		"Recognize --complex");

	CHECK(is_flag("--bench") == 4,
		"Recognize --bench");

	CHECK(is_flag("123") == 5,
		"Recognize positive integer");

	CHECK(is_flag("0") == 5,
		"Recognize zero");

	CHECK(is_flag("-123") == -1,
		"Reject negative number");

	CHECK(is_flag("+123") == -1,
		"Reject explicitly positive number");

	CHECK(is_flag("--unknown") == -1,
		"Reject unknown flag");

	CHECK(is_flag("bench") == -1,
		"Reject flag without dashes");

	CHECK(is_flag(NULL) == -1,
		"Handle NULL input");

	/* Prefix matching checks */

	CHECK(is_flag("--adaptive123") == -1,
		"Check adaptive flag with additional characters");

	CHECK(is_flag("--simple123") == -1,
		"Check simple flag with additional characters");

	CHECK(is_flag("--bench123") == -1,
		"Check bench flag with additional characters");

}

/* ========================================= */
/*              TEST: parse_flags            */
/* ========================================= */

void	test_parse_flags(void)
{
	t_options	options;
	int			result;

	printf("\n========== TEST: parse_flags ==========\n");

	/* BENCH + ADAPTIVE */

	{
		char	*argv[] = {
			"./push_swap",
			"--bench",
			"--adaptive",
			"1",
			"2",
			NULL
		};

		result = parse_flags(argv, &options);

		CHECK(result == 3,
			"Parse --bench --adaptive");

		CHECK(options.bench == 1,
			"Enable benchmark");

		CHECK(options.strategy == STRATEGY_ADAPTIVE,
			"Select adaptive strategy");
	}

	/* SIMPLE STRATEGY */

	{
		char	*argv[] = {
			"./push_swap",
			"--simple",
			"10",
			"20",
			NULL
		};

		result = parse_flags(argv, &options);

		CHECK(result == 2,
			"Parse --simple");

		CHECK(options.bench == 0,
			"Benchmark disabled by default");

		CHECK(options.strategy == STRATEGY_SIMPLE,
			"Select simple strategy");
	}

	/* MEDIUM STRATEGY */

	{
		char	*argv[] = {
			"./push_swap",
			"--medium",
			"10",
			NULL
		};

		result = parse_flags(argv, &options);

		CHECK(result == 2,
			"Parse --medium");

		CHECK(options.strategy == STRATEGY_MEDIUM,
			"Select medium strategy");
	}

	/* COMPLEX STRATEGY */

	{
		char	*argv[] = {
			"./push_swap",
			"--complex",
			"10",
			NULL
		};

		result = parse_flags(argv, &options);

		CHECK(result == 2,
			"Parse --complex");

		CHECK(options.strategy == STRATEGY_COMPLEX,
			"Select complex strategy");
	}

	/* NO FLAGS */

	{
		char	*argv[] = {
			"./push_swap",
			"10",
			"20",
			"30",
			NULL
		};

		result = parse_flags(argv, &options);

		CHECK(result == 1,
			"Parse arguments without flags");

		CHECK(options.bench == 0,
			"Benchmark disabled without flags");

		CHECK(options.strategy == STRATEGY_ADAPTIVE,
			"Adaptive strategy selected by default");
	}

	/* ONLY BENCH */

	{
		char	*argv[] = {
			"./push_swap",
			"--bench",
			"10",
			"20",
			NULL
		};

		result = parse_flags(argv, &options);

		CHECK(result == 2,
			"Parse --bench without strategy");

		CHECK(options.bench == 1,
			"Enable benchmark without strategy");

		CHECK(options.strategy == STRATEGY_ADAPTIVE,
			"Keep adaptive strategy by default");
	}

	/* INVALID FLAG */

	{
		char	*argv[] = {
			"./push_swap",
			"--unknown",
			"10",
			NULL
		};

		result = parse_flags(argv, &options);

		CHECK(result == ERR_INVALID_INPUT,
			"Reject unknown flag");
	}

	/* NEGATIVE NUMBER */

	{
		char	*argv[] = {
			"./push_swap",
			"-10",
			"20",
			NULL
		};

		result = parse_flags(argv, &options);

		CHECK(result == ERR_INVALID_INPUT,
			"Reject negative number as first argument");
	}

	/* BENCH + SIMPLE */

	{
		char	*argv[] = {
			"./push_swap",
			"--bench",
			"--simple",
			"10",
			NULL
		};

		result = parse_flags(argv, &options);

		CHECK(result == 3,
			"Parse --bench followed by --simple");

		CHECK(options.bench == 1,
			"Keep benchmark enabled");

		CHECK(options.strategy == STRATEGY_SIMPLE,
			"Select simple strategy after benchmark");
	}

	/* MULTIPLE STRATEGIES */

	{
		char	*argv[] = {
			"./push_swap",
			"--simple",
			"--medium",
			"10",
			NULL
		};

		result = parse_flags(argv, &options);

		CHECK(result == 3,
			"Accept multiple strategy flags");

		CHECK(options.strategy == STRATEGY_MEDIUM,
			"Last strategy flag takes precedence");
	}

	/* REPEATED BENCH */

	{
		char	*argv[] = {
			"./push_swap",
			"--bench",
			"--bench",
			"10",
			NULL
		};

		result = parse_flags(argv, &options);

		CHECK(result == ERR_INVALID_INPUT,
			"Reject repeated --bench");
	}

	/* STRATEGY + BENCH */

	{
		char	*argv[] = {
			"./push_swap",
			"--simple",
			"--bench",
			"10",
			NULL
		};

		result = parse_flags(argv, &options);

		CHECK(result == 3,
			"Accept --bench after strategy");

		CHECK(options.bench == 1,
			"Enable benchmark after strategy");
	}

	/* THIRD FLAG POSITION */

	{
		char	*argv[] = {
			"./push_swap",
			"--bench",
			"--simple",
			"--medium",
			"10",
			NULL
		};

		result = parse_flags(argv, &options);

		CHECK(result == 3,
			"Stop parsing flags after two arguments");

		CHECK(options.strategy == STRATEGY_SIMPLE,
			"Keep strategy selected before parsing limit");
	}
}

/* ========================================= */
/*             TEST: parse_numbers           */
/* ========================================= */

void	test_parse_numbers(void)
{
	t_error	err;
	int		*nums;

	printf("\n========== TEST: parse_numbers ==========\n");

	/* SINGLE ARGUMENT */

	{
		int		size = 0;
		char	*argv[] = {
			"./push_swap",
			"7 10 8 9",
			NULL
		};

		err = SUCCESS;
		nums = parse_numbers(argv, 1, &err, &size);

		CHECK(nums != NULL,
			"Allocate array from single argument");

		if (nums)
		{
			CHECK(nums[0] == 7 && nums[1] == 10
				&& nums[2] == 8 && nums[3] == 9,
				"Parse multiple numbers in one argument");
			free(nums);
		}
	}

	/* MULTIPLE ARGUMENTS */

	{
		int		size = 0;
		char	*argv[] = {
			"./push_swap",
			"7 10",
			"8 9",
			"20 30",
			NULL
		};

		err = SUCCESS;
		nums = parse_numbers(argv, 1, &err, &size);

		CHECK(nums != NULL,
			"Allocate array from multiple arguments");

		if (nums)
		{
			CHECK(nums[0] == 7 && nums[1] == 10
				&& nums[2] == 8 && nums[3] == 9
				&& nums[4] == 20 && nums[5] == 30,
				"Preserve argument order");
			free(nums);
		}
	}

	/* NEGATIVE NUMBERS */

	{
		int		size = 0;
		char	*argv[] = {
			"./push_swap",
			"-5 -10 0 15",
			NULL
		};

		err = SUCCESS;
		nums = parse_numbers(argv, 1, &err, &size);

		CHECK(nums != NULL,
			"Allocate array containing negative numbers");

		if (nums)
		{
			CHECK(nums[0] == -5 && nums[1] == -10
				&& nums[2] == 0 && nums[3] == 15,
				"Parse negative numbers and zero");
			free(nums);
		}
	}

	/* WHITESPACE */

	{
		int		size = 0;
		char	*argv[] = {
			"./push_swap",
			"   10   20   30   ",
			NULL
		};

		err = SUCCESS;
		nums = parse_numbers(argv, 1, &err, &size);

		CHECK(nums != NULL,
			"Allocate array with extra whitespace");

		if (nums)
		{
			CHECK(nums[0] == 10 && nums[1] == 20
				&& nums[2] == 30,
				"Parse numbers with extra whitespace");
			free(nums);
		}
	}

	/* SKIP FLAGS */

	{
		int		size = 0;
		char	*argv[] = {
			"./push_swap",
			"--simple",
			"10 20 30",
			NULL
		};

		err = SUCCESS;
		nums = parse_numbers(argv, 2, &err, &size);

		CHECK(nums != NULL,
			"Parse numbers starting after flags");

		if (nums)
		{
			CHECK(nums[0] == 10 && nums[1] == 20
				&& nums[2] == 30,
				"Correctly skip flag arguments");
			free(nums);
		}
	}
}

/* ========================================= */
/*                    MAIN                   */
/* ========================================= */

int	main(void)
{
	printf("\n====================================\n");
	printf("          PARSER TEST SUITE\n");
	printf("====================================\n");

	test_is_flag();
	test_parse_flags();
	test_parse_numbers();

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