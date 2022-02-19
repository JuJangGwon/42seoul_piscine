/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jju <jju@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 19:40:12 by jju               #+#    #+#             */
/*   Updated: 2022/02/08 19:11:59 by jju              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_finishcheck(int *a, int n)
{
	int	standard;
	int	temp;

	standard = 10 - n;
	temp = 0;
	while (temp < n)
	{
		if (a[temp] == standard + temp)
		{
			if (temp == n - 1)
			{
				return (1);
			}
		}
		else
		{
			break ;
		}
		temp++;
	}
	write(1, ", ", 2);
	return (0);
}

void	write_itoa(int *a, int n)
{
	char	c;
	int		tem;

	tem = 0;
	while (tem < n)
	{
		c = a[tem] + 48;
		write(1, &c, 1);
		tem ++;
	}
}

void	setarray(int *c, int n)
{
	int	standard;
	int	pivot;
	int	minus;
	int	temp;

	standard = 10;
	pivot = n - 1;
	minus = 0;
	while (pivot > 0)
	{
		if (c[pivot] >= standard - minus)
		{
			temp = 0;
			c[pivot - 1]++;
			while (temp + pivot <= n + 1)
			{
				c[pivot + temp] = c[pivot - 1] + temp + 1;
				temp ++;
			}
		}
		pivot--;
		minus++;
	}
}

void	initarray(int *c, int n)
{
	int	temp;

	temp = 0;
	while (temp < n)
	{
		c[temp] = temp;
		temp = temp + 1;
	}
}

void	ft_print_combn(int n)
{
	int	c[11];
	int	finishcheck;

	finishcheck = 0;
	initarray(c, n);
	write_itoa(c, n);
	write(1, ", ", 2);
	while (finishcheck == 0)
	{
		c[n - 1]++;
		setarray(c, n);
		write_itoa(c, n);
		finishcheck = ft_finishcheck(c, n);
	}
}

int	main(void)
{
	int i = 5;

	ft_print_combn(4);

	return 0;
}
