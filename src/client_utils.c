/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cade-oli <cade-oli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:15:10 by cade-oli          #+#    #+#             */
/*   Updated: 2025/04/13 17:57:58 by cade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	send_message(pid_t pid, char *msg)
{
	while (*msg)
		send_char(pid, *msg++);
	send_char(pid, '\0');
	ft_printf(GREEN "Message received by the Server %d.\n" RESET, pid);
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
		pause();
	}
}

void	ack_handler(int signum)
{
	(void)signum;
}

void	print_usage(void)
{
	ft_printf("Usage: ./client <server_pid> <message>\n");
}

void	handle_error_args(int ac)
{
	if (ac == 3)
		return ;
	if (ac == 2)
		ft_printf("Missing message to send.\n");
	else if (ac > 3)
		ft_printf("Only one message can be sent at a time.\n");
	print_usage();
}
