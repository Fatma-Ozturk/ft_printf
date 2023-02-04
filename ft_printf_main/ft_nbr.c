/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faozturk <faozturk@42kocaeli.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 12:49:06 by faozturk          #+#    #+#             */
/*   Updated: 2022/03/04 15:24:26 by faozturk         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_nbr(int n)
{
	int		len;
	char	*num;

	len = 0;
	num = ft_itoa(n);
	len = ft_str(num);
	free(num);
	return (len);
}

//n sayısını ilk önce itoa ile stringe çevirip num içine attık. numa malloc yeri açmış olduk.
//num stringini ft_str ye gönderip string yazdırma işlemini yapıp dönüşü len olarak aldık.
// num u free bırakmak gerekiyor.
