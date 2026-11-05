// In case of error, the program must display "Error" followed by \n on the standard error.

#include <unistd.h>
#include <stdlib.h>

void	*print_err(int err)
{
	if (err == 1)
	{
		// dislay nothing and return prompt
		write(2, "[PLACEHOLDER]\n", 14);
		return (err);
	}
	write(2, "Error\n", 6);
	return (err);
}

int		is_flag(const char *s)
{
	int	i;

	i = 2;
	if (s[0] == "-" && s[1] == "-")
	{
		// compare up to str_size + 1 to check word has no more text (?)
		if (ft_strncmp(s, "bench", 6) == 0)
			return (1);
		if (ft_strncmp(s, "simple", 7) == 0)
			return (2);
		if (ft_strncmp(s, "medium", 7) == 0)
			return (3);
		if (ft_strncmp(s, "complex", 8) == 0)
			return (4);
		if (ft_strncmp(s, "adaptive", 9) == 0)
			return (5);
	}
	return (0);
}

// NOTE! Doy por sentado que el parámetro vendrá como 1 2 3 4 o "1 2 3 4", pero nunca con dobles espacios o cosas como 1 2 "  3  4"
// char	*strjoin_custom(int argc, char **argv, int current_arg)
// {
// 	char	*str;
// 	int		length;
// 	int		index;
// 	int		i;
// 	int		j;

// 	length = 0;
// 	index = current_arg;
// 	while (index < argc)
// 	{
// 		length += ft_strlen(argv[index]);
// 		index++;
// 		length++; // esto es para tener en cuenta el espacio que voy a añadir al string final entre joins
// 	}
// 	str = (char *) malloc ((length + 1) * sizeof(char));
// 	i = 0;
// 	j = 0;
// 	while (current_arg < argc)
// 	{
// 		while (argv[current_arg][i])
// 		{
// 			str[i] = argv[current_arg][i];
// 			i++;
// 		}

// 	}
// 	return (str);
// }

int		main(int argc, char **argv)
{
	int		current_arg;
	int		flag;
	int		bench;
	char	*arr_nums;

	// Param number check
	if (argc < 2)
		return (print_err(1));

	// Flag check (flags are passed like arguments)
	current_arg = 1;
	flag = is_flag(argv[current_arg]);
	bench = 0;
	if (flag == 0)
	{
		// no flags entered for this execution
	}
	else
	{
		if (flag == 1)
		{
			// --bench flag has been selected
			bench = 1;
			current_arg++;
			flag = is_flag(argv[current_arg]);
		}
		if (flag == 2)
		{
			// --simple flag has been selected

		}
		if (flag == 3)
		{
			// --medium flag has been selected
		}
		if (flag == 4)
		{
			// --complex flag has been selected
		}
		if (flag == 5)
		{
			// --adaptive flag has been selected
		}
		current_arg++;
	}

	if (argc == current_arg + 1)
	{
		// Only one argument for number array (either a single number or a "string of numbers")
		parse_numbers(argv[current_arg]);
	}
	else
	{
		// Unify in one string all arguments that comprise the future numbers array
		arr_nums = strjoin_custom(argc, argv, current_arg);
		if (!arr_nums)
			return (print_err(5)); // error when parsing string of numbers or memory allocation failure
	}

	// Param is not integer

	// Integer is outside of range

	// Duplicated value


	return (0);

}