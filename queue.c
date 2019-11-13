/* Model Implementasi Versi III dengan circular buffer */

#include <stdlib.h>
#include "queue.h"

/* ********* Prototype ********* */
boolean IsEmpty (queue Q){
  return Head(Q)==Nil && Tail(Q)==Nil;
}
/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean IsFull (queue Q){
  return NBElmt(Q)==MaxEl(Q);
}
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
int NBElmt (queue Q){
  if(IsEmpty(Q)){
    return 0;
  }else{
    if(Head(Q)<=Tail(Q)){
      return Tail(Q)-Head(Q)+1;
    }else{
      return Tail(Q)-Head(Q)+1+MaxEl(Q);
    }
  }
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Kreator *** */
void CreateEmpty (queue *Q, int Max){
  (*Q).T=(infotype*) malloc ((Max+1)*sizeof(infotype));
  if((*Q).T!=NULL){
    MaxEl(*Q)=Max;
    Head(*Q)=Nil;
    Tail(*Q)=Nil;
  }else{ /*alokasi gagal*/
    MaxEl(*Q)=0;
  }
}
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

/* *** Destruktor *** */
void DeAlokasi(queue *Q){
  MaxEl(*Q)=0;
  free((*Q).T);
}
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */

/* *** Primitif Add/Delete *** */
void Add (queue * Q, infotype X){
  if(IsEmpty(*Q)){
    Head(*Q)=1;
  }
  Tail(*Q)=Tail(*Q)%MaxEl(*Q)+1;
  InfoTail(*Q)=X;
}
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */

void Del (queue * Q, infotype * X){
  (*X)=InfoHead(*Q);
  if(NBElmt(*Q)==1){ //Head(*Q)==Tail(*Q)
    Head(*Q)=Nil;
    Tail(*Q)=Nil;
  }else{
    Head(*Q)=Head(*Q)%MaxEl(*Q)+1;
  }
}
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer; 
        Q mungkin kosong */
