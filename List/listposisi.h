#ifndef listposisi_H
#define listposisi_H

#include "..//ProgramUtama//tipe_bentukan.h"

/* Definisi list_posisi : */
/* list_posisi kosong : First(L) = Nil */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P) */
/* Elemen terakhir list_posisi : jika addressnya Last, maka Next(Last)=Nil */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty_posisi (list_posisi *L);
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** Manajemen Memori ******************/
address_posisi Alokasi_posisi (infotype_posisi X);
/* Mengirimkan address_list hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address_list tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void Dealokasi_posisi (address_posisi *P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address_list P */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst_posisi (list_posisi *L, infotype_posisi X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLast_posisi (list_posisi *L, infotype_posisi X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst_posisi (list_posisi *L, address_posisi P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address_list P sebagai elemen pertama */
void InsertAfter_posisi (list_posisi *L, address_posisi P, address_posisi Prec);
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertLast_posisi (list_posisi *L, address_posisi P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */


/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst_posisi (list_posisi *L, infotype_posisi *X);
/* I.S. list L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast_posisi (list_posisi *L, infotype_posisi *X);
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
void DelFirst_posisi (list_posisi *L, address_posisi *P);
/* I.S. list tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelLast_posisi (list_posisi *L, address_posisi *P);
/* I.S. list tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
void DelAfter_posisi (list_posisi *L, address_posisi *Pdel, address_posisi Prec);
/* I.S. list tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */

int NbElmt_posisi (list_posisi L);
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */


#endif