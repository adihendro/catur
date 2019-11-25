#include "tipe_bentukan.h"
//#include "threaten.c"

boolean isthreatened(list lawan, int x, int y, papan *board[10][10])
{ 
    int* jml;
    address_list* P1;
    //mengefound apakah suatu spot berbahaya untuk raja
    list_posisi dftr_posisi;
    address_posisi R;
    address_list P;
    boolean found = false;
    (*jml)=0; //inisialisasi awal jml
    P = First(lawan);

    while (P!=Nil_list && (*jml)<=1){
        CreateEmpty_posisi(&dftr_posisi);
        ceksemuagerak(Info(P), board, &dftr_posisi); //menyimpan semua gerakan yang mungkin dari bidak lawan
        R = First(dftr_posisi);

        while (R!=Nil_list && (*jml)<=1){
            if((Info(R).posisiC==x)&&(Info(R).posisiR==y)){
                found = true;
                (*jml)++;
                *P1 = P;
            }
            R = Next(R);
        }

        P = Next(P);
    }
    return found;
}

boolean HasMoved(piece P, stack history)
{
    infotype_stack X;
    int counter = 1;
    boolean Moved = false;

    while ((!Moved) && (counter <= (history.T[(history).TOP].turn))){   
        X = (history).T[(history).TOP];
        history.TOP--;
    
        if (X.nama == P.nama)
            Moved = true;
        counter++;
    }
    return Moved;
}

/*
void castling(piece Raja, piece Benteng, stack history, papan* board[10][10])
{
    if (!(HasMoved(Raja, history))) //kalau raja belum pernah gerak
    {
        if (((*board[Raja.posisiR][Raja.posisiC+2]).nama == ' ') && ((*board[Raja.posisiR][Raja.posisiC+1]).nama == ' ') && (!(HasMoved(Benteng, history))))
        {
           (*board[Raja.posisiR][Raja.posisiC+2]).nama == 'R';
        }
    }
}
*/

boolean cek_castling_pendek(stack history, list list_ada_putih, list list_ada_hitam, queue *giliran)
{
    address_list *P;
    boolean raja_gerak = true;
    boolean benteng_kanan_gerak = true; //dibuat defaultnya true biar pengecekan lebih gampang
    boolean isthreatened_kanan = false;

    if (InfoTail(*giliran) == 1) // kalau putih
    {
        address_list P1;
        *P = First(list_ada_putih);
        isthreatened_kanan = (isthreatened(list_ada_hitam,5,8,board) && 
                              isthreatened(list_ada_hitam,6,8,board && isthreatened(list_ada_hitam,7,8,board)));
        // ngecek kotak e1 f1 g1 aman apa kaga

    } //giliran putih
            
    else //giliran == 2, hitam
    {
        *P = First(list_ada_hitam);
        isthreatened_kanan = (isthreatened(list_ada_putih,5,1,board) && 
                              isthreatened(list_ada_putih,6,1,board && isthreatened(list_ada_putih,7,1,board)));
        // ngecek kotak e8 f8 g8 aman apa kaga

    }
            

    while((*P) != Nil_list) //
    {
        if(Info(*P).nama == 'K') //cek raja
        { 
                if(!HasMoved(Info(*P),history)) // kalau ternyata raja belum jalan
                {
                    raja_gerak = false;
                }
        }

        if(Info(*P).nama == 'B'  && Info(*P).posisiC == 8) //cek benteng kanan
        { 
                if(!HasMoved(Info(*P),history)) // kalau benteng belum gerak
                {
                    benteng_kanan_gerak = false;
                }
        }
            
        *P = Next(*P);
    }

    return (!raja_gerak && !benteng_kanan_gerak && !isthreatened_kanan);
}

boolean cek_castling_panjang(stack history, list list_ada_putih, list list_ada_hitam, queue *giliran)
{
    address_list *P;
    boolean raja_gerak = true;
    boolean benteng_kiri_gerak = true; 
    boolean isthreatened_kiri = false;

    if (InfoTail(*giliran) == 1) // kalau putih
    {
        *P = First(list_ada_putih);
        isthreatened_kiri = (isthreatened(list_ada_hitam,5,8,board) && 
                             isthreatened(list_ada_hitam,4,8,board && isthreatened(list_ada_hitam,3,8,board)));
        // ngecek kotak c1 d1 e1 aman apa kaga
    } //giliran putih
            
    else //giliran == 2, hitam
    {
        *P = First(list_ada_hitam);
        isthreatened_kiri = (isthreatened(list_ada_putih,5,1,board) && 
                             isthreatened(list_ada_putih,4,1,board && isthreatened(list_ada_putih,3,1,board)));
        // ngecek kotak e8 f8 g8 aman apa kaga
    }
            

    while((*P) != Nil_list) //
    {
        if(Info(*P).nama == 'K') //cek raja
        { 
                if(!HasMoved(Info(*P),history)) // kalau ternyata raja belum jalan
                {
                    raja_gerak = false;
                }
        }

        if(Info(*P).nama == 'B') //cek benteng
        { 
                if(!HasMoved(Info(*P),history) && Info(*P).posisiC == 1) // kalau benteng belum gerak dan posisinya di a1 (putih)/a8 (hitam)
                {
                    benteng_kiri_gerak = false;
                }
        }
            
        *P = Next(*P);
    }
    return (!raja_gerak && !benteng_kiri_gerak && !isthreatened_kiri);
}

void castling_pendek(stack* history, list* list_ada_putih, list* list_ada_hitam, queue *giliran)
{
    address_list *P;

    if (InfoTail(*giliran) == 1) // kalau putih
    {
        *P = First(*list_ada_putih);
    } //giliran putih

    else //giliran == 2, hitam
    {
        *P = First(*list_ada_hitam);
    }

    while((*P) != Nil_list) //
    {
        if(Info(*P).nama == 'K') //cek raja
        { 
            Info(*P).posisiC = 7;
        }

        if(Info(*P).nama == 'B'  && Info(*P).posisiC == 8) //cek benteng kanan
        { 
            Info(*P).posisiC = 6;
        }
            
        *P = Next(*P);
    }

    char str[] = "Castling pendek berhasil dilakukan";
    printf("%s",str);
}

void castling_panjang(stack* history, list* list_ada_putih, list* list_ada_hitam, queue *giliran)
{
    address_list *P;

    if (InfoTail(*giliran) == 1) // kalau putih
    {
        *P = First(*list_ada_putih);
    } //giliran putih

    else //giliran == 2, hitam
    {
        *P = First(*list_ada_hitam);
    }

    while((*P) != Nil_list) //
    {
        if(Info(*P).nama == 'K') //cek raja
        { 
            Info(*P).posisiC = 3;
        }

        if(Info(*P).nama == 'B'  && Info(*P).posisiC == 1) //cek benteng kiri
        { 
            Info(*P).posisiC = 4;
        }
            
        *P = Next(*P);
    }

    char str[] = "Castling pendek berhasil dilakukan";
    printf("%s",str);
}
int main()
{

    return 0;
}