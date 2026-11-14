/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helemart <helemart@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 19:04:10 by helemart          #+#    #+#             */
/*   Updated: 2026/09/24 19:10:01 by helemart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*starting_pointer;
	unsigned char	byte_value;

	starting_pointer = (unsigned char *)s;
	byte_value = (unsigned char)c;
	if (n == 0)
		return (s);
	while (n > 0)
	{
		*starting_pointer = byte_value;
		starting_pointer++;
		n--;
	}
	return (s);
}
