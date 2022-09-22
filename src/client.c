/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 22:17:06 by ccamargo          #+#    #+#             */
/*   Updated: 2022/09/21 22:28:22 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

int main(int argc, char **argv)
{
	if (argc != 3)
		ft_printf("Two arguments are necessary: The PID and message to the server!\n");
	else
		ft_printf("Segundo argumento: %s\n", argv[2]);
	return (0);
}
