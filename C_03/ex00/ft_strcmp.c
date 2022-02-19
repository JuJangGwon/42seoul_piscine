/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jju <jju@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 21:16:59 by jju               #+#    #+#             */
/*   Updated: 2022/02/14 11:08:28 by jju              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	c;

	i = 0;
	while (s1[i] && s2[i])
	{
		c = s1[i] - s2[i];
		if (c > 0)
			return (c);
		if (c < 0)
			return (c);
		i++;
	}
	c = s1[i] - s2[i];
	if (s1[i] && !s2[i])
		return (c);
	else if (!s1[i] && s2[i])
		return (c);
	return (0);
}
