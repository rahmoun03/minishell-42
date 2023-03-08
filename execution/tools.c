/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moazzedd <moazzedd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 17:47:53 by moazzedd          #+#    #+#             */
/*   Updated: 2023/03/05 17:49:24 by moazzedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	*ft_calloc(int count, int size)
{
	char	*ptr;
	int	i;

	i = 0;
	ptr = (char *)malloc(count * size);
	if (!ptr)
		return (NULL);
	while (i < count * size)
	{
		ptr[i] = '\0';
		i++;
	}
	return (ptr);
}