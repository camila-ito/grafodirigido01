#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>

#define DEBUG 0

void help(void);
int entrada(char letra[][2], char url[]);
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
         graf[20], rel[2],
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
                strcpy(url, optarg);
                break;
            case 'h':
                help();
                break;
            case '?':
            default:
                printf("Type\n\t$man %s\nor\n\t$%s -h\nfor help.\n\n", argv[0], argv[0]);
                return EXIT_FAILURE;
        }  

    /*começo do codigo*/

    if(DEBUG)
        printf("grafos: %s, quant_graf: %d\n", graf, j);


    while(1)
    {
        printf("\nAutomatos: %s\n", graf);
        printf("Digite uma relacao entre os lugares existentes:\n");
        scanf("%c%c", &rel[0], &rel[1]);
        __fpurge(stdin);

    }
    return EXIT_SUCCESS;
}

int entrada(char letra[][2], char url[])
{
    int i = 0, k;
    FILE *arquivo = NULL;

    arquivo = fopen(url, "r");

    if(arquivo == NULL)
        printf("erro no carregamento do arquivo\n");

    while(fscanf(arquivo, "%c %c\n", &letra[i][0], &letra[i][1]) != EOF) 
        i++;

    for(k=0; k < i; k++)
    {
        printf("%c",letra[k][0]);
        printf("%c\n",letra[k][1]);
    }
    fclose(arquivo);

    return i;
}
void help(void)
{
    printf("%s - %s\n", "ex10", "Analise de grafos");
    printf("\nUsage: %s [-h|-f]\n", "ex10"); 
}

