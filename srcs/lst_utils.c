/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 18:27:51 by taemkim           #+#    #+#             */
/*   Updated: 2021/03/24 18:44:21 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_lst(t_pf *lst)
{
	lst->buf_count = 0;
	lst->ret = 0;
	lst->width = 0;
	lst->preci = 0;
	lst->preci_width = 0;
	lst->preci_parse = 0;
	lst->conv = 0;
	lst->minus = 0;
	lst->zero = 0;
	lst->plus = 0;
	lst->space = 0;
	lst->sharp = 0;
	lst->len = 0;
	lst->sp_len = 0;
	lst->is_int = 0;
	lst->h_count = 0;
	lst->l_count = 0;
	lst->n = 0;
	lst->u = 0;
	lst->i = 0;
}

void	set_preci(t_pf *lst)
{
	lst->preci = 1;
	lst->preci_parse = 1;
	lst->preci_width = 0;
}

void	reset_flags(t_pf *lst)
{
	lst->width = 0;
	lst->preci = 0;
	lst->preci_width = 0;
	lst->preci_parse = 0;
	lst->conv = 0;
	lst->minus = 0;
	lst->zero = 0;
	lst->plus = 0;
	lst->space = 0;
	lst->sharp = 0;
	lst->len = 0;
	lst->sp_len = 0;
	lst->is_int = 0;
	lst->h_count = 0;
	lst->l_count = 0;
	lst->n = 0;
	lst->u = 0;
}
