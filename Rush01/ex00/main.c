/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jju <jju@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 14:51:31 by jju               #+#    #+#             */
/*   Updated: 2022/02/13 21:19:29 by jju              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>


static char		**g_checkarray;
void	init(char *inputarray);
void	casenumber(char **arr);
char	**CreateCheckArray(char *argv);
void	create(char **board, char **array);
int		dfss(int l, char **board, char **arr);
int		check(char **board);
void	ft_show(char **board);
void	freearray();
void	create(char **board, char **array);
char	*initArray(char *argv, int _num);
int		column_correct_check(char **board);
int		colup_check(char *colup_array, char **board);
int		coldown_check(char *coldown_array, char **array);
int		rowright_check(char *rowright_array, char **array);
int		rowleft_check(char *rowleft_array, char **array);

int	exceptioncheck(char **argv, char *inputarray)
{
	int		i;
	int		size;

	size = 0;
	i = 0;

	while (argv[1][i])
	{
		if (argv[1][i] >= '1' && argv[1][i] <= '4')
		{
			inputarray[size] = argv[1][i];
			size++;
		}
		i++;
	}
	if (size != 16)
		return (0);
	i = 0;
	return (1);
}

int	main(int argc, char **argv)
{
	char *inputarray;

	inputarray = (char *)malloc(1*17);
	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (exceptioncheck(argv, inputarray) == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	init(inputarray);
	return (0);
}
