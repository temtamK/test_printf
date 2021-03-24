/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 23:57:19 by taemkim           #+#    #+#             */
/*   Updated: 2020/11/29 16:15:28 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned char	i;
	char			*new;

	i = 0;
	if (!s || !f)
		return (NULL);
	if (!(new = ft_strdup(s)))
		return (NULL);
	while (new[i])
	{
		new[i] = (*f)(i, new[i]);
		i++;
	}
	return (new);
}
