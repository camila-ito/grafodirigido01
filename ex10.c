#include<stdio.h>
#include<math.h>
#define DEBUG 0

int main(int argc, char *argv[])
{
    int i, r, opt,
        j;
    char letra[20][2], 
         graf[20], ref[2],
         url[100]= "entrada.txt";
    
    /* getopt() configured options:
     *        -h  help
     *        -f  flag
     */
     opterr = 0;
     while((opt = getopt(argc, argv, "f:h")) != EOF)
        switch(opt)
        {

         case 'f':
             break;
         case 'h':
             break;
         case '?':

     
        }  

    return EXIT_SUCCESS;
}
