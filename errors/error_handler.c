// In case of error, the program must display "Error" followed by \n on the standard error.

#include "../push_swap.h"

/// @brief Prints out error in terminal and returns error number.
/// @param err t_error enum for error types.
/// @return Integer unsigned value of error.
int		print_err(t_error err)
{
	if (err == SUCCESS)
		return (err);
	if (err == ERR_INVALID_INPUT)
	{
		// dislay nothing and return prompt
		write(2, "[PLACEHOLDER]\n", 14);
		return (-err);
	}
	write(2, "Error\n", 6);
	return (-err);
}
