/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irlozano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 16:32:39 by irlozano          #+#    #+#             */
/*   Updated: 2023/10/05 18:45:45 by irlozano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*new_str;
	size_t			i;
	unsigned int	unslen;

	if (!s)
		return (NULL);
	unslen = ft_strlen(s);
	if (start > unslen)
		return (ft_strdup(""));
	if (unslen - start < len)
		len = unslen - start;
	new_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_str[i] = *(s + start + i);
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
