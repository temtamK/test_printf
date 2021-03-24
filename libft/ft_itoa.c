/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 04:45:40 by taemkim           #+#    #+#             */
/*   Updated: 2020/12/02 14:35:53 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*is_zero(char *str, int n)
{
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	return (str);
}

int		num_len(long long n)
{
	int	len;

	len = 0;
	if (n < 0)
		len++;
	if (n == 0)
	{
		len = 1;
		return (len);
	}
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*str;
	long long	num;
	int			len;

	num = n;
	len = num_len(num);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len--] = '\0';
	is_zero(str, num);
	if (num < 0)
	{
		str[0] = '-';
		num *= -1;
	}
	while (num > 0)
	{
		str[len] = '0' + (num % 10);
		num = num / 10;
		len--;
	}
	return (str);
}
