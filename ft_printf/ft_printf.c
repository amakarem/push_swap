/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 21:21:57 by aelaaser          #+#    #+#             */
/*   Updated: 2024/10/19 16:30:19 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_case_int(char format, void *arg)
{
	if (format == 'i' || format == 'd')
		return (ft_putnbr((int)arg));
	else if (format == 'c')
		return (ft_putchar((int)arg));
	else if (format == 'X' || format == 'x')
		return (ft_nbrtohexadecimal((unsigned int)arg, format));
	else if (format == 'u')
		return (ft_putunsignednbr((unsigned int)arg));
	else if (format == 's')
		return (ft_putstr((char *)arg));
	else if (format == 'p')
		return (ft_printptr((void *)arg));
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		result;
	va_list	arg;

	i = 0;
	va_start(arg, format);
	while (*format && i >= 0)
	{
		if (*format != '%')
			result = ft_putchar(*format);
		else
		{
			format++;
			if (*format == '%')
				result = (ft_putchar('%'));
			else if (*format)
				result = ft_print_case_int(*format, va_arg(arg, void *));
		}
		if (result < 0)
			return (-1);
		i += result;
		format++;
	}
	va_end(arg);
	return (i);
}
