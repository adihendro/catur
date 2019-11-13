#ifndef listposisi_H
#define listposisi_H

#include <stdio.h>
#include "boolean.h"
#include "tipe_bentukan.h"

#define Nil NULL

typedef posisi infotype_posisi;

typedef struct tElmtlist *address;
typedef struct tElmtlist { 
	infotype_posisi info;
	address next;
} ElmtList;

typedef struct {
	address First;
} list;

/* Definisi list : */
/* list kosong : First(L) = Nil */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P) */
/* Elemen terakhir list : jika addressnya Last, maka Next(Last)=Nil */

#define Info(P) (P)->info
#define Next(P) (P)->next
#define First(L) (L).First

address Alokasi (infotype_posisi X);

void InsVLastposisi (list *L, infotype_posisi X);

#endif