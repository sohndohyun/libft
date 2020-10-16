/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint_pow.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsohn <dsohn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 15:07:46 by dsohn             #+#    #+#             */
/*   Updated: 2020/10/16 16:49:15 by dsohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_ul g_power10[] = {
	1,
	10,
	100,
	1000,
	10000,
	100000,
	1000000,
	10000000,
};
static t_bigint g_bigpower10[] =
{
	{ 1, { 100000000 } },
	{ 2, { 0x6fc10000, 0x002386f2 } },
	{ 4, { 0x00000000, 0x85acef81, 0x2d6d415b, 0x000004ee, } },
	{ 7, { 0x00000000, 0x00000000, 0xbf6a1f01, 0x6e38ed64,
			0xdaa797ed, 0xe93ff9f4, 0x00184f03, } },
	{ 14, { 0x00000000, 0x00000000, 0x00000000, 0x00000000,
			0x2e953e01, 0x03df9909, 0x0f1538fd,
			0x2374e42f, 0xd3cff5ec, 0xc404dc08, 0xbccdb0da,
			0xa6337f19, 0xe91f2603, 0x0000024e, } },
	{ 27, { 0x00000000, 0x00000000, 0x00000000, 0x00000000,
			0x00000000, 0x00000000, 0x00000000,
			0x00000000, 0x982e7c01, 0xbed3875b, 0xd8d99f72,
			0x12152f87, 0x6bde50c6, 0xcf4a6e70,
			0xd595d80f, 0x26b2716e, 0xadc666b0, 0x1d153624,
			0x3c42d35a, 0x63ff540e, 0xcc5573c0,
			0x65f9ef17, 0x55bc28f2, 0x80dcc7f7, 0xf46eeddc,
			0x5fdcefce, 0x000553f7, } }
};

static void		bigint_swap(t_bigint **a, t_bigint **b)
{
	t_bigint *temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void			bigint_pow10(t_bigint *result, t_ul exponent)
{
	t_bigint	temp;
	t_bigint	temp2;
	t_bigint	*curtemp;
	t_bigint	*nexttemp;
	long		i;

	curtemp = &temp;
	nexttemp = &temp2;
	bigint_setu32(&temp, exponent & 7);
	exponent >>= 3;
	i = 0;
	while (exponent != 0)
	{
		if (exponent & 1)
		{
			bigint_multiply_bi(nexttemp, curtemp, &g_bigpower10[i]);
			bigint_swap(&curtemp, &nexttemp);
		}
		i++;
		exponent >>= 1;
	}
	bigint_dup(result, curtemp);
}

void			bigint_multiply_pow10(t_bigint *result, \
		const t_bigint *in, t_ull exponent)
{
	t_bigint	temp;
	t_bigint	temp2;
	t_bigint	*curtemp;
	t_bigint	*nexttemp;
	long		i;

	curtemp = &temp;
	nexttemp = &temp2;
	if (exponent & 7)
		bigint_multiply_bi(curtemp, in, &g_bigpower10[exponent & 7]);
	else
		bigint_dup(curtemp, in);
	exponent >>= 3;
	i = 0;
	while (exponent != 0)
	{
		if (exponent & 1)
		{
			bigint_multiply_bi(nexttemp, curtemp, &g_bigpower10[i]);
			bigint_swap(&curtemp, &nexttemp);
		}
		i++;
		exponent >>= 1;
	}
	bigint_dup(result, curtemp);
}

void			bigint_pow2(t_bigint *result, t_ul exponent)
{
	t_ul blockidx;
	t_ul bitidx;

	blockidx = exponent / 32;
	bitidx = 0;
	while (bitidx <= blockidx)
		result->blocks[bitidx++] = 0;
	result->length = blockidx + 1;
	bitidx = exponent % 32;
	result->blocks[blockidx] |= 1 << bitidx;
}
