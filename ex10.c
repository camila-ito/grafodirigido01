/* ************************************************************************ *
 *    ex10.x, VERSION 1.0                                                   *
 *    Identificar Caminho, Circuito ou N/A                                  *
 *                                                                          *
 *    Copyright (C) 2016 by Grupo 1                                         *
 * ************************************************************************ *
 *                                                                          *
 *    This program is free software; you can redistribute it and/or modify  *
 *    it under the terms of the GNU General Public License as published by  *
 *    the Free Software Foundation; either version 2 of the License, or     *
 *    (at your option) any later version.                                   *
 *                                                                          *
 *    This program is distributed in the hope that it will be useful,       *
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *    GNU General Public License for more details.                          *
 *                                                                          *
 *    You should have received a copy of the GNU General Public License     *
 *    along with this program; if not, write to the                         *
 *    Free Software Foundation, Inc.,                                       *
 *    59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 *                                                                          *
 * ************************************************************************ *
 *    To contact the author, please write to:                               *
 *    Rafael Santos Pereira da Silva <rafappr99@gmail.com>                  *
 *    Victor Cajuba  <victorcajuba@gmail.com>                               *
 *    Webpage: http://www.poli.br                                           *
 *    Phone: +55 (81) 99345-0341                                            *
 * ************************************************************************ *
 * 
 */

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>

#define DEBUG 0

static int recur = 0;

void help(void);
int entrada(char letra[][2], char url[]);
int quant_graf(char letra[][2], char *graf, int i);
int verifica(int i, char letra[][2], char reli, char relf, int para[]);/*reli = relacao inicial// relf = relacao final*/
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
    int i, r, opt, para[300],
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

    printf("\nDigite \"--\" para parar o programa\n");

    while(1)
    {
        printf("\nAutomatos: %s\n", graf);
        printf("Digite uma relacao entre os lugares existentes:\n");
        scanf("%c%c", &rel[0], &rel[1]);
        __fpurge(stdin);

        if(rel[0]=='-' && rel[1]=='-')
            break;

        recur = 0;

        r = verifica(i, letra, rel[0], rel[1], para);

        if(r)
        {
            if(recur != 1)
                printf("Circuito\n");
        }
        else
            printf("Nao ha conexao\n");

    }

    return EXIT_SUCCESS;
}

int verifica(int i, char letra[][2], char reli, char relf, int para[])/*reli = relacao inicial// relf = relacao final*/
{
    int k, r = 0, j;

    if(!recur)
        for(k = 0; k < i; k++)
        {
            if(reli == letra[k][0])
            {
                if(letra[k][1] == relf)
                {
                    printf("Caminho\n");
                    break;
                }
            }
        }

    for(k = 0; k < i; k++)
    {
        if(reli == letra[k][0])
        {
            for(j = 0; j < recur; j++)
            {
                if(para[j] == k)
                    break;                    
            }
            if(j == recur)
            {
                para[recur] = k;
                recur++;
            }
            else
                continue;
            if(letra[k][1] == relf)
            {
                r = 1;
                break;
            }
            else
            {
                r = verifica(i, letra, letra[k][1], relf, para);
                if(r)
                    break;
            }
        }
    }

    return r;
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
    {
        printf("erro no carregamento do arquivo\n");
        exit(EXIT_FAILURE);
    }

    while(fscanf(arquivo, "%c %c\n", &letra[i][0], &letra[i][1]) != EOF) 
        i++;

    printf("Relacoes existentes no arquivo\n");

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
    printf("\nOptions:\n"); 
    printf("\t-h, --help\n\t\tShow this help.\n");
    printf("\t-f, --flag\n\t\tCall the arquivo.txt\n");
    printf("\nQuit:\n\t Para sair basta digitar na entrada \"--\"\n"); 
    printf("\nAuthor:\n by %s \n\n", "Grupo1"); 
    exit(EXIT_FAILURE);
}

