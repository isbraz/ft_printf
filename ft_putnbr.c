/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbraz-d <isbraz-d@student.com.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:50:22 by isbraz-d          #+#    #+#             */
/*   Updated: 2023/05/04 16:09:08 by isbraz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	ft_count_digits(int number)
{
	int	i;

	i = 0;
	if (number < 0)
	{
		number *= -1;
		i++;
	}
	if (number == 0)
		return (1);
	while (number > 0)
	{
		number /= 10;
		i++;
	}
	return (i);
}

int	ft_putnbr(int number)
{
	int	c;

	c = ft_count_digits(number);
	if (number == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	else if (number < 0)
	{
		number *= -1;
		ft_putchar ('-');
		ft_putnbr(number);
	}
	else if (number > 9)
	{
		ft_putnbr (number / 10);
		ft_putnbr (number % 10);
	}
	else
		ft_putchar(number + 48);
	return (c);
}

/*
int	main(void)
{
	int	number = 90;

	ft_putnbr(number);
	printf("\n%d\n", ft_putnbr(number));
}
*/