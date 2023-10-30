/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbraz-d <isbraz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:14:56 by isbraz-d          #+#    #+#             */
/*   Updated: 2023/05/09 14:21:05 by isbraz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexdec(unsigned long int n, char type)
{
	char	*base;
	int		c;

	c = 0;
	if (type == 'x')
		base = LOW_HEX;
	if (type == 'X')
		base = UPP_HEX;
	if (n >= 16)
	{
		c += ft_hexdec(n / 16, type);
		c += ft_hexdec(n % 16, type);
	}
	else
	{
		write(1, &base[n], 1);
		c++;
	}
	return (c);
}

/*
int	main(void)
{
	unsigned int n = 60;

	printf("\n%d\n", ft_hexdec(n, 'x'));	
}
*/