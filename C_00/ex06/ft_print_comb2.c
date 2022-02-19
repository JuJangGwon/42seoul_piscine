/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jju <jju@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 19:58:02 by jju               #+#    #+#             */
/*   Updated: 2022/02/06 14:31:15 by jju              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	f_write(char num)
{
	write(1, &num, 1);
}

void	write_2thnum(char num)
{
	char	num1th;
	char	num2th;

	num1th = num / 10 + 48;
	num2th = num % 10 + 48;
	f_write(num1th);
	f_write(num2th);
}

void	print_num(char num1, char num2)
{
	if (num1 <= 9)
	{
		f_write('0');
		f_write(num1 + 48);
	}
	else
	{
		write_2thnum(num1);
	}
	write(1, " ", 1);
	if (num2 <= 9)
	{
		f_write('0');
		f_write(num2 + 48);
	}
	else
	{
		write_2thnum(num2);
	}
	if (num2 != 99 || num1 != 98)
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	while (a < 99)
	{
		b = a + 1;
		while (b < 100)
		{	
			print_num(a, b);
			b = b + 1;
		}
		a = a + 1;
	}
}
