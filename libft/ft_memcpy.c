/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helemart <helemart@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 12:48:57 by helemart          #+#    #+#             */
/*   Updated: 2026/09/28 12:51:17 by helemart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*dest_pointer;
	char	*src_pointer;
	size_t	i;

	dest_pointer = (char *)dest;
	src_pointer = (char *)src;
	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		dest_pointer[i] = src_pointer[i];
		i++;
	}
	return (dest);
}
