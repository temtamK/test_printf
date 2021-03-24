/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 18:40:23 by taemkim           #+#    #+#             */
/*   Updated: 2020/11/29 16:15:13 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *source, int c)
{
	char	chr;
	int		i;

	chr = (unsigned char)c;
	i = 0;
	while (source[i] != '\0')
	{
		if (source[i] == chr)
			return ((char *)source + i);
		i++;
	}
	if (source[i] == chr)
		return ((char *)source + i);
	return (0);
}
