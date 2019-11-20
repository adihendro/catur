#ifndef type_H
#define type_H

//tipe bentukan dasar
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



//head listlinier
typedef piece infotype_list;

typedef struct tElmtlist *address_list;
typedef struct tElmtlist { 
	piece info;
	address_list next;
} ElmtList;

typedef struct {
	address_list First;
} list;



//head listposisi
typedef posisi infotype_posisi;

typedef struct tElmtlist_posisi *address_posisi;
typedef struct tElmtlist_posisi { 
	posisi info;
	address_posisi next;
} ElmtList_posisi;

typedef struct {
	address_posisi First;
} list_posisi;



#include "boolean.h"
#include "listlinier.h"
#include "listposisi.h"
#include "stack.h"
#include "queue.h"

#define Nil_list NULL
#define Info(P) (P)->info
#define Next(P) (P)->next
#define First(L) (L).First
#define Parent(L) (L).Parent


int i,j,k;

boolean go;
papan board[10][10];

char* choice;
char command[100];

stack history, termakan;
list list_ada_putih, list_ada_hitam;
queue giliran;
int poin_putih, poin_hitam;


#endif