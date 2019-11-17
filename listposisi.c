#include <stdio.h>
#include <stdlib.h>
#include "listposisi.h"

void CreateEmpty_posisi (list_posisi *L)
{
    First(*L) = Nil_list;
}

address_posisi Alokasi_posisi (infotype_posisi X)
{
    address_posisi P;

    P = (address_posisi) malloc (sizeof(ElmtList));

    if (P != Nil_list)
    {
        Info(P) = X;
        Next(P) = Nil_list;
        return P;
    }

    else
    {
        return Nil_list;
    }
}

void InsVLast_posisi (list_posisi *L, infotype_posisi X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    address_posisi P;

    /* Algoritma */
    P = Alokasi_posisi(X);
    if (P != Nil_list) 
    {
      InsertLast_posisi(L,P);
    }
}


/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst_posisi (list_posisi *L, address_posisi P)
{
    Next(P) = First(*L);
    First(*L) = P;
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address_posisi P sebagai elemen pertama */
void InsertAfter_posisi (list_posisi *L, address_posisi P, address_posisi Prec)
{
    Next(P) = Next(Prec);
    Next(Prec) = P;
}
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertLast_posisi (list_posisi *L, address_posisi P)
{
    address_posisi Last;
    
    /* Algoritma */
    Last = First(*L);
    if (First(*L) == Nil_list) {
      InsertFirst_posisi(L,P);
    } else {
      while (Next(Last) != Nil_list) {
        Last = Next(Last);
      }
      InsertAfter_posisi(L,P,Last);
    }
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */