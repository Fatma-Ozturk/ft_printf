/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faozturk <faozturk@42kocaeli.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 12:03:39 by faozturk          #+#    #+#             */
/*   Updated: 2022/03/04 15:21:03 by faozturk         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

int		ft_printf(const char *format, ...);
int		ft_formats(va_list args, const char format);

int		ft_char(int c);

int		ft_ptr(unsigned long long ptr);
void	ft_putptr(uintptr_t num);
int		ft_ptrlen(uintptr_t num);

int		ft_unsigned(unsigned int n);
char	*ft_unitoa(unsigned int n);
int		ft_numlen(unsigned int num);

int		ft_percent(void);

int		ft_str(char *str);
void	ft_putstr(char *s);

int		ft_nbr(int n);

int		ft_hex(unsigned int num, const char format);
void	ft_puthex(unsigned int num, const char format);
int		ft_hexlen(unsigned int num);

#endif
