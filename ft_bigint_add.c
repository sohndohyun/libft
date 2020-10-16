/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsohn <dsohn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 00:11:17 by dsohn             #+#    #+#             */
/*   Updated: 2020/10/15 14:16:35 by dsohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		adder(t_bigint *result, \
		const t_bigint *small, const t_bigint *large)
{
	int			i;
	t_ull		carry;
	t_ull		sum;

	i = 0;
	carry = 0;
	while (i < small->length)
	{
		sum = carry + (t_ull)large->blocks[i] + (t_ull)small->blocks[i];
		carry = sum >> 32;
		result->blocks[i++] = sum & 0xffffffff;
	}
	while (i < large->length)
	{
		sum = carry + (t_ull)large->blocks[i];
		carry = sum >> 32;
		result->blocks[i++] = sum & 0xffffffff;
	}
	if (carry != 0)
	{
		result->blocks[i] = 1;
		result->length = large->length + 1;
	}
	else
		result->length = large->length;
}

void			bigint_add(t_bigint *result, \
		const t_bigint *bi1, const t_bigint *bi2)
{
	if (bi1->length < bi2->length)
		adder(result, bi1, bi2);
	else
		adder(result, bi2, bi1);
}
