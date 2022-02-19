/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jju <jju@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 11:25:28 by jju               #+#    #+#             */
/*   Updated: 2022/02/14 17:46:29 by jju              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	de_size;
	unsigned int	i;
	unsigned int	src_size;

	de_size = 0;
	i = 0;
	src_size = 0;
	while (dest[de_size])
		de_size++;
	while (src[src_size])
		src_size++;
	if (de_size >= size)
		return (src_size + size);
	while (src[i] && (i + de_size + 1 < size))
	{
		dest[de_size + i] = src[i];
		i++;
	}
	dest[de_size + i] = '\0';
	return (src_size + de_size);
}
