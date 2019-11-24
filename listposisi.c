#include <stdio.h>
#include <stdlib.h>
#include "listposisi.h"


/****************** TEST LIST KOSONG ******************/
boolean IsEmpty_posisi (list_posisi L){
    return First(L) == Nil_list;
}

/* Mengirim true jika list kosong */
void CreateEmpty_posisi (list_posisi *L){
    First(*L) = Nil_list;
}

address_posisi Alokasi_posisi (infotype_posisi X){
    address_posisi P;
    P = (address_posisi) malloc (sizeof(ElmtList_posisi));

    if (P != Nil_list){
        Info(P) = X;
        Next(P) = Nil_list;
        return P;
    } else{
        return Nil_list;
    }
}

void Dealokasi_posisi (address_posisi *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address_list P */
{
    free(*P);
}


void InsVFirst_posisi (list_posisi *L, infotype_posisi X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
    address_posisi P;

    P = Alokasi_posisi(X);
    if(P!=Nil_list){
        InsertFirst_posisi(L,P);
    }
}

void InsVLast_posisi (list_posisi *L, infotype_posisi X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list_posisi di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    address_posisi P;

    /* Algoritma */
    P = Alokasi_posisi(X);
    if (P != Nil_list) {
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
/* I.S. Prec pastilah elemen list_posisi dan bukan elemen terakhir, */
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




/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst_posisi (list_posisi *L, infotype_posisi *X)
/* I.S. list_posisi L tidak kosong  */
/* F.S. Elemen pertama list_posisi dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
    address_posisi P;

    /* Algoritma */
    P = First(*L);
    (*X) = Info(P);
    First(*L) = Next(First(*L));
    Next(P) = Nil_list;
    Dealokasi_posisi(&P);
}

void DelVLast_posisi (list_posisi *L, infotype_posisi *X)
/* I.S. list_posisi tidak kosong */
/* F.S. Elemen terakhir list_posisi dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
    address_posisi P;

    /* Algoritma */
    DelLast_posisi(L,&P);
    (*X) = Info(P);
    Dealokasi_posisi(&P);
}



/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst_posisi (list_posisi *L, address_posisi *P)
{
    *P = First(*L);
    First(*L) = Next(First(*L));
}
/* I.S. list_posisi tidak kosong */
/* F.S. P adalah alamat elemen pertama list_posisi sebelum penghapusan */
/*      Elemen list_posisi berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */

void DelLast_posisi (list_posisi *L, address_posisi *P)
{
    address_posisi Last, PrecLast;
  
    /* Algoritma */
    Last = First(*L);
    PrecLast = Nil_list;
    while (Next(Last) != Nil_list) {
        PrecLast = Last;
        Last = Next(Last);;
    }
    *P = Last;
    if (PrecLast == Nil_list) {
        First(*L) = Nil_list;
    } else {
        Next(PrecLast) = Nil_list;
    }
}
/* I.S. list_posisi tidak kosong */
/* F.S. P adalah alamat elemen terakhir list_posisi sebelum penghapusan  */
/*      Elemen list_posisi berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
void DelAfter_posisi (list_posisi *L, address_posisi *Pdel, address_posisi Prec)
{
   *Pdel = Next(Next(Prec));
    Next(Next(Prec)) = Nil_list; 
    Next(Prec) = *Pdel;
}
/* I.S. list_posisi tidak kosong. Prec adalah anggota list_posisi  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list_posisi yang dihapus  */

int NbElmt_posisi (list_posisi L)
{
    /* Kamus Lokal */
        /* Kamus Lokal */
    address_posisi P;
    int i;

    /* Algoritma */
    i = 0;
    P = First(L);
    while (P != Nil_list) {
       i++;
       P = Next(P);
    }
    return i;
}
/* Mengirimkan banyaknya elemen list_posisi; mengirimkan 0 jika list_posisi kosong */