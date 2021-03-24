/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 18:41:46 by taemkim           #+#    #+#             */
/*   Updated: 2020/11/29 16:15:04 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*n_dest;
	unsigned char	*n_src;
	size_t			position;

	if (!dest && !src)
		return (0);
	position = -1;
	n_dest = dest;
	n_src = (unsigned char *)src;
	while (++position < n)
		*(n_dest + position) = *(n_src + position);
	return (dest);
}
