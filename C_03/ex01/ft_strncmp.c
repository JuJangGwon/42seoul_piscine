/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jju <jju@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 21:32:58 by jju               #+#    #+#             */
/*   Updated: 2022/02/14 16:51:19 by jju              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	int				d;

	i = 0;
	while (s1[i] && s2[i] && i < n)
	{
		d = s1[i] - s2[i];
		if (d > 0)
			return (d);
		if (d < 0)
			return (d);
		i++;
	}
	if (i < n)
		return (s1[i] - s2[i]);
	return (0);
}
