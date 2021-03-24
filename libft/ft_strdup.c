/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 18:40:03 by taemkim           #+#    #+#             */
/*   Updated: 2020/11/29 16:15:15 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		i;
	int		len;
	char	*n_str;

	len = 0;
	while (str[len])
		len++;
	n_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!(n_str))
		return (NULL);
	i = 0;
	while (str[i])
	{
		n_str[i] = str[i];
		i++;
	}
	n_str[i] = '\0';
	return (n_str);
}
