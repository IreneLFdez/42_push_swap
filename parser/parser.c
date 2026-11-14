#include "../push_swap.h"

int		is_flag(const char *s)
{
	if (!s)
		return (0);
	// compare up to str_size + 1 to check word has no more text (?)
	if (ft_strncmp(s, "--bench", 8) == 0)
		return (1);
	if (ft_strncmp(s, "--simple", 9) == 0)
		return (2);
	if (ft_strncmp(s, "--medium", 9) == 0)
		return (3);
	if (ft_strncmp(s, "--complex", 10) == 0)
		return (4);
	if (ft_strncmp(s, "--adaptive", 11) == 0)
		return (5);
	if (ft_isdigit(s[0]))
		return (6);
	return (0);
}

int	parse_flags(char **argv, t_options *options)
{
	int	flag;
	int	index;

	index = 1;
	options->bench = 0;
	options->strategy = STRATEGY_ADAPTIVE;
	while (argv[index] && index < 3)
	{
		flag = is_flag(argv[index]);

		if (flag == 1)
		{
			if (options->bench == 1)
				return (ERR_INVALID_INPUT);
			options->bench = 1;
			index++;
		}
		else if (flag >= 2 && flag <= 5)
			options->strategy = flag;
		else if (flag == 6)
			break ;
		else
			return (ERR_INVALID_INPUT);
		index++;
	}
	return (index);
}


int		*parse_numbers(char **argv, int index, t_error *err)
{
	int		i;
	int		j;
	int		*arr_nums;
	char	**split;

	i = 0;
	arr_nums = (int *) malloc (count_numbers(argv, index) * sizeof(int));
	if (!arr_nums)
		return (*err = ERR_MEMORY, NULL);
	while (argv[index])
	{
		split = ft_split(argv[index], ' ');
		if (!split)
		{
			*err = ERR_MEMORY;
			return (free(arr_nums), NULL);
		}
		j = 0;
		while (split[j])
			arr_nums[i++] = ft_atoi(split[j++]);
		free_split(split);
		index++;
	}
	return (arr_nums);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}