/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 18:37:22 by taemkim           #+#    #+#             */
/*   Updated: 2020/11/29 16:15:29 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *source, int c)
{
	int	i;

	i = (int)ft_strlen(source) + 1;
	while (i--)
	{
		if (*(source + i) == (char)c)
			return ((char *)source + i);
	}
	return (0);
}
