/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helemart <helemart@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 11:23:03 by helemart          #+#    #+#             */
/*   Updated: 2026/10/02 11:32:27 by helemart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	calculate_start(const char *s1, const char *set)
{
	size_t	start;
	size_t	i;
	int		found;

	start = 0;
	while (s1[start])
	{
		i = 0;
		found = 0;
		while (set[i] && !found)
		{
			if (s1[start] == set[i])
				found = 1;
			i++;
		}
		if (!found)
			return (start);
		start++;
	}
	return (start);
}

static size_t	calculate_length(const char *s1, const char *set, size_t start)
{
	size_t	end;
	size_t	i;
	int		found;

	end = ft_strlen(s1);
	found = 1;
	while (end > start && found)
	{
		i = 0;
		found = 0;
		while (set[i] && !found)
		{
			if (s1[end - 1] == set[i])
				found = 1;
			i++;
		}
		if (found)
			end--;
	}
	return (end - start);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	i;
	size_t	start;
	size_t	length;
	char	*str_trim;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	start = calculate_start(s1, set);
	length = calculate_length(s1, set, start);
	str_trim = (char *) malloc ((length + 1) * sizeof(char));
	if (str_trim == NULL)
		return (NULL);
	while (length)
	{
		str_trim[i] = s1[start];
		i++;
		start++;
		length--;
	}
	str_trim[i] = '\0';
	return (str_trim);
}
