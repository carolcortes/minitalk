/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cade-oli <cade-oli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:15:10 by cade-oli          #+#    #+#             */
/*   Updated: 2025/06/01 11:39:30 by cade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	send_message(pid_t pid, char *msg)
{
	while (*msg)
		send_char(pid, *msg++);
	send_char(pid, '\0');
	ft_printf(GREEN "Message fully sent to the Server [PID %d].\n" RESET, pid);
}

void	send_char(pid_t pid, unsigned char c)
{
	int	bit;

	bit = 8;
	while (bit--)
	{
		if ((c >> bit) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
	}
}

void	print_usage(void)
{
	ft_printf(CYAN "Usage: ./client <server_pid> <message>\n" RESET);
}

void	handle_error_args(int ac)
{
	if (ac == 3)
		return ;
	if (ac == 2)
		ft_printf(RED "Missing message to send.\n" RESET);
	else if (ac > 3)
		ft_printf(RED "Only one message can be sent at a time.\n" RESET);
	print_usage();
}
