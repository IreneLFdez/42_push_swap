/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helemart <helemart@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 13:08:24 by helemart          #+#    #+#             */
/*   Updated: 2026/09/30 13:15:05 by helemart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*str_dup;

	i = 0;
	str_dup = (char *) malloc ((ft_strlen(s) + 1) * sizeof(char));
	if (str_dup == NULL)
		return (NULL);
	while (s[i])
	{
		str_dup[i] = s[i];
		i++;
	}
	str_dup[i] = '\0';
	return (str_dup);
}
