#include "../include/push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* ========================================= */
/*              TEST UTILITIES               */
/* ========================================= */

int	g_failures = 0;
int	g_tests = 0;

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
/*             TEST: count_numbers           */
/* ========================================= */

void	test_count_numbers(void)
{
	char	*argv1[] = {"./push_swap", "10 20 30", NULL};
	char	*argv2[] = {"./push_swap", "10", "20", "30", NULL};
	char	*argv3[] = {"./push_swap", "10 20", "30 40", NULL};
	char	*argv4[] = {"./push_swap", "   10   20  30   ", NULL};
	char	*argv5[] = {"./push_swap", "-10 +20 0", NULL};
	char	*argv6[] = {"./push_swap", NULL};

	printf("\n========== TEST: count_numbers ==========\n");

	CHECK(count_numbers(argv1, 1) == 3,
		"Count numbers in one argument");

	CHECK(count_numbers(argv2, 1) == 3,
		"Count numbers in separate arguments");

	CHECK(count_numbers(argv3, 1) == 4,
		"Count numbers across multiple arguments");

	CHECK(count_numbers(argv4, 1) == 3,
		"Handle multiple spaces");

	CHECK(count_numbers(argv5, 1) == 3,
		"Handle negative numbers, positive signs and zero");

	CHECK(count_numbers(argv6, 1) == 0,
		"Handle empty argument list");
}

/* ========================================= */
/*           TEST: compute_disorder          */
/* ========================================= */

void	test_compute_disorder(void)
{
	int		arr_sorted[] = {1, 2, 3, 4, 5};
	int		arr_reverse[] = {5, 4, 3, 2, 1};
	int		arr_random[] = {3, 1, 5, 2, 4};
	int		arr_two[] = {2, 1};
	int		arr_three[] = {3, 2, 1};
	float	result;

	printf("\n========== TEST: compute_disorder ==========\n");

	result = compute_disorder(arr_sorted, 5);
	CHECK(result == 0.0f,
		"Ordered array should have 0% disorder");

	result = compute_disorder(arr_reverse, 5);
	CHECK(result == 100.0f,
		"Reverse ordered array should have 100% disorder");

	result = compute_disorder(arr_random, 5);
	CHECK(fabsf(result - 40.0f) < 0.01f,
		"Random array should have 40% disorder");

	result = compute_disorder(arr_three, 3);
	CHECK(result == 100.0f,
		"Three reversed numbers should have 100% disorder");

	result = compute_disorder(arr_two, 2);
	CHECK(result == 100.0f,
		"Two reversed numbers should have 100% disorder");

	printf("\nDisorder values:\n");
	printf("Sorted array:   %.2f%%\n",
		compute_disorder(arr_sorted, 5));
	printf("Reverse array:  %.2f%%\n",
		compute_disorder(arr_reverse, 5));
	printf("Random array:   %.2f%%\n",
		compute_disorder(arr_random, 5));
	printf("Array of two:   %.2f%%\n",
		compute_disorder(arr_two, 2));
	printf("Array of three: %.2f%%\n",
		compute_disorder(arr_three, 3));
}

/* ========================================= */
/*           TEST: check_duplicates          */
/* ========================================= */

void	test_check_duplicates(void)
{
	int	nums_unique[] = {10, 20, 30, 40, 0};
	int	nums_duplicate[] = {10, 20, 30, 20, 0};
	int	nums_duplicate_start[] = {10, 10, 30, 40, 0};
	int	nums_negative[] = {-10, -20, -30, -20, 0};
	int	nums_single[] = {42, 0};
	int	nums_empty[] = {0};

	printf("\n========== TEST: check_duplicates ==========\n");

	CHECK(check_duplicates(nums_unique, 5) == SUCCESS,
		"Accept array without duplicates");

	CHECK(check_duplicates(nums_duplicate, 5) == ERR_DUPLICATE,
		"Detect duplicate in middle of array");

	CHECK(check_duplicates(nums_duplicate_start, 5) == ERR_DUPLICATE,
		"Detect duplicate at beginning of array");

	CHECK(check_duplicates(nums_negative, 5) == ERR_DUPLICATE,
		"Detect duplicate negative numbers");

	CHECK(check_duplicates(nums_single, 2) == SUCCESS,
		"Accept array with one number");

	CHECK(check_duplicates(nums_empty, 1) == SUCCESS,
		"Accept empty array");

	CHECK(check_duplicates(NULL, 0) == ERR_INVALID_INPUT,
		"Reject NULL pointer");
}

/* ========================================= */
/*              TEST: sort_array             */
/* ========================================= */

void	test_sort_array(void)
{
	int	nums_random[] = {3, -1, 2, -2, 0};
	int	nums_reverse[] = {4, 3, 2, 1, 0};
	int	nums_sorted[] = {-4, -3, -2, -1, 0};
	int	nums_single[] = {42, 0};
	int	nums_duplicates[] = {3, 1, 3, 2, 0};

	int	*result;

	printf("\n========== TEST: sort_array ==========\n");

	result = sort_array(nums_random, 5);

	CHECK(result[0] == -2
		&& result[1] == -1
		&& result[2] == 2
		&& result[3] == 3,
		"Sort random array");

	result = sort_array(nums_reverse, 5);

	CHECK(result[0] == 1
		&& result[1] == 2
		&& result[2] == 3
		&& result[3] == 4,
		"Sort reverse ordered array");

	result = sort_array(nums_sorted, 5);

	CHECK(result[0] == -4
		&& result[1] == -3
		&& result[2] == -2
		&& result[3] == -1,
		"Keep already sorted array unchanged");

	result = sort_array(nums_single, 2);

	CHECK(result[1] == 42,
		"Handle array with one number");

	result = sort_array(nums_duplicates, 5);

	CHECK(result[0] == 1
		&& result[1] == 2
		&& result[2] == 3
		&& result[3] == 3,
		"Sort array containing duplicates");
}

/* ========================================= */
/*                    MAIN                   */
/* ========================================= */

int	main(void)
{
	printf("\n====================================\n");
	printf("          UTILS TEST SUITE\n");
	printf("====================================\n");

	test_count_numbers();
	test_compute_disorder();
	test_check_duplicates();
	test_sort_array();

	printf("\n====================================\n");
	printf("             TEST RESULTS\n");
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
