#ifndef listposisi_H
#define listposisi_H

#include "tipe_bentukan.h"

/* Definisi list_posisi : */
/* list_posisi kosong : First(L) = Nil */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P) */
/* Elemen terakhir list_posisi : jika addressnya Last, maka Next(Last)=Nil */


void CreateEmpty_posisi (list_posisi *L);

address_posisi Alokasi_posisi (infotype_posisi X);
void Dealokasi_posisi (address_posisi *P);

void InsVFirst_posisi (list_posisi *L, infotype_posisi X);
void InsVLast_posisi (list_posisi *L, infotype_posisi X);

void InsertFirst_posisi (list_posisi *L, address_posisi P);
void InsertAfter_posisi (list_posisi *L, address_posisi P, address_posisi Prec);
void InsertLast_posisi (list_posisi *L, address_posisi P);


/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst_posisi (list_posisi *L, infotype_posisi *X);
void DelVLast_posisi (list_posisi *L, infotype_posisi *X);
void DelFirst_posisi (list_posisi *L, address_posisi *P);
void DelLast_posisi (list_posisi *L, address_posisi *P);
void DelAfter_posisi (list_posisi *L, address_posisi *Pdel, address_posisi Prec);
int NbElmt_posisi (list_posisi L);


#endif