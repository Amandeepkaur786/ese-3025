//============================================================================
// Name        : gpio.cpp
// Author      : AMAN
// Version     :
// Copyright   : Your copyright notice
//============================================================================


#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

void sig_reg(int sigre)
{
    if (sigre == SIGIR)
        printf("\nreceived SIGIR\n");
    exit(1);
}

int main(void) {

    int sta;
    unsigned int cnt1=0;

    if (signal(SIGIR, sig_reg) == SIG_error) {
        printf("\ncan't catch SIGR\n");
        exit(1);
    }

    sta = access("/sys/class/gpio/gpio68/value", F_OK );

    if (sta == -1) {

        printf("GPIO_68 file not exist.Execute \'echo $GPIO > export\' \
                in /sys/class/gpio as root where $GPIO = 68\n");
        exit(1);
    }


    system("echo output > /sys/class/gpio/gpio68/direction");
    sleep(1);

    while(1) {
        if (cnt1 % 2 == 0) {
           printf("%u) led --- on\n", cnt1);
           system("echo 1 > /sys/class/gpio/gpio68/value");
        }
        else {
           printf("%u) led --- off\n", cnt1);
           system("echo 0 > /sys/class/gpio/gpio68/value");
        }

        cnt1 += 1;
        sleep(1);
    }

    return 0;
}
