/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsohn <dsohn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 23:44:35 by dsohn             #+#    #+#             */
/*   Updated: 2020/10/15 14:16:56 by dsohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			bigint_setu64(t_bigint *target, t_ull value)
{
	if (value > 0xFFFFFFFF)
	{
		target->blocks[0] = value & 0xFFFFFFFF;
		target->blocks[1] = (value >> 32) & 0xFFFFFFFF;
		target->length = 2;
	}
	else if (value != 0)
	{
		target->blocks[0] = value & 0xFFFFFFFF;
		target->length = 1;
	}
	else
		target->length = 0;
}

void			bigint_setu32(t_bigint *target, t_ul value)
{
	if (value != 0)
	{
		target->blocks[0] = value;
		target->length = (value != 0);
	}
	else
		target->length = 0;
}

t_ul			bigint_getu32(t_bigint *target)
{
	return (target->length == 0 ? 0 : target->blocks[0]);
}
