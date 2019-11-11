/* 
 *  Author: zentut.com
 *  Description: C Write text file demo
 */
 
#include <stdio.h>
 
#define LEN 256
int main ()
{
   FILE * fp;
   int i;
   /* open the file for writing*/
   fp = fopen ("nyoba.txt","w");
 
   /* write 10 lines of text into the file stream*/
   for(i = 0; i < 10;i++){
       fprintf (fp, "This iszz line %d\n",i + 1);
   }
 
   /* close the file*/  
   fclose (fp);
   return 0;
}

void save();

void save () {
    FILE *fp;
    fp = fopen("list_ada_hitam.txt","w");

    // write
    

    fclose(fp);
}