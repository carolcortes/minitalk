/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cade-oli <cade-oli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 13:54:13 by cade-oli          #+#    #+#             */
/*   Updated: 2025/06/01 11:38:32 by cade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #define _POSIX_C_SOURCE 200809L

#include "../inc/minitalk.h"

int	main(int ac, char **av)
{
	pid_t	server_pid;

	if (ac != 3)
	{
		handle_error_args(ac);
		return (EXIT_FAILURE);
	}
	server_pid = ft_atoi(av[1]);
	if (kill(server_pid, 0) == -1)
	{
		ft_printf(RED "Server's PID not found\n" RESET);
		exit(EXIT_FAILURE);
	}
	send_message(server_pid, av[2]);
	return (EXIT_SUCCESS);
}
