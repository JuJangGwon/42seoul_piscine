/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jju <jju@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 10:51:54 by jju               #+#    #+#             */
/*   Updated: 2022/02/05 16:04:05 by jju              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	write_edgeline(int max_x, int x)
{
	if (x == 1)
	{
		ft_putchar('A');
	}
	else if (x == max_x && x != 1)
	{
		ft_putchar('C');
	}
	else
	{
		ft_putchar('B');
	}
}

void	write_insideline(int max_x, int x)
{
	if (x == 1 || x == max_x)
	{
		ft_putchar('B');
	}
	else
	{
		ft_putchar(' ');
	}
}

void	linecheck(int max_x, int max_y, int x, int y)
{
	if (y == 1 || y == max_y)
	{
		write_edgeline(max_x, x);
	}
	else
	{
		write_insideline(max_x, x);
	}
}

void	rush(int x, int y)
{
	int	num_x;
	int	num_y;

	num_y = 1;
	if (x < 1 || y < 1)
	{
		return ;
	}
	while (num_y <= y)
	{
		num_x = 1;
		while (num_x <= x)
		{
			linecheck(x, y, num_x, num_y);
			num_x = num_x + 1;
		}
		num_y = num_y + 1;
		write(1, "\n", 1);
	}
}
