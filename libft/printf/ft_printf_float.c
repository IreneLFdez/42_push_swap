/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_float.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilopez-f <ilopez-f@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 15:15:46 by ilopez-f          #+#    #+#             */
/*   Updated: 2026/11/14 15:33:55 by ilopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/// @brief Imprime los 0 que siguen al punto en un número decimal.
/// @param fractional_part Parte decimal del número convertida a long long.
/// @param multiplier 
/// @return Número de caracteres impresos.
static int	ft_print_zeros(long long fractional_part, long long multiplier)
{
	int	character_count;

	character_count = 0;
	multiplier /= 10;
	if (multiplier > 0 && fractional_part < multiplier)
	{
		character_count += ft_putchar('0');
		character_count += ft_print_zeros(fractional_part, multiplier);
	}
	return (character_count);
}

/// @brief Imprime la parte decimal de un número.
/// @param fractional_part Parte decimal el número convertida a long long.
/// @param multiplier Multiplicador base.
/// @return Número de caracteres impresos.
static int	ft_putfraction(long long fractional_part, long long multiplier)
{
	int	character_count;

	character_count = 0;
	character_count += ft_print_zeros(fractional_part, multiplier);
	if (fractional_part > 0)
		character_count += ft_putnbr_base_count(fractional_part, "0123456789");
	else
		character_count += ft_putchar('0');
	return (character_count);
}

/// @brief Imprime un número decimal.
/// @param num Número a imprimir.
/// @return Número total de catacteres impresos.
int	ft_putfloat_count(double num)
{
	long long	integer_part;
	double		fraction_part;
	long long	fractional_digits;
	int			character_count;

	character_count = 0;
	if (num < 0)
	{
		character_count += ft_putchar('-');
		num = -num;
	}
	integer_part = (long long)num;
	fraction_part = num - (double)integer_part;
	fractional_digits = (long long)(fraction_part * 1000000.0 + 0.5);
	if (fractional_digits >= 1000000)
	{
		integer_part += 1;
		fractional_digits = 0;
	}
	character_count += ft_putnbr_base_count(integer_part, "0123456789");
	character_count += ft_putchar('.');
	character_count += ft_putfraction(fractional_digits, 1000000);
	return (character_count);
}
