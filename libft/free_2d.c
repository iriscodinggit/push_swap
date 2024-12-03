/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_2d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irlozano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 19:56:08 by irlozano          #+#    #+#             */
/*   Updated: 2024/09/08 19:56:14 by irlozano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	free_2d(char **arr)
{
	size_t	i;

	i = 0;
	while (arr && arr[i])
	{
		if (arr[i])
		{
			free(arr[i]);
			arr[i] = NULL;
		}
		i++;
	}
	free(arr);
	arr = NULL;
}