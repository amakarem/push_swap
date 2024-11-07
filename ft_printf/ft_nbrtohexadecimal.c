/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrtohexadecimal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 20:13:29 by aelaaser          #+#    #+#             */
/*   Updated: 2024/10/19 15:30:25 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_hexconv(unsigned int n, char format)
{
	if (n <= 9)
		return (n + 48);
	else if (format == 'X' && n >= 10 && n <= 16)
		return (n + 55);
	else
		return (n + 87);
}

int	ft_nbrtohexadecimal(unsigned int n, char format)
{
	unsigned int	tmp;
	char			*hex;
	char			*tmphex;
	int				i;

	if (n == 0)
		return (ft_putchar('0'));
	tmphex = malloc(sizeof(char) * 9);
	if (!tmphex)
		return (-1);
	i = 0;
	while (n > 0)
	{
		tmp = n;
		n = (n / 16);
		tmphex[i++] = ft_hexconv(tmp - (16 * n), format);
	}
	tmphex[i] = '\0';
	hex = ft_revstr(tmphex);
	free(tmphex);
	if (!hex)
		return (-1);
	i = ft_putstr(hex);
	free(hex);
	return (i);
}
