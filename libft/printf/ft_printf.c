/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilopez-f <ilopez-f@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 18:16:04 by ilopez-f          #+#    #+#             */
/*   Updated: 2026/11/14 15:35:48 by ilopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_count(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_putstr_count("(null)"));
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_print_ptr_count(void *ptr)
{
	int	count;

	count = 0;
	if (!ptr)
		count = ft_putstr_count("(nil)");
	else
	{
		count = ft_putstr_count("0x");
		count += ft_putnbr_base_count((unsigned long long)ptr,
				"0123456789abcdef");
	}
	return (count);
}

int	ft_parse_format(char format, va_list *args)
{
	int	count;

	count = 0;
	if (format == 'c')
		count = ft_putchar(va_arg(*args, int));
	else if (format == 's')
		count = ft_putstr_count(va_arg(*args, char *));
	else if (format == 'd' || format == 'i')
		count = ft_putnbr_count(va_arg(*args, int));
	else if (format == 'u')
		count = ft_putnbr_base_count(va_arg(*args, unsigned int), "0123456789");
	else if (format == 'x')
		count = ft_putnbr_base_count(va_arg(*args, unsigned int),
				"0123456789abcdef");
	else if (format == 'X')
		count = ft_putnbr_base_count(va_arg(*args, unsigned int),
				"0123456789ABCDEF");
	else if (format == 'p')
		count += ft_print_ptr_count(va_arg(*args, void *));
	else if (format == 'f')
		count += ft_putfloat_count(va_arg(*args, double));
	else if (format == '%')
		count = ft_putchar('%');
	return (count);
}

int	ft_printf(char const *format, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1])
		{
			count += ft_parse_format(format[i + 1], &args);
			i += 2;
		}
		else
		{
			ft_putchar(format[i]);
			i++;
			count++;
		}
	}
	va_end(args);
	return (count);
}
