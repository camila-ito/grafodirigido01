#define MODULO(x) ((x)>=0 ? (x) : (-1*(x)))
#define PI 3.14159265

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>

#define DEBUG 0

void help(void);
int entrada(char letra[][2], char url[]);
int quant_graf(char letra[][2], char *graf, int i);
int verifica(int i, char letra[][2], char reli, char relf);/*reli = relacao inicial// relf = relacao final*/
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

    i = entrada(letra, url);/*i = numero de transicoes no .txt*/
    j = quant_graf(letra, graf, i);/*j = numero de automatos*/

    if(DEBUG)
        printf("grafos: %s, quant_graf: %d\n", graf, j);

    printf("Digite 00(zero zero) para parar o programa\n");

    while(1)
    {
        printf("\nAutomatos: %s\n", graf);
        printf("Digite uma relacao entre os lugares existentes:\n");
        scanf("%c%c", &rel[0], &rel[1]);
        __fpurge(stdin);

        if(rel[0]=='0' && rel[1]=='0')
            break;

        /*verifica(int i, char letra[][2], char reli, char relf)*//*reli = relacao inicial// relf = relacao final*/
    }

    return EXIT_SUCCESS;
}

int verifica(int i, char letra[][2], char reli, char relf)/*reli = relacao inicial// relf = relacao final*/
{
    int ;
    char ;

    return 0;
}
/* --------------------------------------------------------------------------*/
/**
 * \brief 
 *
 * \param letra[][2]
 * \param url[]
 *
 * \return 
 */
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

/* --------------------------------------------------------------------------*/
/**
 * \brief 
 *
 * \param letra[][2]
 * \param graf
 * \param i
 *
 * \return 
 */
int quant_graf(char letra[][2], char *graf, int i)
{
    int k, m,
        j = 0, l = 0;/*variaveis de controle*/

    for(k = 0; k < 20; k++)
        graf[k] = 0;

    for(m = 0; m < 2; m++)
    {        
        for(k=0; k<i; k++)
        {
            if(!graf[j])
            {
                for(l=0; l<j; l++)
                {
                    if(graf[l]==letra[k][m])
                        break;
                }
                if(l==j)
                {
                    graf[j]=letra[k][m];
                    j++;
                }
            }
        }
    }

   
    return j;
}


/* --------------------------------------------------------------------------*/
/**
 * \brief 
 */
void help(void)
{
    printf("%s - %s\n", "ex10", "Analise de grafos");
    printf("\nUsage: %s [-h|-f]\n", "ex10"); 
    exit(EXIT_FAILURE);
}

