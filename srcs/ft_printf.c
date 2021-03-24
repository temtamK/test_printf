/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:55:17 by taemkim           #+#    #+#             */
/*   Updated: 2021/03/24 18:43:03 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_buf(t_pf *lst)
{
	write(1, lst->buf, lst->buf_count);
	lst->buf_count = 0;
}

void	put_buf(t_pf *lst, char *format, int len)
{
	int		i;

	i = 0;
	lst->ret += len;
	while (i < len)
	{
		lst->buf[lst->buf_count] = format[i];
		lst->buf_count++;
		if (lst->buf_count == BUFFER_SIZE)
			print_buf(lst);
		i++;
	}
}

void	print_not_spec(t_pf *lst, char *format)
{
	int		len;

	len = 0;
	while (format[lst->i] && format[lst->i] != '%')
	{
		lst->buf[lst->buf_count] = format[lst->i];
		lst->buf_count++;
		len++;
		if (lst->buf_count == BUFFER_SIZE)
			print_buf(lst);
		lst->i++;
	}
	lst->ret += len;
	lst->i--;
}

int		ft_printf(const char *format, ...)
{
	t_pf	lst;
	va_list	arg;

	init_lst(&lst);
	va_start(arg, format);
	while (format[lst.i])
	{
		if (format[lst.i] == '%')
		{
			if (format[lst.i + 1] == '\0')
				break ;
			if (is_signal(format[lst.i + 1]))
				ft_parse((char *)format, arg, &lst);
		}
		else
			print_not_spec(&lst, (char *)format);
		lst.i++;
	}
	va_end(arg);
	print_buf(&lst);
	return (lst.ret);
}
