/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jju <jju@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:44:46 by jju               #+#    #+#             */
/*   Updated: 2022/02/13 21:18:14 by jju              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	**CreateCheckArray(char *argv)
{
	char	temp_array[4][4];
	int		t;
	int		j;
;
	j = 0;
	while (j < 4)
	{
		t = 0;
		while (t < 4)
		{
			temp_array[j][t] = argv[j * 4 + t];
			t++;
		}
		j++;
	}
	return (temp_array);
}

void	casenumber(char **arr)
{
	*(arr) = "1234";
	*(arr + 1) = "1243";
	*(arr + 2) = "1342";
	*(arr + 3) = "1324";
	*(arr + 4) = "1423";
	*(arr + 5) = "1432";
	*(arr + 6) = "2134";
	*(arr + 7) = "2143";
	*(arr + 8) = "2314";
	*(arr + 9) = "2341";
	*(arr + 10) = "2413";
	*(arr + 11) = "2431";
	*(arr + 12) = "3124";
	*(arr + 13) = "3142";
	*(arr + 14) = "3214";
	*(arr + 15) = "3241";
	*(arr + 16) = "3412";
	*(arr + 17) = "3421";
	*(arr + 18) = "4123";
	*(arr + 19) = "4132";
	*(arr + 20) = "4231";
	*(arr + 21) = "4213";
	*(arr + 22) = "4312";
	*(arr + 23) = "4321";
}

void	init(char *inputarray)
{
	int		i;
	char	**array;
	char	**board;
	char	checkarray[4][4];
	i = 0;
	board = (char **)malloc(sizeof(char *) * 4);
	array = (char **)malloc(sizeof(char *) * 24);
	
	while (i < 4)
	{
		*(board + i) = (char *)malloc(sizeof(char *) * 4);
		*(array + i) = (char *)malloc(sizeof(char *) * 4);
		i++;
	}
	g_checkarray = CreateCheckArray(inputarray);
	casenumber(array);
	create(board, array);
}
