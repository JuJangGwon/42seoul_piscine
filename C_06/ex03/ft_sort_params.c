/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jju <jju@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:23:00 by jju               #+#    #+#             */
/*   Updated: 2022/02/17 11:42:06 by jju              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_argv(char **argv);

void	swap(char **x, int i)
{
	char	*temp;

	temp = x[i];
	x[i] = x[i + 1];
	x[i + 1] = temp;
}

int	compare(char *x, char *y)
{
	int	c;
	int	i;

	i = 0;
	while (x[i] && y[i])
	{
		c = x[i] - y[i];
		if (c > 0)
		{
			return (1);
		}
		else if (c < 0)
			return (0);
		i++;
	}
	if (x[i] && ! y[i])
		return (1);
	return (0);
}

void	a(char **argv, int argc)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc)
	{
		j = 1;
		while (j < argc - 1)
		{
			if (compare(argv[j], argv[j + 1]))
			{
				swap(argv, j);
			}
			j++;
		}
		i++;
	}
}

void	write_argv(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			write(1, &argv[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc < 2)
		return (0);
	a(argv, argc);
	write_argv(argv);
	return (0);
}
