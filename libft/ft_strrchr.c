/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irlozano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:42:34 by irlozano          #+#    #+#             */
/*   Updated: 2023/10/01 14:48:26 by irlozano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdio.h>
#include <stdlib.h>

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*res;

	res = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			res = (char *) &s[i];
		i++;
	}
	if (s[i] == (char)c)
		res = (char *) &s[i];
	return (res);
}
