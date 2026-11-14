/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helemart <helemart@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 17:17:37 by helemart          #+#    #+#             */
/*   Updated: 2026/09/29 17:20:21 by helemart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*pointer1;
	unsigned char	*pointer2;

	i = 0;
	pointer1 = (unsigned char *)s1;
	pointer2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (pointer1[i] != pointer2[i])
			return (pointer1[i] - pointer2[i]);
		i++;
	}
	return (0);
}
