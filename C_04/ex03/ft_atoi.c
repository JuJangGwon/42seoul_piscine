/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jju <jju@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:12:30 by jju               #+#    #+#             */
/*   Updated: 2022/02/16 10:02:02 by jju              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	nums(char c, int *is_count, char *a, int *size)
{
	if (*is_count == 1)
	{
		if (c >= '0' && c <= '9')
		{
			a[*size] = c;
			*size = *size + 1;
			return (1);
		}
		else
			return (0);
	}
	return (1);
}

void	plusminus(char c, int *minus, int *is_count)
{
	if (c >= '0' && c <= '9')
	{
		*is_count = *is_count + 1;
	}
	if (c == '-')
		*minus = *minus + 1;
}

int	atoi(char *c, int size, int minus)
{
	int	sum;
	int	i;
	int	j;

	j = 0;
	sum = 0;
	i = 0;
	while (i < size)
	{
		sum = sum * 10;
		sum = sum + (c[i] - 48);
		i++;
	}
	if (minus % 2 == 1)
	{
		sum = sum * -1;
	}
	return (sum);
}

int	ft_atoi(char *str)
{
	char	a[11];
	int		is_count;
	int		minus;
	int		i;
	int		size;

	size = 0;
	is_count = 0;
	minus = 0;
	i = 0;
	while (str[i])
	{
		if (is_count == 0)
			plusminus(str[i], &minus, &is_count);
		if (! nums(str[i], &is_count, a, &size))
			break ;
		i++;
	}
	return (atoi(a, size, minus));
}
