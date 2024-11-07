/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 21:10:51 by aelaaser          #+#    #+#             */
/*   Updated: 2024/10/18 21:19:04 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_revstr(char *s)
{
	char	*tmp;
	int		len;
	int		i;

	len = ft_strlen(s) - 1 ;
	tmp = malloc(sizeof(char) * (len + 2));
	if (tmp == NULL)
		return (NULL);
	i = 0;
	while (len >= 0)
	{
		tmp[i] = s[len];
		len--;
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
