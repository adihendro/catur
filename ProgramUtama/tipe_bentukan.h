#ifndef type_H
#define type_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

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


//head listlinier
typedef piece infotype_list;

typedef struct tElmtlist *address_list;
typedef struct tElmtlist { 
	piece info;
	list_posisi gerakan;
	address_list next;
} ElmtList;

typedef struct {
	address_list First;
} list;



#include "boolean.h"
#include "..//List//listlinier.h"
#include "..//List//listposisi.h"
#include "..//Stack//stack.h"
#include "..//Queue//queue.h"

#define Nil_list NULL
#define Info(P) (P)->info
#define Gerakan(P) (P)->gerakan
#define Next(P) (P)->next
#define First(L) (L).First
#define Parent(L) (L).Parent


int i,j,k;

boolean go; //dipake di main.c masukkan command
papan board[10][10];

char* choice;
char choice2;
char command[100];

stack history, termakan;
list list_ada_putih, list_ada_hitam;
queue giliran;
int poin_putih, poin_hitam;
int turn; //berapa kali udh gerakan


//untuk cek skak
address_list K;
address_list P1;
int jml;
boolean iskak;

//asosiasi list dari list_ada_putih dan list_ada_hitam
list kawan, lawan; //list piece apa yg ada di papan 
list list_bisa_gerak;
int poin;
int jml_bs_grk;

boolean endgame; //untuk STALEMATE dan CHECKMATE
int status; //untuk STALEMATE dan CHECKMATE

// untuk menyimpan nama si putih dan hitam
char nama_putih[4];
char nama_hitam[4];
char nama[11][4]; //ada 10 nama, maks 20 karakter per nama
int skor[11];
char putih_1, putih_2, putih_3, hitam_1, hitam_2, hitam_3;

// nama_putih = (char *) malloc (sizeof(4 * char));
// nama_hitam = (char *) malloc (sizeof(4 * char));

void string2ByteArray(char* input, int* output);
void stringToInt(char* ascii_str,int* Ret);

#endif