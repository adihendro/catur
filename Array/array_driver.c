#include "..//ProgramUtama//inisialisasi.c"
#include "print_papan.c"
#include "..//List//listlinier.c"
#include "..//Stack//stack.c"
#include "..//Queue//queue.c"
#include <stdio.h>

int main(){
    inisialisasi(); //mengisi list
    papan *board2[10][10];
    for(i=0;i<=10;i++){ //dilakukan agar parameternya pointer
        for(j=0;j<=10;j++){
            board2[i][j] = &board[i][j];
        }
    }
    updateboard(board2, list_ada_putih, list_ada_hitam); //mengisi board dengan isi list
    PrintPapan(board2); //fitur yang akan kita coba
    return 0;
}