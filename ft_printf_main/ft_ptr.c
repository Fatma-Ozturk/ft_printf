/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faozturk <faozturk@42kocaeli.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 11:50:46 by faozturk          #+#    #+#             */
/*   Updated: 2022/03/04 14:56:05 by faozturk         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_ptrlen(uintptr_t num)
{
	int	len;

	len = 0;
	while (num)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_putptr(uintptr_t num)
{
	if (num >= 16)
	{
		ft_putptr(num / 16);
		ft_putptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
			ft_putchar_fd((num - 10 + 'a'), 1);
	}
}

int	ft_ptr(unsigned long long ptr)
{
	int	len;

	len = 0;
	len += write(1, "0x", 2);
	if (ptr == 0)
		len += write(1, "0", 1);
	else
	{
		ft_putptr(ptr);
		len += ft_ptrlen(ptr);
	}
	return (len);
}	

// mesela a pointerın adres değerini gönderdik diyelim. unsigned long long olarak yani int tipinde gelecek.
// ilk olarak başa 0x yazılacak daha sonra sayı putptrye gönderilip 16lık tabanda yazımı yapılacak. 123 diyelim 16ya bölümünden bölüm 7 kalan 11 olacak. 7 tekrar döngüye girip olduğu gibi yazılacak 11 de döngüye girecek ve 11-10 dan 1 + 'a' dan 'b' olarak yazılacak.
// sonuç 0x7b olacak.0123456789abcdef 10 sayıp a ya kadar gelip sonra a dan itibaren sayma yapmış olduk.
