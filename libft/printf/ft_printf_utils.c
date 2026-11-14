/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilopez-f <ilopez-f@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 15:54:58 by ilopez-f          #+#    #+#             */
/*   Updated: 2026/11/14 15:31:49 by ilopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_count_digits(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	ft_putnbr_count(int nb)
{
	char	n;
	int		len;

	len = ft_count_digits(nb);
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr_count(nb / 10);
	n = (nb % 10) + '0';
	write(1, &n, 1);
	return (len);
}


int	ft_putnbr_base_count(unsigned long long nbr, char *base)
{
	int	base_len;
	int	len;

	base_len = 0;
	len = 0;
	while (base[base_len])
		base_len++;
	if (nbr >= (unsigned long long)base_len)
		len += ft_putnbr_base_count(nbr / base_len, base);
	len += ft_putchar(base[nbr % base_len]);
	return (len);
}
