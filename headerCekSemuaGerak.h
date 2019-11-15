#ifndef headerCekSemuaGerak_H
#define headerCekSemuaGerak_H

#include <boolean.h>
#include <stdio.h>
#include <stdlib.h>

#define Nil NULL

typedef struct 
{
    int posisiR;
    int posisiC;
}infotype_posisi;

typedef infotype_posisi infotype; //infotypenya adalah sebuah infotype posisi

typedef struct 
{
	infotype info;
	address next;
} list_posisi;  // list posisi adalah tipe bentukan dari infotype posisi, yang terdiri dari posisi baris dan posisi kolom, address next

typedef struct 
{
	char nama;
	int player;
	int poin;
	int posisiR;
	int posisiC;
} piece; //sebuah piece memiliki nama (P,R,N,B,Q,K), punya putih(1) atau hitam(2), poin, dan posisi saat ini
	
typedef struct tElmtlist *address;
typedef struct tElmtlist { 
	infotype info;
	address next;
} ElmtList;

typedef struct {
	address First;
} List;

#define Info(P) (P)->info
#define Next(P) (P)->next
#define First(L) (L).First


//kalo pake depan belakang kiri kanan takut ketuker"
#define Timur(bidak) board[bidak.posisiR][bidak.posisiC+1]
#define Barat(bidak) board[bidak.posisiR][bidak.posisiC-1]
#define Utara(bidak) board[bidak.posisiR-1][bidak.posisiC]
#define Selatan(bidak) board[bidak.posisiR+1][bidak.posisiC]
#define TimurLaut(bidak) board[bidak.posisiR-1][bidak.posisiC+1]
#define BaratLaut(bidak) board[bidak.posisiR-1][bidak.posisiC-1]
#define BaratDaya(bidak) board[bidak.posisiR+1][bidak.posisiC-1]
#define Tenggara(bidak) board[bidak.posisiR+1][bidak.posisiC+1]

address Alokasi (infotype X);
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */

void InsertFirst (List *L, address P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */

void InsertAfter (List *L, address P, address Prec);
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */

void InsertLast (List *L, address P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

void InsVLastSquare (List *L, infotype X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

void AddPossibleMove (List *L, int row, int column); //menambahkan move yang mungkin ke list posisi

void PrintSemuaPosisi (List L);

#endif