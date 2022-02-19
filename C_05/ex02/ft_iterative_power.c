/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jju <jju@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:21:11 by jju               #+#    #+#             */
/*   Updated: 2022/02/17 12:49:38 by jju              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_iterative_power(int nb, int power)
{
	int	sum;
	int	i;

	sum = nb;
	i = 1;
	if (nb == 0 && power == 0)
		return (1);
	if (power < 0 || nb == 0)
		return (0);
	while (i < power)
	{
		sum = sum * nb;
		i++;
	}
	return (sum);
}
