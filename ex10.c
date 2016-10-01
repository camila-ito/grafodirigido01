#include<stdio.h>
#include<math.h>
#define DEBUG 0


/* --------------------------------------------------------------------------*/
/**
 * \brief 
 *
 * \param argc
 * \param argv[]
 *
 * \return 
 */
int main(int argc, char *argv[])
{
    int i, r, opt,
        j; /*numero de automatos*/
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
            default:
                printf("Type\n\t$man %s\nor\n\t$%s -h\nfor help.\n\n", argv[0], argv[0]);
                return EXIT_FAILURE;
        }  
    
    /*começo do codigo*/
     
    return EXIT_SUCCESS;
}

int entrada(char letra[][2], char url[])
{

    return i;
}
