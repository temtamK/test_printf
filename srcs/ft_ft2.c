/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 17:50:29 by taemkim           #+#    #+#             */
/*   Updated: 2021/03/29 21:14:40 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*itoa_printf(long long int n)
{
	char	*format;
	int		num_len;

	num_len = num_count(n);
	if (!(format = ft_calloc((num_len + 1), sizeof(char))))
		return (NULL);
	format[num_len] = '\0';
	while (num_len)
	{
		if (n < 0)
		{
			format[--num_len] = -(n % 10) + 48;
			n = n / 10;
			n = -n;
		}
		else
		{
			format[--num_len] = n % 10 + 48;
			n = n / 10;
		}
	}
	return (format);
}

int		atoi_printf(char *format, int *i)
{
	int		atoi;

	atoi = 0;
	while (ft_isdigit(format[*i]))
	{
		atoi = atoi * 10 + format[*i] - 48;
		(*i)++;
	}
	(*i)--;
	return (atoi);
}

char	*ft_strdup_l(char *format, t_pf *lst)
{
	char	*str;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(format);
	if (lst->preci && lst->preci_width < len)
		len = lst->preci_width;
	if (!(str = ft_calloc(len + 1, sizeof(char))))
		return (NULL);
	while (i < len)
	{
		str[i] = format[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_c_to_str(char c)
{
	char	*s;

	s = ft_calloc(2, sizeof(char));
	s[0] = c;
	s[1] = '\0';
	return (s);
}
