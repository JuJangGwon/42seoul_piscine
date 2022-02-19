/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jju <jju@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:02:53 by jju               #+#    #+#             */
/*   Updated: 2022/02/16 10:16:49 by jju              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_is_prime(int nb)
{
	int	j;

	j = 2;
	if (nb < 2)
	{
		return (0);
	}
	while (j < nb)
	{
		if (nb % j == 0)
		{
			return (0);
		}
		j++;
	}
	return (1);
}
