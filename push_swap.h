// this is a temporary file that needs to be merged with other implementations of the final header file

// NODE structure
typedef struct s_node
{
	int				value;		// Number to sort
	int				index;		// Does not change
	struct s_node	*next;		// Next node in list
	struct s_node	*prev;		// Previous node in list
}					t_node;


// LIST OF NODES structure
typedef struct s_stack
{
	t_node			*top;		// First element in list
	t_node			*bottom;	// Last element in list
	int				size;		// Number of nodes
}					t_stack;