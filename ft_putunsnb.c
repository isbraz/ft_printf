/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsnb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbraz-d <isbraz-d@student.com.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 18:19:04 by isbraz-d          #+#    #+#             */
/*   Updated: 2023/05/04 16:03:35 by isbraz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsnb(unsigned int number)
{
	int	c;

	c = 0;
	if (number > 9)
	{
		c += ft_putunsnb(number / 10);
		c += ft_putunsnb(number % 10);
	}
	else
	{
		ft_putchar(number + 48);
		c++;
	}
	return (c);
}

/*
int	main(void)
{
	unsigned int number;

	number = 40;
	ft_putunsnb(40);
}
*/