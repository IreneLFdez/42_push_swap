/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helemart <helemart@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 12:54:52 by helemart          #+#    #+#             */
/*   Updated: 2026/09/30 13:05:54 by helemart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_bytes;
	void	*pointer;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb > (size_t) - 1 / size)
		return (NULL);
	total_bytes = nmemb * size;
	pointer = malloc(total_bytes);
	if (pointer == NULL)
		return (NULL);
	ft_bzero(pointer, total_bytes);
	return (pointer);
}
