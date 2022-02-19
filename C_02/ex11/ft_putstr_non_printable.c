/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jju <jju@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 19:57:46 by jju               #+#    #+#             */
/*   Updated: 2022/02/10 10:54:35 by jju              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	change(unsigned char str)
{
	char	*_16;
	int		i;

	_16 = "0123456789abcdef";
	i = str;
	if (str < 16)
	{
		write(1, "0", 1);
		write(1, &_16[i % 16], 1);
	}
	else
	{
		write(1, &_16[i / 16], 1);
		write(1, &_16[i % 16], 1);
	}
}

void	ft_putstr_non_printable(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 33 && str[i] <= 126)
		{
			write(1, &str[i], 1);
		}
		else if (str[i] == ' ')
			write(1, " ", 1);
		else
		{
			write(1, "\\", 1);
			change(str[i]);
		}
		i++;
	}
}
