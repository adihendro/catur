#ifndef fungsi_H
#define fungsi_H

#include "tipe_bentukan.h"


void start();
// void move(piece *board, stack *history, stack *termakan, int *poin_putih, int *poin_hitam, List *list_ada_putih, List *list_ada_hitam, Queue giliransiapa);
void PrintPapan(papan board[10][10]);

void ceksemuagerak(piece F, papan board[10][10]);

#endif