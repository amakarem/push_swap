/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 21:17:04 by aelaaser          #+#    #+#             */
/*   Updated: 2024/10/19 16:11:31 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_negative(int n)
{
	int	i;
	int	result;

	i = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		result = ft_putchar('-');
		if (result < 0)
			return (-1);
		i += result;
		result = ft_putnbr(-n);
		if (result < 0)
			return (-1);
		i += result;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	int	i;
	int	result;

	i = 0;
	if (n < 0)
		return (ft_putnbr_negative(n));
	if (n >= 10)
	{
		result = ft_putnbr((n / 10));
		if (result < 0)
			return (-1);
		i += result;
		result = ft_putchar((n % 10 + '0'));
		if (result < 0)
			return (-1);
		i += result;
	}
	else
		i = ft_putchar((n + '0'));
	return (i);
}
