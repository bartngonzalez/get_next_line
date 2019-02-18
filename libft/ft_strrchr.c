/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgonzale <bgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 19:53:55 by bgonzale          #+#    #+#             */
/*   Updated: 2019/02/17 19:11:18 by bgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_strrchr(const char *s, int c)
{
	char	ch;
	int		i;
	int		j;

	ch = (char)c;
	i = 0;
	j = -1;
	while (s[i])
	{
		if (s[i] == ch)
			j = i;
		i++;
	}
	if (s[i] == ch)
		return ((char *)(s + i));
	return (j < 0 ? (NULL) : ((char *)(s + j)));
}
