/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 21:14:01 by aelaaser          #+#    #+#             */
/*   Updated: 2024/11/04 21:34:59 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_putchar(char c);
int		ft_putstr(const char *s);
int		ft_putnbr(int n);
int		ft_putunsignednbr(unsigned int n);
int		ft_printf(const char *format, ...);
char	ft_hexconv(unsigned int n, char format);
int		ft_nbrtohexadecimal(unsigned int n, char format);
char	*ft_revstr(char *s);
size_t	ft_strlen(const char *str);
int		ft_printptr(void *ptr);
#endif
