#include "../include/push_swap.h"
#include <stdio.h>
#include <stdlib.h>

/* ========================================= / / TEST UTILITIES / / ========================================= */

int g_failures = 0; int g_tests = 0;

#define CHECK(condition, description) do { \
	g_tests++; \
	if (condition) \
		printf("[PASS] %s\n", description); \
	else \
	{ \
		printf("[FAIL] %s (line %d)\n", description, __LINE__); \
		g_failures++; \
	} \
} while (0)


/* ========================================= / / TEST: initialize_stack / / ========================================= */

void test_initialize_stack(void) { t_stack *stack;

printf("\n========== TEST: initialize_stack ==========\n");

stack = initialize_stack();

CHECK(stack != NULL,
	"Allocate memory for a new stack");

CHECK(stack && stack->top == NULL,
	"Initialize top pointer to NULL");

CHECK(stack && stack->bottom == NULL,
	"Initialize bottom pointer to NULL");

CHECK(stack && stack->size == 0,
	"Initialize stack size to zero");

free_stack(stack);


}

/* ========================================= / / TEST: initialize_node / / ========================================= */

void test_initialize_node(void) { t_node *node;

printf("\n========== TEST: initialize_node ==========\n");

node = initialize_node(42, 3);

CHECK(node != NULL,
	"Allocate memory for a new node");

CHECK(node && node->value == 42,
	"Initialize node value correctly");

CHECK(node && node->index == 3,
	"Initialize node index correctly");

CHECK(node && node->prev == NULL,
	"Initialize previous pointer to NULL");

CHECK(node && node->next == NULL,
	"Initialize next pointer to NULL");

free_node(node);

node = initialize_node(-2147483648, 0);

CHECK(node && node->value == -2147483648,
	"Handle minimum integer value");

CHECK(node && node->index == 0,
	"Handle index zero");

free_node(node);

node = initialize_node(2147483647, 2147483647);

CHECK(node && node->value == 2147483647,
	"Handle maximum integer value");

free_node(node);


}

/* ========================================= / / TEST: free_node / / ========================================= */

void test_free_node(void) { t_node *node; void *result;

printf("\n========== TEST: free_node ==========\n");

result = free_node(NULL);

CHECK(result == NULL,
	"Handle NULL pointer safely");

node = initialize_node(42, 5);

CHECK(node != NULL,
	"Create node before freeing");

result = free_node(node);

CHECK(result == NULL,
	"Return NULL after freeing node");


}

/* ========================================= / / TEST: free_stack / / ========================================= */

void test_free_stack(void) { t_stack *stack; t_node *node1; t_node *node2; t_node *node3; void *result;

printf("\n========== TEST: free_stack ==========\n");

result = free_stack(NULL);

CHECK(result == NULL,
	"Handle NULL stack pointer safely");

stack = initialize_stack();

CHECK(stack != NULL,
	"Create empty stack before freeing");

result = free_stack(stack);

CHECK(result == NULL,
	"Free an empty stack");

stack = initialize_stack();

node1 = initialize_node(10, 0);
node2 = initialize_node(20, 1);
node3 = initialize_node(30, 2);

if (stack && node1 && node2 && node3)
{
	stack->top = node1;
	stack->bottom = node3;
	stack->size = 3;

	node1->next = node2;
	node2->prev = node1;

	node2->next = node3;
	node3->prev = node2;

	result = free_stack(stack);

	CHECK(result == NULL,
		"Free stack containing multiple linked nodes");
}
else
{
	free_node(node1);
	free_node(node2);
	free_node(node3);
	free_stack(stack);

	CHECK(0,
		"Allocate nodes for multi-node stack test");
}


}

/* ========================================= / / TEST: fill_stack / / ========================================= */

void test_fill_stack(void) {

int		original1[] = {3, 1, 5, 2, 4};
int		sorted1[] = {1, 2, 3, 4, 5};

int		original2[] = {5, 4, 3, 2, 1};
int		sorted2[] = {1, 2, 3, 4, 5};

int		original3[] = {-10, 0, 10};
int		sorted3[] = {-10, 0, 10};

int		original4[] = {42};
int		sorted4[] = {42};

t_stack	*stack;
t_node	*current;
int		i;
int		valid;

printf("\n========== TEST: fill_stack ==========\n");

/* Test 1: Random array */

stack = fill_stack(original1, sorted1, 5);

CHECK(stack != NULL,
	"Create stack from random array");

CHECK(stack && stack->size == 5,
	"Set correct stack size");

CHECK(stack && stack->top->value == 3,
	"Set first element as stack top");

CHECK(stack && stack->bottom->value == 4,
	"Set last element as stack bottom");

/* Check values and indexes */

if (stack)
{
	current = stack->top;

	CHECK(current && current->value == 3
		&& current->index == 2,
		"Assign correct index to first node");

	current = current->next;

	CHECK(current && current->value == 1
		&& current->index == 0,
		"Assign correct index to second node");

	current = current->next;

	CHECK(current && current->value == 5
		&& current->index == 4,
		"Assign correct index to third node");

	current = current->next;

	CHECK(current && current->value == 2
		&& current->index == 1,
		"Assign correct index to fourth node");

	current = current->next;

	CHECK(current && current->value == 4
		&& current->index == 3,
		"Assign correct index to fifth node");

	/* Check linked-list integrity */

	valid = 1;
	current = stack->top;
	i = 0;

	while (current && current->next)
	{
		if (current->next->prev != current)
			valid = 0;
		current = current->next;
		i++;
	}

	CHECK(valid,
		"Maintain correct prev/next pointers");

	CHECK(current == stack->bottom,
		"Last node matches bottom pointer");

	CHECK(stack->top->prev == NULL,
		"Top node has NULL previous pointer");

	CHECK(stack->bottom->next == NULL,
		"Bottom node has NULL next pointer");

	CHECK(i == 4,
		"Maintain correct number of links");

	free_stack(stack);
}

/* Test 2: Reverse ordered array */

stack = fill_stack(original2, sorted2, 5);

CHECK(stack && stack->size == 5,
	"Handle reverse ordered array");

if (stack)
{
	current = stack->top;
	valid = 1;
	i = 4;

	while (current)
	{
		if (current->index != i)
			valid = 0;
		current = current->next;
		i--;
	}

	CHECK(valid,
		"Assign descending indexes to reverse array");

	free_stack(stack);
}

/* Test 3: Negative and positive values */

stack = fill_stack(original3, sorted3, 3);

CHECK(stack && stack->size == 3,
	"Handle negative, zero and positive values");

/* Test 4: Single element */

stack = fill_stack(original4, sorted4, 1);

CHECK(stack && stack->size == 1,
	"Handle array containing one element");

CHECK(stack && stack->top == stack->bottom,
	"Single node is both top and bottom");

CHECK(stack && stack->top->value == 42
	&& stack->top->index == 0,
	"Assign correct value and index to single node");

if (stack)
	free_stack(stack);


}

/* ========================================= / / MAIN / / ========================================= */

int main(void) { printf("\n====================================\n"); printf(" STACK TEST SUITE\n"); printf("====================================\n");

test_initialize_stack();
test_initialize_node();
test_free_node();
test_free_stack();
test_fill_stack();

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