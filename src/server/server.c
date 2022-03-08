/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbiczyk <kbiczyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:29:39 by kamilbiczyk       #+#    #+#             */
/*   Updated: 2022/03/08 16:07:42 by kbiczyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void handler(int num)
{   
    printf("dss");
    if(num == 30)
        printf("0");
    else
        printf("1");
}

int main(void)
{
    pid_t pid;

    pid = getpid();
    printf("Server Pid : %d\n", pid);
    signal(SIGUSR1, handler);
    signal(SIGUSR2, handler);
    while (1)
    {
        sleep(1);
    }
}
