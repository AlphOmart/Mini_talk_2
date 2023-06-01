/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_server.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwubneh <mwubneh@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:12:31 by mwubneh           #+#    #+#             */
/*   Updated: 2023/06/01 14:38:42 by mwubneh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

size_t	ft_strlen(char	*str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putpid(pid_t process_id)
{
	char	nbr;

	if (process_id < 10)
	{
		nbr = process_id + '0';
		write(1, &nbr, 1);
	}
	else
	{
		ft_putpid(process_id / 10);
		ft_putpid(process_id % 10);
	}
}
