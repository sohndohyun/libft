/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsohn <dsohn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 11:25:32 by dsohn             #+#    #+#             */
/*   Updated: 2020/09/28 11:40:22 by dsohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*memset(void *s, int o, size_t n)
{
	unsigned char *temp;

	temp = s;
	while (n-- > 0)
	{
		*temp = (unsigned char)o;
		temp++;
	}
	return (s);
}
