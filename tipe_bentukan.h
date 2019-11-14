#ifndef type_H
#define type_H


typedef struct {
			char nama;
			int player;
			int poin;
			int posisiR;
			int posisiC;
		} piece;

typedef struct {
			char nama;
			int player;
		} papan;

typedef struct {
			int posisiR;
			int posisiC;
		} posisi;


#include "listlinier.h"
#include "listposisi.h"
#include "stack.h"
#include "queue.h"



int i,j,k;
int poin_putih=0, poin_hitam=0;

piece F;
papan board[10][10];
char command[12];

stack history, termakan;
list list_ada_putih, list_ada_hitam;
queue giliransiapa;


#endif