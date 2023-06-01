/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwubneh <mwubneh@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:13:32 by mwubneh           #+#    #+#             */
/*   Updated: 2023/06/01 14:38:12 by mwubneh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include<unistd.h>
# include<signal.h>
# include<stdlib.h>

size_t	ft_strlen(char	*str);
void	ft_putpid(pid_t process_id);

#endif
