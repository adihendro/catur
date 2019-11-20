
#include <stdio.h>
#include "tipe_bentukan.h"
 
int main ()
{
    FILE * fp;

    fp = fopen ("list_ada_putih.txt","w");
 
    address P;
    P = First(list_ada_putih);
    while (P != Nil_list) {
        fprintf(fp,"%c",Info(P).nama);
        fprintf(fp,"^");
        fprintf(fp,"%d",Info(P).player);
        fprintf(fp,"^");
        fprintf(fp,"%d",Info(P).poin);
        fprintf(fp,"^");
        fprintf(fp,"%d",Info(P).PosisiR);
        fprintf(fp,"^");
        fprintf(fp,"%d",Info(P).PosisiC);
        fprintf(fp,".");
        P = Next(P);
    }
    fprintf(fp,";"); // tanda berakhir
    fclose (fp);


    fp = fopen ("list_ada_hitam.txt","w");
 
    address P;
    P = First(list_ada_hitam);
    while (P != Nil) {
        fprintf(fp,"%c",Info(P).nama);
        fprintf(fp,"^");
        fprintf(fp,"%d",Info(P).player);
        fprintf(fp,"^");
        fprintf(fp,"%d",Info(P).poin);
        fprintf(fp,"^");
        fprintf(fp,"%d",Info(P).PosisiR);
        fprintf(fp,"^");
        fprintf(fp,"%d",Info(P).PosisiC);
        fprintf(fp,".");
        P = Next(P);
    }
    fprintf(fp,";"); // tanda berakhir
    fclose (fp);
    return 0;
}

