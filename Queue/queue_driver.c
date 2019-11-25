#include "queue.h"
#include "queue.c"
#include <stdio.h>

int main(){
    //fungsi queue.c yang kami gunakan dalam program ini adalah InfoTail, Add, dan createempty
    queue giliran;
    CreateEmpty_queue(&giliran,2);//mengosongkan circular queue. Hanya terdiri dari 2 giliran
    Add(&giliran, 1);
    Add(&giliran, 2);
    if (InfoTail(giliran) == 1) { //jika terakhir giliran 1, maka sekarang giliran 2
        Add(&giliran, 2);
        printf("giliran player 2");
    } else {
        Add(&giliran, 1);
        printf("giliran player 1");
    }
    return 0;
}