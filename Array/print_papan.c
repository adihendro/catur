#include "..//ProgramUtama//tipe_bentukan.h"

void PrintPapan(papan *board[10][10]){
	/*jadi gw mikirnya board ini array yang terdiri dari tipe bentukan piece
	  yang isinya: 
      1. namanya "king,queen,dsb" (string). bisa juga pake integer kaya king 1, queen 2 ato gmn
	  2. playernya(int) 1 atau 2
	  3. poinnya(int) biar bisa dijumlah. ato gk klo mau ntar if king trus +10 gt
	*/
	int i,j;
    char gameboard[35][35] = {
        {' ',' ','+','-','-','-','+','-','-','-','+','-','-','-','+','-','-','-','+','-','-','-','+','-','-','-','+','-','-','-','+','-','-','-','+'},
        {' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|'},
        {' ','8','|',' ','R',' ','|',' ','N',' ','|',' ','B',' ','|',' ','Q',' ','|',' ','K',' ','|',' ','B',' ','|',' ','N',' ','|',' ','R',' ','|'},
        {' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|'},
        {' ',' ','+','-','-','-','+','-','-','-','+','-','-','-','+','-','-','-','+','-','-','-','+','-','-','-','+','-','-','-','+','-','-','-','+'},
        {' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|'},
        {' ','7','|',' ','P',' ','|',' ','P',' ','|',' ','P',' ','|',' ','P',' ','|',' ','P',' ','|',' ','P',' ','|',' ','P',' ','|',' ','P',' ','|'},
        {' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|'},
        {' ',' ','+','-','-','-','+','-','-','-','+','-','-','-','+','-','-','-','+','-','-','-','+','-','-','-','+','-','-','-','+','-','-','-','+'},
        {' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|'},
        {' ','6','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|'},
        {' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|'},
        {' ',' ','+','-','-','-','+','-','-','-','+','-','-','-','+','-','-','-','+','-','-','-','+','-','-','-','+','-','-','-','+','-','-','-','+'},
        {' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|'},
        {' ','5','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|'},
        {' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|'},
        {' ',' ','+','-','-','-','+','-','-','-','+','-','-','-','+','-','-','-','+','-','-','-','+','-','-','-','+','-','-','-','+','-','-','-','+'},
        {' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|'},
        {' ','4','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|'},
        {' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|'},
        {' ',' ','+','-','-','-','+','-','-','-','+','-','-','-','+','-','-','-','+','-','-','-','+','-','-','-','+','-','-','-','+','-','-','-','+'},
        {' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|'},
        {' ','3','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|'},
        {' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|'},
        {' ',' ','+','-','-','-','+','-','-','-','+','-','-','-','+','-','-','-','+','-','-','-','+','-','-','-','+','-','-','-','+','-','-','-','+'},
        {' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|'},
        {' ','2','|',' ','p',' ','|',' ','p',' ','|',' ','p',' ','|',' ','p',' ','|',' ','p',' ','|',' ','p',' ','|',' ','p',' ','|',' ','p',' ','|'},
        {' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|'},
        {' ',' ','+','-','-','-','+','-','-','-','+','-','-','-','+','-','-','-','+','-','-','-','+','-','-','-','+','-','-','-','+','-','-','-','+'},
        {' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|'},
        {' ','1','|',' ','r',' ','|',' ','n',' ','|',' ','b',' ','|',' ','q',' ','|',' ','k',' ','|',' ','b',' ','|',' ','n',' ','|',' ','r',' ','|'},
        {' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|'},
        {' ',' ','+','-','-','-','+','-','-','-','+','-','-','-','+','-','-','-','+','-','-','-','+','-','-','-','+','-','-','-','+','-','-','-','+'},
        {' ',' ',' ',' ','a',' ',' ',' ','b',' ',' ',' ','c',' ',' ',' ','d',' ',' ',' ','e',' ',' ',' ','f',' ',' ',' ','g',' ',' ',' ','h',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}   
    };


	//representasi klo piece di board[10][10] bakal ditaroh dimana di board gede
	//displayRow
	int dR0 = 2;
	int dR1 = 6;
	int dR2 = 10;
	int dR3 = 14;
	int dR4 = 18;
	int dR5 = 22;
	int dR6 = 26;
	int dR7 = 30;

	//displayColumn
	int dC0 = 4;
	int dC1 = 8;
	int dC2 = 12;
	int dC3 = 16;
	int dC4 = 20;
	int dC5 = 24;
	int dC6 = 28;
	int dC7 = 32;

    //nyimpen row dan column sementara
	int tempRow;
	int tempCol;

	//update lokasi bidak di display board
	for(int i = 1; i <= 8; i++){
		if(i == 1)
			tempRow = dR0;
		else if(i == 2)
			tempRow = dR1;
		else if(i == 3)
			tempRow = dR2;
		else if(i == 4)
			tempRow = dR3;
		else if(i == 5)
			tempRow = dR4;
		else if(i == 6)
			tempRow = dR5;
		else if(i == 7)
			tempRow = dR6;
		else if(i == 8)
			tempRow = dR7;
		
		for(int j = 1; j <= 8; j++){	
			if(j == 1)
				tempCol = dC0;
			else if(j == 2)
				tempCol = dC1;
			else if(j == 3)	
				tempCol = dC2;
			else if(j == 4)
				tempCol = dC3;
			else if(j == 5)
				tempCol = dC4;
			else if(j == 6)
				tempCol = dC5;
			else if(j == 7)
				tempCol = dC6;
			else if(j == 8)
				tempCol = dC7;

            //update display board pieces to match the real board
            if((*board[i][j]).nama==' '){
                gameboard[tempRow][tempCol] = ' ';
            }
            else if((*board[i][j]).nama=='P'){
                if((*board[i][j]).player == 1){
                    gameboard[tempRow][tempCol] = 'P';
                }
                else{
                    gameboard[tempRow][tempCol] = 'p';
                }        
            }
            else if((*board[i][j]).nama=='K'){
                if((*board[i][j]).player == 1){
                    gameboard[tempRow][tempCol] = 'K';
                }
                else{
                    gameboard[tempRow][tempCol] = 'k';
                }        
            }
            else if((*board[i][j]).nama=='Q'){
                if((*board[i][j]).player == 1){
                    gameboard[tempRow][tempCol] = 'Q';
                }
                else{
                    gameboard[tempRow][tempCol] = 'q';
                }        
            }
            else if((*board[i][j]).nama=='B'){
                if((*board[i][j]).player == 1){
                    gameboard[tempRow][tempCol] = 'B';
                }
                else{
                    gameboard[tempRow][tempCol] = 'b';
                }        
            }
            else if((*board[i][j]).nama=='N'){
                if((*board[i][j]).player == 1){
                    gameboard[tempRow][tempCol] = 'N';
                }
                else{
                    gameboard[tempRow][tempCol] = 'n';
                }        
            }
            else if((*board[i][j]).nama=='R'){
                if((*board[i][j]).player == 1){
                    gameboard[tempRow][tempCol] = 'R';
                }
                else{
                    gameboard[tempRow][tempCol] = 'r';
                }        
            }
        }
    }

	for (i = 0; i < 33 ; i++) {
        for (j = 0; j < 35; j++) {
            if((gameboard[i][j] == 'P' ) || (gameboard[i][j] == 'K' ) || (gameboard[i][j] == 'Q' ) || //bidak putih
               (gameboard[i][j] == 'B' ) || (gameboard[i][j] == 'N' ) || (gameboard[i][j] == 'R' )){
                printf("\033[1;32m"); //warna hijau
                printf("%c ", gameboard[i][j]); //bidak putih memakai warna hijau
                printf("\033[0m"); 
            } else if((gameboard[i][j] == 'p' ) || (gameboard[i][j] == 'k' ) || (gameboard[i][j] == 'q' ) || //bidak hitam
               (gameboard[i][j] == 'b' ) || (gameboard[i][j] == 'n' ) || (gameboard[i][j] == 'r' )){
                printf("\033[1;31m"); //warna merah
                printf("%c ", gameboard[i][j]); //bidak hitam memakai warna merah
                printf("\033[0m");
            } else{
                printf("%c ", gameboard[i][j]);
            }
        }
        printf("\n");
    }
    for (i = 33; i < 35 ; i++) {
        for (j = 0; j < 35; j++) {
            printf("%c ", gameboard[i][j]);
        }
        printf("\n");
    }
}
