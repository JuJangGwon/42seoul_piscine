/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jju <jju@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 14:32:59 by jju               #+#    #+#             */
/*   Updated: 2022/02/20 15:21:15 by jju              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

void	write_num(char *c)
{
	int	j;

	j = 0;
	while (c[j])
		write(1, &c[j++], 1);
}

void set_one_to_nine(char c, char hashmap[][2][50], int _ten_to_nineteen);
void	fillstring(char *c, int size);
void	makeHashmap(char *buf, char hashmap[][2][50])
{
	int	i;
	int x;
	int z;
	int is_word;

	x = 0;
	i = 0;
	z = 0;
	is_word = 0;
	while (buf[i])
	{
		if (buf[i] == ':')
		{
			hashmap[x][is_word][z] = '\0';
			is_word = 1;
			z = 0;
		}
		else if (buf[i] == '\n')
		{
			hashmap[x][is_word][z] = '\0';
			is_word = 0;
			z = 0;
			x++;
		}
		else if ((buf[i] >= '0' && buf[i] <= '9') || (buf[i] >= 'a' && buf[i] <= 'z'))
		{
			hashmap[x][is_word][z++] = buf[i];
		}
		i++;
	}
}

void set_hundred(char c, char hashmap[][2][50])
{
	int	a;

	if (c == '0')
		return ;
	a = c - 48;

	write_num(hashmap[a][1]);
	write(1, " ", 1);
	write_num(hashmap[28][1]);
	write(1, " ", 1);
}

void set_twenty_to_ninety(char _1th, char _2th, char hashmap[][2][50])
{
	int a;
	int _ten_to_nineteen = 0;
	if (_1th >= '2')
	{
		a = _1th - 48 + 20 - 2;
		write_num(hashmap[a][1]);
		write(1, " ", 1);
	}
	else if (_1th == '1')
	{
		_ten_to_nineteen = 1;
	}
	else if (_1th == '2')
		_ten_to_nineteen = 1;
	set_one_to_nine(_2th, hashmap, _ten_to_nineteen);
}


void set_one_to_nine(char c, char hashmap[][2][50], int _ten_to_nineteen)
{
	int	a;
	
	if (!_ten_to_nineteen)
	{
		if (c >= '1')
		{
			a = c - 48;
			write_num(hashmap[a][1]);
		}
	}
	else if (_ten_to_nineteen == 2)
	{
		a = c - 48;
		write_num(hashmap[a][1]);
	}
	else
	{
		a = c - 48 + 10;
		write_num(hashmap[a][1]);
	}
	write(1, " ", 1);
}

void find_digit(char *c, int *size, int *digit)
{
	int _size;

	_size = 0;
	while (c[_size] >= '0' && c[_size] <= '9')
	{
		_size++;	
	}
	*size = _size;
	*digit = (*size) / 3;
	char d;
	d = *digit + 48;;
}

void	write_number(char hashmap[][2][50], char *c)
{
	int	j;
	int digit;
	int size;

	find_digit(c, &size, &digit);
	j = 0;
	while (digit > 1)
	{
		set_hundred(c[j], hashmap);
		set_twenty_to_ninety(c[j + 1], c[j + 2], hashmap);
		if (c[j] != '0' || c[j + 1] != '0' || c[j + 2] != '0')
			write_num(hashmap[27 + digit][1]);
		write(1, " ", 1);
		j = j + 3;
		digit--;
	}
	if (digit == 1)
	{
		set_hundred(c[j], hashmap);
		set_twenty_to_ninety(c[j + 1], c[j + 2], hashmap);
	}
}

void	show_hashmap(char hashmap[42][2][50])
{
	int	i;
	int	j;

	i = 0;
	while (i < 41)
	{
		j = 0;
		while (hashmap[i][0][j])
		{
			write(1, &hashmap[i][0][j++], 1);
		}
		write(1, "  ", 2);
		j = 0;
		while (hashmap[i][1][j])
		{
			write(1, &hashmap[i][1][j++], 1);
		}
		write(1, "\n", 1);
		i++;
	}
}
char	*stringcheck(char *c)
{
	char *temp_str;
	int	minus;
	int i;
	int size;

	size = 0;
	i = 0;
	minus = 0;
	while (c[i])
	{
		if (c[i] == '-')
			minus++;
		else if (c[i] >= '0' && c[i] <= '9')
		{
			temp_str[size++] = c[i];
		}
		i++;
	}
	if (size % 3 != 0)
		fillstring(temp_str, size);
	return temp_str;
}

void	fillstring(char *c, int size)
{
	int i;
	int j;

	j = 0;
	if (size % 3 == 1)
	{
		c[size + 3] = '\0';  
		while (size > 0)
		{
			c[size + 2 - 1] = c[size - 1];
			size--;
		}
		c[0] = '0';
		c[1] = '0';
	}
	if (size % 3 == 2)
	{	
		c[size + 2] = '\0';
		while (size > 0)
		{		
			c[size + 1 - 1] = c[size - 1];
			size--;
		}
		c[0] = '0';
	}
}

int main(int argc, char **argv)
{
	char buf[1000];
	char Hashmap[42][2][50];
	int	fd;
	char *array;

	argc = 0;
	if((fd = open("numbers.dict", O_RDWR)) == -1)
		return (0);
	read(fd, buf, 1000);
	makeHashmap(buf, Hashmap);
	array = stringcheck(argv[1]);
	write_number(Hashmap, array);
	close(fd);
	return (0);
}
