#ifndef stack_H
#define stack_H

#include <stdio.h>
#include "boolean.h"

/* MODUL STACK
Deklarasi stack yang diimplementasi dengan tabel kontigu alokasi statik dan ukuran sama
TOP adalah alamat elemen puncak*/

#define Nil_stack 0
#define MaxEl_stack 100
#define Top(S) (S).TOP
#define Info_stack(S) (S).infotype_stack;

typedef struct {
    char nama;
    int player;
    int turn;
    int posisiR_lama;
    int posisiC_lama;
    int posisiR_baru;
    int posisiC_baru;
    boolean promotion;
} infotype_stack;

typedef int address_stack;

typedef struct {
    infotype_stack T[MaxEl_stack+1];
    address_stack TOP;
} stack;

/* Definisi stack S kosong : S.TOP = Nil */
/* S.TOP = jumlah element stack */
/* S.T[S.TOP-1] = element paling atas */


/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmpty_stack(stack *S);
/* I.S. Sembarang */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmpty_stack(stack S);
/* Mengirim true jika stack kosong*/
/* Ciri stack kosong : TOP bernilai Nil */
boolean IsFull_stack(stack S);
/* Mengirim true jika stack S penuh */
/* Ciri stack penuh : TOP bernilai MaxEl */

/* ********** Operator Dasar stack ********* */
void Push(stack *S, infotype_stack X);
/* Menambahkan X sebagai elemen stack S. */
/* I.S. S mungkin kosong, S tidak penuh */
/*F.S. X menjadi element TOP yang baru, TOP bertambah 1 */
void Pop (stack *S, infotype_stack *X);
/* Menghapus X dari stack S. */
/* I.S. S tidak kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */


#endif