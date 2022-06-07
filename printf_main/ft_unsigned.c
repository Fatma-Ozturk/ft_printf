/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faozturk <faozturk@42kocaeli.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 11:50:35 by faozturk          #+#    #+#             */
/*   Updated: 2022/03/04 14:57:09 by faozturk         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_numlen(unsigned int num)
{
	int	len;

	len = 0;
	while (num)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

char	*ft_unitoa(unsigned int n)
{
	char	*num;
	int		len;

	len = ft_numlen(n);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (0);
	num[len] = '\0';
	while (n != 0)
	{
		num[len - 1] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	return (num);
}

int	ft_unsigned(unsigned int n)
{
	int		len;
	char	*num;

	len = 0;
	if (n == 0)
		len += write(1, "0", 1);
	else
	{
		num = ft_unitoa(n);
		len += ft_str(num);
		free(num);
	}
	return (len);
}

// n sayımızı ft_unitoa fonksiyonu ile stringe çevirip num içine atıyoruz. Çevirme işlemini sondan başlarak kalan yardımı ile yapıyoruz.
// num u da ft_str fonksiyonu ile hem yazdırıp hem len olarak döndürüyoruz.
