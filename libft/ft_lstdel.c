/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgonzale <bgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 19:46:31 by bgonzale          #+#    #+#             */
/*   Updated: 2019/02/17 19:08:58 by bgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*list;
	t_list	*next;

	list = *alst;
	while (list)
	{
		next = list->next;
		(*del)(list->content, list->content_size);
		free(list);
		list = next;
	}
	*alst = NULL;
}
