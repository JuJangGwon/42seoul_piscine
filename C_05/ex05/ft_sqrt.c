/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jju <jju@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:56:09 by jju               #+#    #+#             */
/*   Updated: 2022/02/16 10:16:12 by jju              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_sqrt(int nb)
{
	int	a;

	a = 1;
	if (nb < 1)
		return (0);
	while (a <= 46340)
	{
		if (a * a == nb)
			return (a);
		a++;
	}
	return (0);
}
