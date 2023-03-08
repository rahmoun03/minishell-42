/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arahmoun <arahmoun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 18:34:01 by arahmoun          #+#    #+#             */
/*   Updated: 2023/03/05 18:34:02 by arahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return i;
}

void	ft_strcpy(char *dst, char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

char	*ft_strdup(const char *s1)
{
	char	*re;
	int	size;

	size = ft_strlen((char *)s1);
	re = (char *)malloc(size + 1);
	if (!re)
		return (0);
	ft_strcpy(re, (char *)s1);
	return (re);
}

char **ft_ddup(char **str)
{
	char **ret;
	int i;

	i = 0;
	ret = NULL;
	while (str[i])
		i++;
	ret = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (str[i])
	{
		ret[i] = ft_strdup(str[i]);
		i++;
	}
	ret[i] = NULL;
	return (ret);
}