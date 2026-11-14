/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helemart <helemart@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 18:18:50 by helemart          #+#    #+#             */
/*   Updated: 2026/09/28 18:19:49 by helemart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_pointer;
	unsigned char	*src_pointer;

	if (dest == NULL && src == NULL)
		return (NULL);
	dest_pointer = (unsigned char *)dest;
	src_pointer = (unsigned char *)src;
	if (dest_pointer > src_pointer)
	{
		while (n > 0)
		{
			n--;
			dest_pointer[n] = src_pointer[n];
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
