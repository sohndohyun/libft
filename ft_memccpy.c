/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsohn <dsohn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 12:11:26 by dsohn             #+#    #+#             */
/*   Updated: 2020/09/28 12:30:47 by dsohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	unsigned char	ch;

	d = (unsigned char*)dest;
	s = (unsigned char*)src;
	ch = (unsigned char)c;
	while (n-- > 0)
	{
		*d = *s;
		if ((*d++ == ch)
			return (d);
		s++;
	}
	return (0);
}
