/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helemart <helemart@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 12:09:16 by helemart          #+#    #+#             */
/*   Updated: 2026/09/28 12:09:53 by helemart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*starting_pointer;

	starting_pointer = (unsigned char *)s;
	while (n > 0)
	{
		*starting_pointer = 0;
		starting_pointer++;
		n--;
	}
}
