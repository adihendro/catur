/* 
 *  Author: zentut.com
 *  Description: C Write text file demo
 */
 
#include <stdio.h>
#include "tipe_bentukan.h"
 
#define LEN 256
int main ()
{
    FILE * fp;

    /* open the file for writing*/
    fp = fopen ("list_ada_putih.txt","w");
 
    /* write 10 lines of text into the file stream*/
    address P;
    P = First(list_ada_putih);
    while (P != Nil_list) {
        fprintf(fp,"%c",Info(P).nama);
        fprintf(fp,"%d",Info(P).player);
        fprintf(fp,"%d",Info(P).poin);
        fprintf(fp,"%d",Info(P).PosisiR);
        fprintf(fp,"%d",Info(P).PosisiC);
        P = Next(P);
    }
    fprintf(fp,";"); // tanda berakhir
    /* close the file*/  
    fclose (fp);
    return 0;
}

