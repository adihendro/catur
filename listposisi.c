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
      InsertLast(L,P);
    }
}