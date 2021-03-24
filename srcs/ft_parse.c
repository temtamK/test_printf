/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:12:27 by taemkim           #+#    #+#             */
/*   Updated: 2021/03/24 18:52:50 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	is_flag(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'n' || c == 'X' || c == '%');
}

size_t	is_signal(char c)
{
	return (is_flag(c) || ft_isdigit(c)
	|| c == '-' || c == ' ' || c == '.' || c == '+' || c == '#' || c == '*'
	|| c == 'l' || c == 'h');
}

void	check_flag(char *format, va_list arg, t_pf *lst)
{
	if (format[lst->i] == '*')
	{
		if (lst->preci_parse)
			lst->preci_width = va_arg(arg, int);
		else
			lst->width = va_arg(arg, int);
	}
	if (format[lst->i] == '0' && !lst->minus && !lst->preci_parse)
		lst->zero = 1;
	if (format[lst->i] > '0' && format[lst->i] <= '9' && !lst->preci_parse)
		lst->width = ft_atoi_printf(format, &lst->i);
	if (ft_isdigit(format[lst->i]) && lst->preci_parse)
		lst->preci_width = ft_atoi_printf(format, &lst->i);
	lst->preci_parse = 0;
	if (format[lst->i] == '-')
	{
		lst->zero = 0;
		lst->minus = 1;
	}
	format[lst->i] == '.' ? set_preci(lst) : 0;
	format[lst->i] == ' ' ? lst->space = 1 : 0;
	format[lst->i] == '+' ? lst->plus = 1 : 0;
	format[lst->i] == '#' ? lst->sharp = 1 : 0;
	format[lst->i] == 'l' ? lst->l_count += 1 : 0;
	format[lst->i] == 'h' ? lst->h_count += 1 : 0;
}

int		ft_parse2(char *format, va_list arg, t_pf *lst)
{
	char	*sp;
	char	*c;

	while (!is_flag(format[lst->i]))
	{
		check_flag(format, arg, lst);
		if (format[lst->i + 1] == '\0')
			return (0);
		if (!is_signal(format[lst->i + 1]))
		{
			c = ft_c_to_str(format[lst->i + 1]);
			lst->len = 1;
			lst->minus ? put_buf(lst, c, 1) : 0;
			sp = ft_print_space(lst);
			put_buf(lst, sp, lst->sp_len);
			!lst->minus ? put_buf(lst, c, 1) : 0;
			free(c);
			free(sp);
			lst->i++;
			return (0);
		}
		lst->i++;
	}
	return (1);
}

void		ft_parse(char *format, va_list arg, t_pf *lst)
{
	lst->i++;
	reset_flags(lst);
	if (!ft_parse2(format, arg, lst))
		return ;
	if (lst->width < 0)
	{
		lst->minus = 1;
		lst->zero = 0;
		lst->width = -lst->width;
	}
	if (lst->preci_width < 0)
		lst->preci = 0;
	lst->preci && lst->preci_width >= 0 ? lst->zero = 0 : 0;
	lst->conv = format[lst->i];
	format[lst->i] == 'c' ? ft_conv_c(arg, lst) : 0;
	format[lst->i] == 's' ? ft_conv_s(arg, lst) : 0;
	format[lst->i] == 'p' ? ft_conv_p(arg, lst) : 0;
	format[lst->i] == 'd' || format[lst->i] == 'i' ? ft_conv_d(arg, lst) : 0;
	format[lst->i] == 'u' ? ft_conv_u(arg, lst) : 0;
	format[lst->i] == 'x' ? ft_conv_x(arg, lst) : 0;
	format[lst->i] == 'X' ? ft_conv_x(arg, lst) : 0;
	format[lst->i] == '%' ? ft_conv_c(arg, lst) : 0;
	format[lst->i] == 'n' ? ft_conv_n(arg, lst) : 0;
}
