/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jju <jju@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:23:16 by jju               #+#    #+#             */
/*   Updated: 2022/02/21 15:25:51 by jju              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <strlib.h>

char	*ft_strdup(const char *s)
{
	int	i;
	int	len;
	char	*temp;

	i = 0;
	len = 0;
	while(s[len])
		len++;
	temp = (char *)malloc(sizeof(char) * (len + 1));
	if (!(temp))
		return (NULL);
	while (s[i])
	{
		new_s[i] = s[i];
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}
