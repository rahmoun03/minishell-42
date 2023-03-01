/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moazzedd <moazzedd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:36:13 by moazzedd          #+#    #+#             */
/*   Updated: 2023/03/01 21:20:50 by moazzedd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_init(t_var *vars)
{
    vars->j = 0;
    vars->x = 0;
}

void    skip(t_var *vars, t_all *tmp)
{
    if (tmp->cmd[vars->i][vars->j] == 39 || tmp->cmd[vars->i][vars->j] == 34)
    {
        vars->j++;
        tmp->cmd[vars->i][vars->x] = tmp->cmd[vars->i][vars->j];
        while (tmp->cmd[vars->i][vars->j] != 34 && tmp->cmd[vars->i][vars->j] != 39)
        {
            tmp->cmd[vars->i][vars->x] = tmp->cmd[vars->i][vars->j];
            vars->x++;
            vars->j++;
        }
        vars->j++;
        tmp->cmd[vars->i][vars->x] = tmp->cmd[vars->i][vars->j];
    }
}

void    remove_dq(t_all *tmp)
{
    t_var   vars;

    vars.temp = tmp;
    vars.j = 0;
    vars.i = 0;
    vars.x = 0;
    while (tmp)
    {
        while (tmp->cmd[vars.i])
        {
            while (tmp->cmd[vars.i][vars.j])
            {
                skip(&vars, tmp);
                vars.j++;
                vars.x++;
                tmp->cmd[vars.i][vars.x] = tmp->cmd[vars.i][vars.j];
            }
            vars.i++;
            ft_init(&vars);
        }
        vars.i = 0;
        tmp = tmp->next;
        ft_init(&vars);
    }
    // vars.i = 0;
    // while (vars.temp)
    // {
    //     while (vars.temp->cmd[vars.i])
    //     {
    //         printf("%s\n",vars.temp->cmd[vars.i]);
    //         vars.i++;
    //     }
    //     vars.temp = vars.temp->next;
    //     vars.i = 0;
    // }
    // exit(1);
}