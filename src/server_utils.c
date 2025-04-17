/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cade-oli <cade-oli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 14:55:06 by cade-oli          #+#    #+#             */
/*   Updated: 2025/04/17 14:02:18 by cade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #define _POSIX_C_SOURCE 200809L
#include "../inc/minitalk.h"

void	print_banner(void)
{
	ft_printf(CYAN
		"███████╗███████╗██████╗ ██╗   ██╗███████╗██████╗ \n"
		"██╔════╝██╔════╝██╔══██╗██║   ██║██╔════╝██╔══██╗\n"
		"███████╗█████╗  ██████╔╝██║   ██║█████╗  ██████╔╝\n"
		"╚════██║██╔══╝  ██╔══██╗╚██╗ ██╔╝██╔══╝  ██╔══██╗\n"
		"███████║███████╗██║  ██║ ╚████╔╝ ███████╗██║  ██║\n"
		"╚══════╝╚══════╝╚═╝  ╚═╝  ╚═══╝  ╚══════╝╚═╝  ╚═╝\n"
		RESET);
	ft_printf(GREEN "\n🚀 minitalk Server started successfully!\n\n" RESET);
}

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static int				bit_count = 0;
	static unsigned char	current_char = 0;

	(void)context;
	if (signum == SIGUSR2)
		current_char |= (1 << (7 - bit_count));
	bit_count++;
	if (bit_count == 8)
	{
		if (current_char == '\0')
			ft_printf("\n");
		else
			ft_printf("%c", current_char);
		bit_count = 0;
		current_char = 0;
	}
	kill(info->si_pid, SIGUSR1);
}
