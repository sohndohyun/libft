/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsohn <dsohn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 22:59:53 by dsohn             #+#    #+#             */
/*   Updated: 2020/10/15 14:17:02 by dsohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bigint		*bigint_dup(t_bigint *target, const t_bigint *source)
{
	t_ul i;

	i = 0;
	while (i < source->length)
	{
		target->blocks[i] = source->blocks[i];
		i++;
	}
	return (target);
}

t_ul			bigint_getlength(t_bigint *target)
{
	return (target->length);
}

t_ul			bigint_getblock(t_bigint *target, t_ul index)
{
	return (target->blocks[index]);
}

void			bigint_setzero(t_bigint *target)
{
	target->length = 0;
}

int				bigint_iszero(t_bigint *target)
{
	return (target->length == 0);
}
