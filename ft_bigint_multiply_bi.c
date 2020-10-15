/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint_multiply_bi.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsohn <dsohn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 15:12:36 by dsohn             #+#    #+#             */
/*   Updated: 2020/10/16 02:43:00 by dsohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		multiplier_bi(\
	t_bigint *result, const t_bigint *small, const t_bigint *large)
{
	long	i;
	long	j;
	t_ull	carry;
	t_ull	mult;

	i = -1;
	while (++i < small->length)
	{
		if (small->blocks[i] == 0)
			continue ;
		carry = 0;
		j = 0;
		while (1)
		{
			mult = result->blocks[j] + \
				large->blocks[j] * small->blocks[i] + carry;
			carry = mult >> 32;
			result->blocks[j] = mult & 0xffffffff;
			if (++j == large->length)
				break ;
		}
		result->blocks[j] = (t_ul)(carry & 0xffffffff);
	}
	if (result->length > 0 && result->blocks[result->length - 1] == 0)
		result->length--;
}

void			bigint_multiply_bi(\
	t_bigint *result, const t_bigint *bi1, const t_bigint *bi2)
{
	result->length = bi1->length + bi2->length;
	ft_bzero(result->blocks, sizeof(t_ul) * result->length);
	if (bi1->length < bi2->length)
		multiplier(result, bi1, bi2);
	else
		multiplier(result, bi2, bi1);
}
