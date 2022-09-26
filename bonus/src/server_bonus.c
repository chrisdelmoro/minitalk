/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 22:22:13 by ccamargo          #+#    #+#             */
/*   Updated: 2022/09/25 21:10:05 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk_bonus.h>

static void	fill_str(int bit, int pid)
{
	static int				i = 7;
	static unsigned char	c = 0;

	if (bit)
		c = c | (bit << i);
	i--;
	if (i == -1)
	{
		if (c == '\0')
		{
			write(1, "\n", 1);
			kill(pid, SIGUSR1);
		}
		else
			write(1, &c, 1);
		i = 7;
		c = 0;
	}
}

static void got_bit(int sig_num, siginfo_t *info, void *context)
{
	(void) context;
	if (sig_num == SIGUSR1)
		fill_str(0, info->si_pid);
	else if (sig_num == SIGUSR2)
		fill_str(1, info->si_pid);
}

int	main(void)
{
	struct sigaction	action;

	action.sa_sigaction = got_bit;
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	ft_printf("PID: %d\n", getpid());
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
