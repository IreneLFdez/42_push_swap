#include "../push_swap.h"

t_stack	*initialize_stack(t_stack *stack)
{
	if (!stack)
	{
		stack = (t_stack *) malloc ((sizeof(t_stack)));
		if (!stack)
			return (NULL);
	}
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
	return (stack);
}

t_node	*initialize_node(int value, int index)
{
	t_node  *node;

	node = (t_node *) malloc ((sizeof(t_node)));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = index;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void	*free_node(t_node *node)
{
	if (!node)
		return (NULL);
	node->value = 0;
	node->index = 0;
	node->next = NULL;
	node->prev = NULL;
	free(node);
	return (NULL);
}

void	*free_stack(t_stack *stack)
{
	t_node *current;
	t_node *next;

	if (!stack)
		return (NULL);

	current = stack->top;
	while (current)
	{
		next = current->next;
		free_node(current);
		current = next;
	}
	free(stack);
	return (NULL);
}


t_stack	*fill_stack(int *arr_nums, int *arr_nums_ordered, int size)
{
	t_stack *stack;
	t_node  *node;
	int		value;
	int		index;
	int		i;

	// i = 0;
	// while (size > 0)
	// {
	// 	value = arr_nums[i];
	// }
	// initialize_node(value, index);
	// node->index = find_index(arr_nums_ordered, value);
	// node->prev = stack->bottom;
	// node->next = NULL;
	// if (stack->size == 0)
	// 	stack->bottom = node;
	// else
	// 	stack->top->prev = node;
	// stack->top = node;
	// stack->size++;

	// return (stack);
}
