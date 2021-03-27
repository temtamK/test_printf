/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 17:23:23 by taemkim           #+#    #+#             */
/*   Updated: 2021/03/26 23:16:19 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_c_to_str(char c)
{
	char	*s;

	s = ft_calloc(2, sizeof(char));
	s[0] = c;
	s[1] = '\0';
	return (s);
}

size_t		num_count(long long int n)
{
	size_t		len;

	len = 0;
	if (!n)
		len++;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

size_t		num_count_base(long long int n, char *base)
{
	size_t			len;
	long long int	base_len;

	len = 1;
	base_len = ft_strlen(base);
	while (n >= base_len)
	{
		n = n / base_len;
		len++;
	}
	return (len);
}

char		*ft_uitoa(long long int n)
{
	char		*str;
	int			num_len;

	num_len = num_count(n);
	if (!(str = ft_calloc((num_len + 1), sizeof(char))))
		return (NULL);
	str[num_len] = '\0';
	while (num_len)
	{
		str[--num_len] = n % 10 + 48;
		n = n / 10;
	}
	return (str);
}

char		*ft_itoa_base(long long int n, char *base)
{
	char		*str;
	int			num_len;
	int			base_len;

	num_len = num_count_base(n, base);
	base_len = ft_strlen(base);
	if (!(str = ft_calloc((num_len + 1), sizeof(char))))
		return (NULL);
	str[num_len] = '\0';
	while (num_len)
	{
		str[--num_len] = base[n % base_len];
		n = n / base_len;
	}
	return (str);
}
