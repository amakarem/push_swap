/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsignednbr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 19:36:23 by aelaaser          #+#    #+#             */
/*   Updated: 2024/10/19 15:56:08 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsignednbr(unsigned int n)
{
	int	i;
	int	result;

	i = 0;
	if (n >= 10)
	{
		result = ft_putunsignednbr(n / 10);
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
