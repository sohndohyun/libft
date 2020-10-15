/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint_multiply_else.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsohn <dsohn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 20:19:52 by dsohn             #+#    #+#             */
/*   Updated: 2020/10/16 03:16:35 by dsohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	bigint_multiply_ul(t_bigint *result, const t_bigint *bi, t_ul ul)
{
	t_ul	carry;
	t_ull	mult;
	long	i;

	i = 0;
	carry = 0;
	while (i < bi->length)
	{
		mult = (t_ull)bi->blocks[i] * ul + carry;
		result->blocks[i++] = (t_ul)(mult & 0xffffffff);
		carry = mult >> 32;
	}
	if (carry != 0)
	{
		result->blocks[i] = carry;
		result->length = bi->length + 1;
	}
	else
		result->length = bi->length;
}

void	bigint_multiply_2(t_bigint *result)
{
	t_ul	carry;
	long	i;
	t_ul	cur;

	carry = 0;
	i = 0;
	while (i < result->length)
	{
		cur = result->blocks[i];
		result->blocks[i++] = (cur << 1) | carry;
		carry = cur >> 31;
	}
	if (carry != 0)
	{
		result->blocks[i] = carry;
		result->length++;
	}
}

void	bigint_multiply_10(t_bigint *result)
{
	t_ull	carry;
	t_ull	mult;
	long	i;

	carry = 0;
	i = 0;
	while (i < result->length)
	{
		mult = (t_ull)result->blocks[i] * 10 + carry;
		result->blocks[i++] = (t_ul)(mult & 0xffffffff);
		carry = mult >> 32;
	}
	if (carry != 0)
	{
		result->blocks[i] = (t_ul)carry;
		result->length++;
	}
}
