/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arahmoun <arahmoun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 18:34:32 by arahmoun          #+#    #+#             */
/*   Updated: 2023/03/05 18:34:33 by arahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	error_arg(void)
{
	printf("%splease dont use the arguments%s\n", RED, DEF);
	exit(1);
}

void    ft_error(void)
{
    printf("syntax error \n");
    exit(1);
}