/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jju <jju@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 19:03:17 by jju               #+#    #+#             */
/*   Updated: 2022/02/06 17:57:42 by jju              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_write(char c)
{
	write(1, &c, 1);
}

void	num_write(int *num, int negative)
{
	char	c;
	int		findzero;
	int		temp;

	findzero = 0;
	temp = 9;
	if (negative == 1)
		write(1, "-", 1);
	while (temp > -1)
	{
		if (num[temp] != 0)
			findzero = 1;
		if (findzero == 1)
		{
			c = num[temp] + 48;
			write(1, &c, 1);
		}
		if (findzero == 0 && temp == 0)
			ft_write('0');
		temp--;
	}
}

void	ft_putnbr(int nb)
{
	int				num[10];
	int				negative;
	unsigned int	un_nb;

	un_nb = nb;
	negative = 0;
	if (nb < 0)
	{
		negative = 1;
		un_nb = nb * -1;
	}
	num[9] = un_nb / 1000000000;
	num[8] = un_nb % 1000000000 / 100000000;
	num[7] = un_nb % 100000000 / 10000000;
	num[6] = un_nb % 10000000 / 1000000;
	num[5] = un_nb % 1000000 / 100000;
	num[4] = un_nb % 100000 / 10000;
	num[3] = un_nb % 10000 / 1000;
	num[2] = un_nb % 1000 / 100;
	num[1] = un_nb % 100 / 10;
	num[0] = un_nb % 10;
	num_write(num, negative);
}
