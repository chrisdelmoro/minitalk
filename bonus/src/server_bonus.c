/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 22:22:13 by ccamargo          #+#    #+#             */
/*   Updated: 2022/09/26 21:04:13 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk_bonus.h>

static void	fill_str(char c, int pid)
{
	char		*c_dup;
	static char	*msg = "";
	char		*tmp;

	tmp = msg;
	c_dup = ft_calloc(2, sizeof(char));
	c_dup[0] = c;
	msg = ft_strjoin(msg, c_dup);
	ft_freethis(&c_dup, NULL);
	if (c == '\0')
	{
		ft_printf("%s\n", msg);
		ft_freethis(&msg, "");
		kill(pid, SIGUSR1);
	}
	if (ft_strlen(tmp))
		ft_freethis(&tmp, NULL);
}

static void	encode_byte(int bit, int pid)
{
	static int	i = 7;
	static char	c = 0;

	if (bit)
		c = c | (bit << i);
	i--;
	if (i == -1)
	{
		fill_str(c, pid);
		i = 7;
		c = 0;
	}
}

static void	got_bit(int sig_num, siginfo_t *info, void *context)
{
	(void) context;
	if (sig_num == SIGUSR1)
		encode_byte(0, info->si_pid);
	else if (sig_num == SIGUSR2)
		encode_byte(1, info->si_pid);
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
