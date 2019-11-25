#include "..//ProgramUtama//tipe_bentukan.h"

void string2ByteArray(char* input, int* output)
{
    // mengubah byte string ke array of integer
    int loop = 0;
    int i = 0;

    while(input[loop] != '\0')
        output[i++] = input[loop++];
}
void stringToInt(char* ascii_str,int* Ret){
    //mendapatkan nilai bilangan integer pertama dari array of string
    int len = strlen(ascii_str);
    int arr[len];
    string2ByteArray(ascii_str, arr);
    *Ret = arr[0];
}

// int main(){
//     int input1;
//     int input2;
//     int input_nomor_bidak;
// do{    //buat input yg baru diubah jadi ascii
//         choice = (char*) malloc (sizeof(100));
//         printf("Your choice: ");
//         scanf("%s",choice);
//         stringToInt(choice, &input1, &input2);
//         printf("%d\n",input1);
//         printf("%d\n",input2);
//         if((!((49<=input1<=57) || (48<=input2<=57))) || (!((49<=input1<=57) || (input2==4199676))))
//             printf("Wrong input nigga!\n\n");
//     } while((!((49<=input1<=57) || (48<=input2<=57))) || (!((49<=input1<=57) || (input2==4199676))));
//     input_nomor_bidak = atoi(choice);
//     printf("%d", input_nomor_bidak);
//     return 0;
// } 

// int main(){
//     int jml_bs_grk = 9;
//     int input1;
//     int input_nomor_bidak;
//     do{    //buat input yg baru diubah jadi ascii
//         choice = (char*) malloc (sizeof(100));
//         printf("Your choice: ");
//         scanf("%s",choice);
//         stringToInt(choice, &input1);
//         input_nomor_bidak = atoi(choice);
//         if((!(49<=input1 && input1<=57)) || (input_nomor_bidak>jml_bs_grk))
//             printf("Wrong input! Choose from the corresponding numbers above!\n\n");
//     } while((!(49<=input1 && input1<=57)) || (input_nomor_bidak>jml_bs_grk));
//     return 0;
// } 

// int main(){
//     int X;
//     int Y;
//     do{    
//         choice = (char*) malloc (sizeof(100));
//         printf("Your choice: ");
//         scanf("%s",choice);
//         stringToInt(choice,&X,&Y);
//         if(!(X==49 || X==50 || X==51))//49 adalah ascii untuk 1, 50 = 2, 51 = 3
//             printf("WRONG! It's must be a number from 1-3!\n\n");
//     } while(!(X==49 || X==50 || X==51));
//     printf("fuckin sexy\n");
// }

// int main(){
//     int X;
//     int Y;
//     choice = (char*) malloc (sizeof(100));
//     scanf("%s",choice);
//     stringToInt(choice,&X,&Y);
//     printf("%d\n",X);
//     printf("%d\n",Y);
//     return 0;
// }
