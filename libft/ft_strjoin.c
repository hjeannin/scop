/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeannin <hjeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 15:08:13 by hjeannin          #+#    #+#             */
/*   Updated: 2015/02/24 21:58:11 by hjeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strjoin(char const *s, char const *s2)
{
	char		*str;
	size_t		i;
	size_t		j;
	int			len;

	i = 0;
	j = 0;
	len = ft_strlen(s) + ft_strlen(s2);
	if (s == NULL || s2 == NULL)
		return (NULL);
	str = ft_strnew(len);
	while (s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}
