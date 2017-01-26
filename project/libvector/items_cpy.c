/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   items_cpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 18:59:36 by nhuber            #+#    #+#             */
/*   Updated: 2016/06/30 19:01:52 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void	*items_cpy(void *dst, const void *src, int size)
{
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)dst;
	s2 = (unsigned char *)src;
	while (n--)
		*s1++ = *s2++;
	return (dst);
}
