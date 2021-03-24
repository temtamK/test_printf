/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 18:42:08 by taemkim           #+#    #+#             */
/*   Updated: 2020/11/29 16:15:03 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*n_s1;
	unsigned char	*n_s2;
	size_t			pst;

	n_s1 = (unsigned char *)s1;
	n_s2 = (unsigned char *)s2;
	pst = -1;
	while (++pst < n && *(n_s1 + pst) == *(n_s2 + pst))
		;
	if (pst == n)
		return (0);
	return (*(n_s1 + pst) - *(n_s2 + pst));
}
