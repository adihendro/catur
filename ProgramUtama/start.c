#include "tipe_bentukan.h"


void delay(int milliseconds){
    long pause;
    clock_t now,then;

    pause = milliseconds*(CLOCKS_PER_SEC/1000);
    now = then = clock();
    while((now-then) < pause)
        now = clock();
}


void start(int *pilihan_user) {
    system("clear");

    printf("\033[1;33m");
    printf("********************************************************************************\n");
    printf("********************************************************************************\n");
    printf("**                                                                            **\n");
    printf("**                                                                            **\n");
    printf("**\033[1;31m               ccccc    hh    hh    eeeeee    ssssss   ssssss               \033[1;33m**\n");
    printf("**\033[1;31m              cc        hh    hh    ee        ss       ss                   \033[1;33m**\n");
    printf("**\033[1;31m             cc         hhhhhhhh    eeeeee    ssssss   ssssss               \033[1;33m**\n");
    printf("**\033[0m              cc        hh    hh    ee            ss       ss               \033[1;33m**\n");
    printf("**\033[0m               ccccc    hh    hh    eeeeee    ssssss   ssssss               \033[1;33m**\n");
    printf("**                                                                            **\n");
    printf("**                                                                            **\n");
    printf("**                                                                            **\n");
    printf("**                                 Let's Play                                 **\n");
    printf("**                                                                            **\n");
    printf("**                                 1. New Game                                **\n");
    printf("**                                 2. Load Game                               **\n");
    printf("**                                 3. Leaderboard                             **\n");
    printf("**                                                                            **\n");
    printf("**                                                                            **\n");
    printf("********************************************************************************\n");
    printf("********************************************************************************\n");
    printf("\033[0m");

    printf("\033[1;36m");
    printf("\n");
    delay(1000);
    printf("                                  Choose Wisely\n");
    delay(1000);
    printf("                                      1/2/3\n\n");
    delay(1000);
    printf("\033[0m");

    
    //printing
    int X;
    do{    
        choice = (char*) malloc (sizeof(100));
        printf("Your choice: ");
        scanf("%s",choice);
        stringToInt(choice,&X);
        if(!(X==49 || X==50 || X==51))//49 adalah ascii untuk 1, 50 = 2, 51 = 3
            printf("Wrong input! It's must be a number from 1-3!\n\n");
    } while(!(X==49 || X==50 || X==51));
    *pilihan_user = X;
}
