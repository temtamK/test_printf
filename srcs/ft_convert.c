/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:47:02 by taemkim           #+#    #+#             */
/*   Updated: 2021/03/24 19:04:06 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conv_s(va_list arg, t_pf *lst)
{
	char	*format;
	char	*sp;

	if (lst->preci && lst->preci_width < 0)
		lst->preci_width = -lst->preci_width;
	if (!(format = va_arg(arg, char *)))
		format = ft_strdup_l("(null)", lst);
	else
		format = ft_strdup_l(format, lst);
	lst->len = ft_strlen(format);
	sp = ft_print_space(lst);
	ft_join_all(format, sp, lst);
}

void	ft_conv_c(va_list arg, t_pf *lst)
{
	char	*format;
	char	*sp;

	format = NULL;
	lst->len = 1;
	lst->conv == 'c' ? format = ft_c_to_str(va_arg(arg, int)) : 0;
	lst->conv == '%' ? format = ft_c_to_str('%') : 0;
	sp = ft_print_space(lst);
	ft_join_all(format, sp, lst);
}

void	ft_conv_n(va_list arg, t_pf *lst)
{
	long long int	*n;

	if (lst->l_count >= 2)
		n = (long long int *)va_arg(arg, long long int *);
	else if (lst->l_count == 1)
		n = (long long int *)va_arg(arg, long int *);
	else if (lst->h_count && ((lst->h_count % 2) == 0))
		n = (long long int *)((char *)va_arg(arg, int *));
	else if (lst->h_count && ((lst->h_count % 2) != 0))
		n = (long long int *)((short *)va_arg(arg, int *));
	else
		n = (long long int *)va_arg(arg, int *);
	if (!n)
		return ;
	*n = lst->ret;
}

void	ft_conv_x(va_list arg, t_pf *lst)
{
	char	*format;
	char	*sp;

	format = NULL;
	lst->is_int = 1;
	ft_size_u(arg, lst);
	lst->conv == 'x' ? format = ft_itoa_base(lst->u, "0123456789abcdef") : 0;
	lst->conv == 'X' ? format = ft_itoa_base(lst->u, "0123456789ABCEDF") : 0;
	lst->len = ft_strlen(format);
	format = ft_num_preci(format, lst);
	lst->len = ft_strlen(format);
	if (lst->u == 0 && lst->preci && lst->preci_width == 0 && !lst->width)
	{
		free(format);
		return ;
	}
	if (lst->u == 0 && lst->preci && lst->preci_width == 0)
	{
		free(format);
		format = ft_strdup(" ");
	}
	lst->sharp && lst->u ? lst->len += 2 : 0;
	sp = ft_print_space(lst);
	ft_join_all(format, sp, lst);
}

void	ft_conv_p(va_list arg, t_pf *lst)
{
	char	*format;
	char	*sp;

	lst->u = va_arg(arg, long unsigned);
	format = ft_itoa_base(lst->u, "0123456789abcdef");
	lst->preci ? lst->zero = 0 : 0;
	lst->len = ft_strlen(format);
	format = ft_num_preci(format, lst);
	lst->len = ft_strlen(format) + 2;
	if (lst->u == 0 && lst->preci && lst->preci_width == 0)
	{
		free(format);
		format = ft_strdup(" ");
		lst->len -= 1;
	}
	sp = ft_print_space(lst);
	ft_join_all(format, sp, lst);
}
