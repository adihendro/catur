#include <stdio.h>
#include <time.h>
#include "tipe_bentukan.h"

void delay(int milliseconds){
    long pause;
    clock_t now,then;

    pause = milliseconds*(CLOCKS_PER_SEC/1000);
    now = then = clock();
    while( (now-then) < pause )
        now = clock();
}

void inisialisasi(){
    piece bidak;
    bidak.nama='p';
    bidak.player=1;
    bidak.poin=1;
    bidak.posisiR=7;
    bidak.posisiC=2;

    InsVFirst(&list_ada_putih,bidak);
}

void start() {
    inisialisasi();
    
    printf("********************************************************************************\n");
    printf("********************************************************************************\n");
    printf("**                                                                            **\n");
    printf("**                                                                            **\n");
    printf("**               ccccc    hh    hh    eeeeee    ssssss   ssssss               **\n");
    printf("**              cc        hh    hh    ee        ss       ss                   **\n");
    printf("**             cc         hhhhhhhh    eeeeee    ssssss   ssssss               **\n");
    printf("**              cc        hh    hh    ee            ss       ss               **\n");
    printf("**               ccccc    hh    hh    eeeeee    ssssss   ssssss               **\n");
    printf("**                                                                            **\n");
    printf("**                                                                            **\n");
    printf("**                                                                            **\n");
    printf("**                                 Let's Play                                 **\n");
    printf("**                                                                            **\n");
    printf("**                                 1. New Game                                **\n");
    printf("**                                 2. Load Game                               **\n");
    printf("**                                 3. Leaderboard                             **\n");
    printf("**                                                                            **\n");
    printf("********************************************************************************\n");
    printf("********************************************************************************\n");
    printf("\n");
    // delay(1000);
    printf("                                  Choose Wisely\n\n");
    // delay(1000);
    printf("                                      1/2/3\n\n");
    // delay(1000);
}
