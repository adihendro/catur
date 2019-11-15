#ifndef fungsi_H
#define fungsi_H

#include "tipe_bentukan.h"


void start();
void PrintPapan(papan board[10][10]);

void move(papan *board, stack *history, stack *termakan, int *poin_putih, int *poin_hitam, list *list_ada_putih, list *list_ada_hitam, queue giliransiapa);

int cekbisagerak(piece F, papan board[10][10]);
void ceksemuagerak(piece F, papan board[10][10], list_posisi *L);

#endif