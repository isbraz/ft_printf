/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbraz-d <isbraz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:34:09 by isbraz-d          #+#    #+#             */
/*   Updated: 2023/05/09 18:24:14 by isbraz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	ft_type(char type, va_list args)
{
	int	c;

	c = 0;
	if (type == '%')
		c += ft_putchar('%');
	else if (type == 'c')
		c += ft_putchar(va_arg(args, int));
	else if (type == 'd' || type == 'i')
		c += ft_putnbr(va_arg(args, int));
	else if (type == 's')
		c += ft_putstr(va_arg(args, char *));
	else if (type == 'u')
		c += ft_putunsnb(va_arg(args, unsigned int));
	else if (type == 'x' || type == 'X')
		c += ft_hexdec(va_arg(args, unsigned int), type);
	else if (type == 'p')
		c += ft_adress(va_arg(args, void *));
	return (c);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		c;
	int		i;

	i = 0;
	c = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			c += ft_type(str[++i], args);
			i++;
			continue ;
		}
		c += ft_putchar(str[i++]);
	}
	return (c);
}

/*
int	main(void)
{
	unsigned int	teste = 4294967295;
	
	printf("%p%p\n", &teste);
	ft_printf("%p\n", &teste);
}
*/