/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 18:42:36 by taemkim           #+#    #+#             */
/*   Updated: 2020/11/29 16:15:02 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*n_s;
	size_t		pst;

	n_s = (const char *)s;
	pst = -1;
	while (++pst < n)
		if (*(n_s + pst) == (char)c)
			return ((void *)n_s + pst);
	return (NULL);
}
