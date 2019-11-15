#include "headerCekSemuaGerak.h"

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

void InsertFirst (List *L, address P)
{
    Next(P) = First(*L);
    First(*L) = P;
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertAfter (List *L, address P, address Prec)
{
    Next(P) = Next(Prec);
    Next(Prec) = P;
}
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */

void InsertLast (List *L, address P)
{
        address Last;
    
    /* Algoritma */
    Last = First(*L);
    if (First(*L) == Nil) {
      InsertFirst(L,P);
    } else {
      while (Next(Last) != Nil) {
        Last = Next(Last);
      }
      InsertAfter(L,P,Last);
    }
}

void InsVLastSquare (List *L, infotype_posisi X)
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

void AddPossibleMove (List*L, int row, int column) //menambahkan move yang mungkin ke list posisi
{
	infotype square;

	square.posisiR = row;
	square.posisiC = column;

	InsVLastSquare(&L,square);
}

void PrintSemuaPosisi (List L)
{
  ;
}