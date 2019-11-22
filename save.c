
#include <stdio.h>
#include "tipe_bentukan.h"
 
int main ()
{
    FILE * fp;

    // simpan list_ada_putih
    fp = fopen ("list_ada_putih.txt","w"); 
    address_list P;
    P = First(list_ada_putih);
    while (P != Nil_list) {
        fprintf(fp,"%c",Info(P).nama);
        fprintf(fp,"^");
        fprintf(fp,"%d",Info(P).player);
        fprintf(fp,"^");
        fprintf(fp,"%d",Info(P).poin);
        fprintf(fp,"^");
        fprintf(fp,"%d",Info(P).posisiR);
        fprintf(fp,"^");
        fprintf(fp,"%d",Info(P).posisiC);
        fprintf(fp,".");
        P = Next(P);
    }
    fprintf(fp,";"); // tanda berakhir
    fclose (fp);

    // list_ada_hitam
    fp = fopen ("list_ada_hitam.txt","w");
    address_list P;
    P = First(list_ada_hitam);
    while (P != Nil_list) {
        fprintf(fp,"%c",Info(P).nama);
        fprintf(fp,"^");
        fprintf(fp,"%d",Info(P).player);
        fprintf(fp,"^");
        fprintf(fp,"%d",Info(P).poin);
        fprintf(fp,"^");
        fprintf(fp,"%d",Info(P).posisiR);
        fprintf(fp,"^");
        fprintf(fp,"%d",Info(P).posisiC);
        fprintf(fp,".");
        P = Next(P);
    }
    fprintf(fp,";"); // tanda berakhir
    fclose (fp);

    // simpan poin putih poin hitam dan giliran
    // formatnya : 20|60|1;
    // 20 adalah poin putih, 60 poin hitam, 1 adalah giliran selanjutnya
    fp = fopen("poin.txt","w");
    fprintf(fp,"%d",poin_putih);
    fprintf(fp,"|");
    fprintf(fp,"%d",poin_hitam);
    fprintf(fp,"|");
    fprintf(fp,"%d",InfoTail(giliran));
    fprintf(fp,";");
    fclose(fp);

    // save stack history
    // formatnya nama,player,turn,posisiR_lama,posisiC_lama,posisiR_baru,posisiC_baru
    fp = fopen("history.txt","w");
    stack history_copy;
    history_copy = history;
    stack reverse_history;
    infotype_stack temp;
    CreateEmpty_stack(&reverse_history); // stacknya kebalik
    while(!IsEmpty_stack(history_copy)) {
        Pop(&history_copy,&temp);
        Push(&reverse_history,temp);
    }
    // mulai menulis ke txt
    while(!IsEmpty_stack(reverse_history)) {
        Pop(&reverse_history,&temp);
        fprintf(fp,"%c",temp.nama);
        fprintf(fp,"|");
        fprintf(fp,"%d",temp.player);
        fprintf(fp,"|");
        fprintf(fp,"%d",temp.turn);
        fprintf(fp,"|");
        fprintf(fp,"%d",temp.posisiR_lama);
        fprintf(fp,"|");
        fprintf(fp,"%d",temp.posisiC_lama);
        fprintf(fp,"|");
        fprintf(fp,"%d",temp.posisiR_baru);
        fprintf(fp,"|");
        fprintf(fp,"%d",temp.posisiC_baru);
        fprintf(fp,"|");
        fprintf(fp,"%d",temp.promotion);
        fprintf(fp,"|");
        fprintf(fp,"%d",temp.twosteps);
        fprintf(fp,".");
    }
    fprintf(fp,";");
    fclose(fp);

    // save stack termakan
    fp = fopen("termakan.txt","w");
    stack termakan_copy;
    termakan_copy = termakan;
    stack reverse_termakan;
    CreateEmpty_stack(&reverse_termakan);
    while(!IsEmpty_stack(termakan_copy)) {
        Pop(&termakan_copy,&temp);
        Push(&reverse_termakan,temp);
    }
    // mulai menulis ke txt
    while(!IsEmpty_stack(reverse_termakan)) {
        Pop(&reverse_termakan,&temp);
        fprintf(fp,"%c",temp.nama);
        fprintf(fp,"|");
        fprintf(fp,"%d",temp.player);
        fprintf(fp,"|");
        fprintf(fp,"%d",temp.turn);
        fprintf(fp,"|");
        fprintf(fp,"%d",temp.posisiR_lama);
        fprintf(fp,"|");
        fprintf(fp,"%d",temp.posisiC_lama);
        fprintf(fp,"|");
        fprintf(fp,"%d",temp.posisiR_baru);
        fprintf(fp,"|");
        fprintf(fp,"%d",temp.posisiC_baru);
        fprintf(fp,"|");
        fprintf(fp,"%d",temp.promotion);
        fprintf(fp,"|");
        fprintf(fp,"%d",temp.twosteps);
        fprintf(fp,".");
    }
    fprintf(fp,";");
    fclose(fp);

    
    return 0;
}

