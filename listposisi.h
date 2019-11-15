#ifndef listposisi_H
#define listposisi_H

#include <stdio.h>
#include "boolean.h"
#include "tipe_bentukan.h"

/* Definisi list_posisi : */
/* list_posisi kosong : First(L) = Nil */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P) */
/* Elemen terakhir list_posisi : jika addressnya Last, maka Next(Last)=Nil */


#define Parent(P) (P)->info

void CreateEmpty_posisi (list_posisi *L);

address_posisi Alokasi_posisi (infotype_posisi X);

void InsVLast_posisi (list_posisi *L, infotype_posisi X);

#endif