/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_def.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsohn <dsohn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 12:48:21 by dsohn             #+#    #+#             */
/*   Updated: 2020/10/15 14:19:49 by dsohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DEF_H
# define FT_DEF_H

# include <stddef.h>
# define BI_MAXBLOCK 35

typedef struct				s_list
{
	void					*content;
	struct s_list			*next;
}							t_list;

typedef unsigned long long	t_ull;
typedef unsigned long		t_ul;
typedef long long			t_ll;

typedef struct				s_bigint
{
	t_ul					length;
	t_ul					blocks[BI_MAXBLOCK];
}							t_bigint;

#endif
