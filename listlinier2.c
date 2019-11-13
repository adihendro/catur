#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L)
{
    return First(L) == Nil;
}
/* Mengirim true jika list kosong */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L)
{
    First(*L) = Nil;
}

/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** Manajemen Memori ******************/
address Alokasi (infotype X)
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
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */

void Dealokasi (address *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
    free(*P);
}


/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
    address P;

    P = Alokasi(X);
    if(P!=Nil)
    {
        InsertFirst(L,P);
    }
}

void InsVLast (List *L, infotype X)
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

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
    address P;

    /* Algoritma */
    P = First(*L);
    (*X) = Info(P);
    First(*L) = Next(First(*L));
    Next(P) = Nil;
    Dealokasi(&P);
}

void DelVLast (List *L, infotype *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
    address P;

    /* Algoritma */
    DelLast(L,&P);
    (*X) = Info(P);
    Dealokasi(&P);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
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
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P)
{
    *P = First(*L);
    First(*L) = Next(First(*L));
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */

void DelLast (List *L, address *P)
{
     address Last, PrecLast;
  
  /* Algoritma */
  Last = First(*L);
  PrecLast = Nil;
  while (Next(Last) != Nil) {
    PrecLast = Last;
    Last = Next(Last);;
  }
  *P = Last;
  if (PrecLast == Nil) {
    First(*L) = Nil;
  } else {
    Next(PrecLast) = Nil;
  }
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
void DelAfter (List *L, address *Pdel, address Prec)
{
   *Pdel = Next(Prec);
    Next(Prec) = Next(Next(Prec));
    Next(*Pdel) = Nil; 
}
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */

int NbElmt (List L)
{
    /* Kamus Lokal */
        /* Kamus Lokal */
    address P;
    int i;

    /* Algoritma */
    i = 0;
    P = First(L);
    while (P != Nil) {
       i++;
       P = Next(P);
    }
    return i;
}
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */