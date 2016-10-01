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
                strcpy(url, optarg);
                break;
            case 'h':
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
        
        do{
            __fpurge(stdin);
        } while(rel[0] == '\n' || rel[1] == '\n');
        
    }
    return EXIT_SUCCESS;
}

int entrada(char letra[][2], char url[])
{
    int i = 0; k;
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
