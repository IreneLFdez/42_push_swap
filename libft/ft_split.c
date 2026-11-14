/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helemart <helemart@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 11:33:49 by helemart          #+#    #+#             */
/*   Updated: 2026/10/02 11:48:33 by helemart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_strs(const char *s, char c)
{
	int		count;
	int		flag;

	count = 0;
	flag = 0;
	if (!s)
		return (0);
	while (*s)
	{
		if (*s != c && flag == 0)
		{
			flag = 1;
			count++;
		}
		else if (*s == c)
			flag = 0;
		s++;
	}
	return (count);
}

static char	*add_str(const char *s, char c, int *start)
{
	int		i;
	int		length;
	char	*str;

	i = 0;
	length = 0;
	while (s[*start + length] && s[*start + length] != c)
		length++;
	str = (char *) malloc ((length + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (i < length)
	{
		str[i] = s[*start + i];
		i++;
	}
	str[i] = '\0';
	*start += length;
	return (str);
}

static char	**free_strs(char **split, int step)
{
	while (step > 0)
	{
		step--;
		free(split[step]);
	}
	free(split);
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	int		i;
	int		start;
	int		count;
	char	**split;

	if (!s)
		return (NULL);
	count = count_strs(s, c);
	split = (char **) malloc ((count + 1) * sizeof(char *));
	if (split == NULL)
		return (NULL);
	i = 0;
	start = 0;
	while (i < count)
	{
		while (s[start] && s[start] == c)
			start++;
		split[i] = add_str(s, c, &start);
		if (!split[i])
			return (free_strs(split, i));
		i++;
	}
	split[i] = NULL;
	return (split);
}
