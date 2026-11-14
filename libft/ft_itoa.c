/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helemart <helemart@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 12:19:10 by helemart          #+#    #+#             */
/*   Updated: 2026/10/06 12:47:02 by helemart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	calculate_length(long n)
{
	int	length;

	if (n == 0)
		return (1);
	length = 0;
	if (n < 0)
		length++;
	while (n != 0)
	{
		length++;
		n = n / 10;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	int			length;
	char		*str_num;

	length = calculate_length(n);
	str_num = (char *) malloc ((length + 1) * sizeof(char));
	if (str_num == NULL)
		return (NULL);
	str_num[length] = '\0';
	if (n == 0)
		str_num[0] = '0';
	if (n < 0)
		str_num[0] = '-';
	while (n != 0)
	{
		length--;
		if (n < 0)
			str_num[length] = -(n % 10) + '0';
		else
			str_num[length] = (n % 10) + '0';
		n = n / 10;
	}
	return (str_num);
}
