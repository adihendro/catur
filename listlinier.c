#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty_list (list L){
    return First(L) == Nil_list;
}
/* Mengirim true jika list kosong */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty_list (list *L){
    First(*L) = Nil_list;
}

/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** Manajemen Memori ******************/
address_list Alokasi (infotype_list X){
    address_list P;

    P = (address_list) malloc (sizeof(ElmtList));

    if (P != Nil_list){
        Info(P) = X;
        Next(P) = Nil_list;
        return P;
    } else{
        return Nil_list;
    }
}
/* Mengirimkan address_list hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address_list tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil_list */
/* Jika alokasi gagal, mengirimkan Nil_list */

void Dealokasi (address_list *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address_list P */
{
    free(*P);
}


/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (list *L, infotype_list X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
    address_list P;

    P = Alokasi(X);
    if(P!=Nil_list)
    {
        InsertFirst(L,P);
    }
}

void InsVLast (list *L, infotype_list X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    address_list P;

    /* Algoritma */
    P = Alokasi(X);
    if (P != Nil_list) 
    {
      InsertLast(L,P);
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (list *L, infotype_list *X)
/* I.S. list L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
    address_list P;

    /* Algoritma */
    P = First(*L);
    (*X) = Info(P);
    First(*L) = Next(First(*L));
    Next(P) = Nil_list;
    Dealokasi(&P);
}

void DelVLast (list *L, infotype_list *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
    address_list P;

    /* Algoritma */
    DelLast(L,&P);
    (*X) = Info(P);
    Dealokasi(&P);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (list *L, address_list P)
{
    Next(P) = First(*L);
    First(*L) = P;
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address_list P sebagai elemen pertama */
void InsertAfter (list *L, address_list P, address_list Prec)
{
    Next(P) = Next(Prec);
    Next(Prec) = P;
}
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertLast (list *L, address_list P)
{
    address_list Last;
    
    /* Algoritma */
    Last = First(*L);
    if (First(*L) == Nil_list) {
      InsertFirst(L,P);
    } else {
      while (Next(Last) != Nil_list) {
        Last = Next(Last);
      }
      InsertAfter(L,P,Last);
    }
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (list *L, address_list *P)
{
    *P = First(*L);
    First(*L) = Next(First(*L));
}
/* I.S. list tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */

void DelLast (list *L, address_list *P)
{
    address_list Last, PrecLast;
  
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
/* I.S. list tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
void DelAfter (list *L, address_list *Pdel, address_list Prec)
{
   *Pdel = Next(Prec);
    Next(Prec) = Next(Next(Prec));
    Next(*Pdel) = Nil_list; 
}
/* I.S. list tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */

int NbElmt (list L)
{
    /* Kamus Lokal */
        /* Kamus Lokal */
    address_list P;
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
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */



//Fungsi reborn
address_list Search (list L, int X, int Y){
    address_list a, a1;
    a=First(L);
    a1=a;
    boolean ketemu=false;
    while(!ketemu){
        if(Info(a).posisiC==X && Info(a).posisiR==Y){
            ketemu=true;
        } else{
            a1=a;
            a=Next(a);
        }
    }
    return a1;
}
