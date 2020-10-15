/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint_compare.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsohn <dsohn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 23:56:54 by dsohn             #+#    #+#             */
/*   Updated: 2020/10/15 14:15:47 by dsohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	bigint_compare(const t_bigint *bi1, const t_bigint *bi2)
{
	long i;

	if (bi1->length - bi2->length != 0)
		return (bi1->length - bi2->length);
	i = bi1->length - 1;
	while (i >= 0)
	{
		if (bi1->blocks[i] != bi2->blocks[i])
		{
			if (bi1->blocks[i] > bi2->blocks[i])
				return (1);
			else
				return (-1);
		}
		--i;
	}
	return (0);
}
