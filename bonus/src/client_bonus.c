/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 22:17:06 by ccamargo          #+#    #+#             */
/*   Updated: 2022/09/26 22:46:12 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk_bonus.h>

static int	check_pid(char *pid)
{
	size_t	i;

	i = 0;
	while (pid[i])
	{
		if (ft_isdigit(pid[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

static void	send_message(int pid, char *msg)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = ft_strlen(msg) + 1;
	while (i < len)
	{
		j = 7;
		while (j > -1)
		{
			if ((msg[i] >> j) & 1)
			{
				kill(pid, SIGUSR2);
				usleep(BIT_DELAY);
			}
			else
			{
				kill(pid, SIGUSR1);
				usleep(BIT_DELAY);
			}
			j--;
		}
		i++;
	}
}

static void	got_signal(int sig_num)
{
	if (sig_num == SIGUSR1)
		ft_printf("ACK: Message delivered!\n");
}

int	main(int argc, char **argv)
{
	struct sigaction	action;

	action.sa_handler = got_signal;
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &action, NULL);
	if (argc != 3 || !check_pid(argv[1]))
	{
		ft_printf("Only two arguments are valid: A valid PID and a message \
to the server!\n");
		return (EXIT_FAILURE);
	}
	else
		send_message(ft_atoi(argv[1]), argv[2]);
	return (EXIT_SUCCESS);
}
