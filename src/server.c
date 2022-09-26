/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 22:22:13 by ccamargo          #+#    #+#             */
/*   Updated: 2022/09/26 19:19:33 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

static void	fill_str(int bit)
{
	static int	i = 7;
	static char	c = 0;
	static char	*msg = "";
	char		*tmp;

	if (bit)
		c = c | (bit << i);
	i--;
	if (i == -1)
	{
		tmp = msg;
		msg = ft_strjoin(msg, &c);
		if (ft_strlen(tmp))
			ft_freethis(&tmp, NULL);
		if (c == '\0')
		{
			ft_printf("%s\n", msg);
			ft_freethis(&msg, "");
		}
		i = 7;
		c = 0;
	}
}

static void	got_bit(int sig_num)
{
	if (sig_num == SIGUSR1)
		fill_str(0);
	else if (sig_num == SIGUSR2)
		fill_str(1);
}

int	main(void)
{
	struct sigaction	action;

	action.sa_handler = got_bit;
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	ft_printf("PID: %d\n", getpid());
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
