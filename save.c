#include "tipe_bentukan.h"
    
void save(list list_ada_putih , list list_ada_hitam , int poin_putih , int poin_hitam , queue giliran , stack history , stack termakan, char putih_1, char putih_2, char putih_3, char hitam_1, char hitam_2, char hitam_3, int turn)
{
    FILE * fp;

    // simpan list_ada_putih
    fp = fopen ("save_file//list_ada_putih.txt","w"); 
    address_list P;
    P = First(list_ada_putih);
    while (P != Nil_list) {
        fprintf(fp,"%c",Info(P).nama);
        fprintf(fp,"|");
        fprintf(fp,"%d",Info(P).player);
        fprintf(fp,"|");
        fprintf(fp,"%d",Info(P).poin);
        fprintf(fp,"|");
        fprintf(fp,"%d",Info(P).posisiR);
        fprintf(fp,"|");
        fprintf(fp,"%d",Info(P).posisiC);
        fprintf(fp,"|");
        P = Next(P);
    }
    fprintf(fp,";"); // tanda berakhir
    fclose (fp);

    // list_ada_hitam
    fp = fopen ("save_file//list_ada_hitam.txt","w");
    P = First(list_ada_hitam);
    while (P != Nil_list) {
        fprintf(fp,"%c",Info(P).nama);
        fprintf(fp,"|");
        fprintf(fp,"%d",Info(P).player);
        fprintf(fp,"|");
        fprintf(fp,"%d",Info(P).poin);
        fprintf(fp,"|");
        fprintf(fp,"%d",Info(P).posisiR);
        fprintf(fp,"|");
        fprintf(fp,"%d",Info(P).posisiC);
        fprintf(fp,"|");
        P = Next(P);
    }
    fprintf(fp,";"); // tanda berakhir
    fclose (fp);

    // simpan poin putih poin hitam dan giliran dan turn
    // formatnya : 20|60|1;
    // 20 adalah poin putih, 60 poin hitam, 1 adalah giliran selanjutnya
    fp = fopen("save_file//poin.txt","w");
    fprintf(fp,"%d",poin_putih);
    fprintf(fp,"|");
    fprintf(fp,"%d",poin_hitam);
    fprintf(fp,"|");
    fprintf(fp,"%d",InfoTail(giliran));
    fprintf(fp,"|");
    fprintf(fp,"%d", turn);
    fprintf(fp, "|");
    fprintf(fp,";");
    fclose(fp);

    // save stack history
    // formatnya nama,player,turn,posisiR_lama,posisiC_lama,posisiR_baru,posisiC_baru
    fp = fopen("save_file//history.txt","w");
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
        fprintf(fp,"|");
    }
    fprintf(fp,";");
    fclose(fp);

    // save stack termakan
    fp = fopen("save_file//termakan.txt","w");
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
        fprintf(fp,"|");
    }
    fprintf(fp,";");
    fclose(fp);


    // save kedua nama pemain
    fp = fopen("save_file//namaplayer.txt","w");
    fprintf(fp, "%c", putih_1);
    fprintf(fp, "%c", putih_2);
    fprintf(fp, "%c", putih_3);
    fprintf(fp , "|");
    fprintf(fp, "%c", hitam_1);
    fprintf(fp, "%c", hitam_2);
    fprintf(fp, "%c", hitam_3);
    fprintf(fp , "|");
    fprintf(fp , ";");
    fclose(fp);
}

