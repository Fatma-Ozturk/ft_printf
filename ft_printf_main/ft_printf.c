/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faozturk <faozturk@42kocaeli.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 11:46:44 by faozturk          #+#    #+#             */
/*   Updated: 2022/03/04 16:20:19 by faozturk         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_formats(va_list args, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_char(va_arg(args, int));
	else if (format == 's')
		len += ft_str(va_arg(args, char *));
	else if (format == 'p')
		len += ft_ptr(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		len += ft_nbr(va_arg(args, int));
	else if (format == 'u')
		len += ft_unsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		len += ft_hex(va_arg(args, unsigned int), format);
	else if (format == '%')
		len += ft_percent();
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		len;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += ft_formats(args, str[i + 1]);
			i++;
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}

// ft_printf her zaman bir integer uzunluk değeri döndürür. %d ile bu uzunluk değeri ekrana yazdırılabilir.

#include <stdio.h>
int    main(void)
{
    //int a;
    //int b;
    //int c;
    //char    *d;
    //unsigned int    ui;
    //ui = 4294967295;
    //a = 50;
    //b = 44444;
    //c = 'd';
    //d = "OMG";
    // printf("\n%d\n", ft_printf("yey %d WOW %d %c %s %% || %i %p || %u", a, b, c, d, a, &a, ui));
    // printf("\n%d\n", ft_printf("yey %d WOW %d %c %s %% || %i %p || %u", a, b, c, d, a, &a, ui));
    // ft_printf("%u", 15);
    //int res = ft_printf("Fatma %d\n", 55);
    //int res2 = printf("Fatma %d\n", 55);
    //printf("\nres - %d\nres2 - %d\n", res, res2);
    //ft_printf("%c\n", 'm');
    //ft_printf("%d\n", 100);
    //ft_printf("%s\n", "fatma");
    //ft_printf("%p\n", &a);
    //ft_printf("%%\n");
    int x = ft_printf("%x\n", "fatma");
    printf("%d\n", x);
}


