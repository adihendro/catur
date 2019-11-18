
#include "stack.h"

void CreateEmpty_stack(stack *S){
    (*S).TOP = Nil;
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmpty_stack(stack S){
    return (S).TOP == Nil;
}
/* Mengirim true jika stack kosong*/
/* Ciri stack kosong : TOP bernilai Nil */
boolean IsFull(stack S){
    return (S).TOP == MaxEl;
}
/* Mengirim true jika stack S penuh */
/* Ciri stack penuh : TOP bernilai MaxEl */

/* ********** Operator Dasar stack ********* */
void Push(stack *S, infotype_stack X){
    (*S).TOP ++;
    (*S).T[(*S).TOP] = X;
}
/* Menambahkan X sebagai elemen stack S. */
/* I.S. S mungkin kosong, S tidak penuh */
/*F.S. X menjadi element TOP yang baru, TOP bertambah 1 */
void Pop (stack *S, infotype_stack *X){
    *X = (*S).T[(*S).TOP];
    (*S).TOP--;
}
/* Menghapus X dari stack S. */
/* I.S. S tidak kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
