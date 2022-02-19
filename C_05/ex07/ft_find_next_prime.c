/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jju <jju@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:54:20 by jju               #+#    #+#             */
/*   Updated: 2022/02/17 15:32:56 by jju              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	primecheck(int nb)
{
	int	j;

	while (j * j <= nb && j <= 46340)
	{
		j = 2;
		while (j < nb)
		{
			if (nb % j == 0)
				return (nb);
			j++;
		}
		nb++;
	}
	return (0);
}

int	ft_find_next_prime(int nb)
{
	int	non_prime;
	int	j;

	if (nb <= 2)
		return (2);
	return (primecheck(nb));
}
