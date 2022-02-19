/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jju <jju@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 15:04:24 by jju               #+#    #+#             */
/*   Updated: 2022/02/15 15:09:20 by jju              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_show(char **board)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			write(1, &board[i][j], 1);
			if (j != 3)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	check(char **board)
{
	if (column_correct_check(board) == 0)
		return (0);
	if (colup_check(board) == 0)
		return (0);
    if (coldown_check(board) == 0)
		return (0);
    if (rowright_check(board) == 0)
		return (0);
    if (rowleft_check(board) == 0)
		return (0);
	return (1);
}

int	dfss(int l, char **board, char *used)
{
	int	i;

	i = 0;
	if (l == 4)
	{
		if (check(board) == 1)
		{
			ft_show(board);
			return (1);
		}
		return (0);
	}
	else
	{
		while (i < 24)
		{
			if (used[i] == 0)
			{
				board[l] = arr[i];
				used[i] = 1;
				if (dfss(used[24] + 1, board, used))
					return (1);
				used[i] = 0;
			}
			i++;
		}
		return (0);
	}
}

void	create(char **board, char **array, char **checkarray)
{
	int	i;
	char *used;
	
	i = 0;
	used = (char *)malloc(1*24);
	while (i < 24)
		used[i++] = 0;
	dfss(0, board, used);
}
