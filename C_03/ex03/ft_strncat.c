/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jju <jju@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 21:41:53 by jju               #+#    #+#             */
/*   Updated: 2022/02/16 15:53:29 by jju              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	s_i;
	int				d_i;

	d_i = 0;
	s_i = 0;
	while (dest[d_i])
	{
		d_i++;
	}
	while (src[s_i] && s_i < nb)
	{
		dest[d_i++] = src[s_i++];
	}
	dest[d_i] = '\0';
	return (dest);
}
