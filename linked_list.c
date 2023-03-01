#include "minishell.h"

t_all	*ft_lstnew(void)
{
	t_all	*new_list;

	new_list = (t_all *)malloc(sizeof(t_all));
	if (!new_list)
		return (NULL);
	new_list->text = NULL;
	new_list->cmd = NULL;
	new_list->command = NULL;
	new_list->rdr = NULL;
	new_list->next = NULL;
	return (new_list);
}

void	ft_lstadd_back(t_all **lst, t_all *new)
{
	t_all	*tmp;

	if (!*lst)
	{
		(*lst) = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}