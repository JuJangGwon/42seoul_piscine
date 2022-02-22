/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jju <jju@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:38:39 by jju               #+#    #+#             */
/*   Updated: 2022/02/17 11:42:42 by jju              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	j;

	if (argc < 2)
		return (0);
	while (argc > 1)
	{
		j = 0;
		while (argv[argc - 1][j])
			write(1, &argv[argc - 1][j++], 1);
		write(1, "\n", 1);
		argc--;
	}
	return (0);
}
