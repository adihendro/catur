#include "ascii_checker.c"

int main(){
    int X; // untuk menampung hasil string yang berubah menjadi ascii value
    do{    
        choice = (char*) malloc (sizeof(100));
        printf("Your choice: ");
        scanf("%s",choice); //menerima input string agar tidak error
        stringToInt(choice,&X); //mengubah string menjadi integer
        if(!(X==49 || X==50 || X==51))//49 adalah ascii untuk 1, 50 = 2, 51 = 3
            printf("WRONG! It's must be a number from 1-3!\n\n");
    } while(!(X==49 || X==50 || X==51)); //terus mengulang sampai melakukan input benar
    printf("input benar\n");
}