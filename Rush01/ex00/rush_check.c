/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jju <jju@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:44:34 by jju               #+#    #+#             */
/*   Updated: 2022/02/13 21:25:42 by jju              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	column_correct_check(char **board)
{
	int		num[4];
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
			num[j++] = 0;
		j = 0;
		while (j < 4)
		{
			num[board[j++][i] - 49] = 1;
		}
		j = 0;
		while (j < 4)
		{
			if (num[j++] == 0)
				return (0);
		}
		i++;
	}
	return (1);
}

int	colup_check(char **board)
{
	int	floor;
	int	i;
	int	j;
	int	high;

	j = 0;
	while (j < 4)
	{
		i = 0;
		high = 0;
		floor = 0;
		while (i < 4)
		{
			if (board[i][j] > high)
			{
				high = board[i][j];
				floor++;
			}
			i++;
		}
		if (g_checkarray[0][j] != floor + 48)
			return (0);
		j++;
	}
	return (1);
}

int	coldown_check(char **array)
{
	int	floor;
	int	i;
	int	j;
	int	high;

	j = 0;
	while (j < 4)
	{
		i = 3;
		floor = 0;
		high = 0;
		while (i >= 0)
		{
			if (array[i][j] > high)
			{
				high = array[j][i];
				floor++;
			}
			i--;
		}	
		if (g_checkarray[1][j] != floor + 48)
			return (0);
		j++;
	}
	return (1);
}

int	rowright_check(char **array)
{
	int	floor;
	int	i;
	int	j;
	int	high;

	j = 0;
	while (j < 4)
	{
		floor = 0;
		high = 0;
		i = 3;
		while (i >= 0)
		{
			if (array[j][i] > high)
			{
				high = array[j][i];
				floor++;
			}
			i--;
		}
		if (g_checkarray[2][j] != floor + 48)
			return (0);
		j++;
	}
	return (1);
}

int	rowleft_check(char **array)
{
	int	floor;
	int	i;
	int	j;
	int	high;

	j = 0;
	while (j < 4)
	{
		i = 0;
		floor = 0;
		high = 0;
		while (i < 4)
		{
			if (array[j][i] > high)
			{
				high = array[j][i];
				floor++;
			}
			i++;
		}
		if (g_checkarray[3][j] != floor + 48)
			return (0);
		j++;
	}
	return (1);
}
