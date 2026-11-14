/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilopez-f <ilopez-f@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 18:32:02 by ilopez-f          #+#    #+#             */
/*   Updated: 2026/11/14 15:34:06 by ilopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int	ft_printf(const char *format, ...);
int	ft_putchar(char c);
int	ft_putstr_count(char *str);
int	ft_putnbr_count(int nb);
int	ft_putnbr_base_count(unsigned long long nbr, char *base);
int	ft_print_ptr_count(void *ptr);
int	ft_putfloat_count(double num);

#endif