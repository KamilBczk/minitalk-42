/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamilbiczyk <kamilbiczyk@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:29:39 by kamilbiczyk       #+#    #+#             */
/*   Updated: 2021/10/20 22:40:29 by kamilbiczyk      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void handler(int num)
{   
    if (num == 30)
        write(1, "0", 1);
    else if (num == 31)
        write(1, "1", 1);
    else
        printf("Error");
}

int main(void)
{
    int pid;
    struct sigaction sa;

    pid = getpid();
    sa.sa_handler = handler;
    printf("Pid : %d\n", pid);
    signal(SIGUSR1, handler);
    signal(SIGUSR2, handler);
    // sigaction(SIGUSR1, &sa, NULL);
    // sigaction(SIGUSR2, &sa, NULL);
    while (1)
    {
        
    }
}
