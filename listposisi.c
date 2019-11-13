#include <stdio.h>
#include <stdlib.h>
#include "listposisi.h"

address Alokasi (infotype_posisi X)
{
    address P;

    P = (address) malloc (sizeof(ElmtList));

    if (P != Nil)
    {
        Info(P) = X;
        Next(P) = Nil;
        return P;
    }

    else
    {
        return Nil;
    }
}

void InsVLastposisi (list *L, infotype_posisi X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    address P;

    /* Algoritma */
    P = Alokasi(X);
    if (P != Nil) 
    {
      InsertLast(L,P);
    }
}