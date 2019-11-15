#include "boolean.h"
#include <stdio.h>

#ifndef stack_H
#define stack_H

/* MODUL STACK
Deklarasi stack yang diimplementasi dengan tabel kontigu alokasi statik
dan ukuran sama
TOP adalah alamat elemen puncak*/

#define Nil 0
#define MaxEl 10
#define Top(S) (S).TOP
#define Info(S) (S).infotype_stack;

typedef struct 
{
    char nama;
    int player;
    int turn;
    int posisiR;
    int posisiC;
} infotype_stack;

typedef int address;

typedef struct {
    infotype_stack T[MaxEl + 1];
    address TOP;
} Stack;

/* Definisi stack S kosong : S.TOP = Nil */
/* S.TOP = jumlah element stack */
/* S.T[S.TOP-1] = element paling atas */


/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmpty(Stack *S);
/* I.S. Sembarang */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmpty(Stack S);
/* Mengirim true jika Stack kosong*/
/* Ciri stack kosong : TOP bernilai Nil */
boolean IsFull(Stack S);
/* Mengirim true jika stack S penuh */
/* Ciri stack penuh : TOP bernilai MaxEl */

/* ********** Operator Dasar Stack ********* */
void Push(Stack *S, infotype_stack X);
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, S tidak penuh */
/*F.S. X menjadi element TOP yang baru, TOP bertambah 1 */
void Pop (Stack *S, infotype_stack *X);
/* Menghapus X dari Stack S. */
/* I.S. S tidak kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */


#endif