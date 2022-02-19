/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jju <jju@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:02:24 by jju               #+#    #+#             */
/*   Updated: 2022/02/10 14:52:51 by jju              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	_if_first_btrue(char *str, int *first_b, int i)
{
	if (str[i] >= 'a' && str[i] <= 'z')
	{
		*first_b = 1;
		str[i] = str[i] - 'a' + 'A';
	}
	else if (str[i] >= '0' && str[i] <= '9')
	{
		*first_b = 1;
	}
	else if (str[i] >= 'A' && str[i] <= 'Z')
	{
		*first_b = 1;
	}
}

char	*ft_strcapitalize(char *str)
{
	int	first_b;
	int	i;

	i = 0;
	first_b = 0;
	while (str[i])
	{
		if (first_b == 0)
			_if_first_btrue(str, &first_b, i);
		else
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
				str[i] = str[i] - 'A' + 'a';
			else if (! (str[i] >= '0' && str[i] <= '9'))
				if (! (str[i] >= 'a' && str[i] <= 'z'))
					first_b = 0;
		}
		i++;
	}
	return (str);
}
