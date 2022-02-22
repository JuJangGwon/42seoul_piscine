/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jju <jju@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:26:14 by jju               #+#    #+#             */
/*   Updated: 2022/02/21 15:42:07 by jju              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int		count;
	int		*tab;

	count = 0;
	if (min >= max)
		return (0);
	if (! (tab = (int *)malloc((max - min) * sizeof(int))))
		return (0);
	while (count < max - min)
	{
		tab[count] = min + count;
		count++;
	}
	return (tab);
}
