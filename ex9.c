/**************************************************************************
 *  Copyright (C) 2005, 2015 by Dr.Beco                                   *
 *  rcb@beco.cc                                                           *
 *                                                                        *
 *  This program is free software; you can redistribute it and/or modify  *
 *  it under the terms of the GNU General Public License as published by  *
 *  the Free Software Foundation; either version 2 of the License, or     *
 *  (at your option) any later version.                                   *
 *                                                                        *
 *  This program is distributed in the hope that it will be useful,       *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *  GNU General Public License for more details.                          *
 *                                                                        *
 *  You should have received a copy of the GNU General Public License     *
 *  along with this program; if not, write to the                         *
 *  Free Software Foundation, Inc.,                                       *
 *  59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
  
/* Template para programa basico Allegro
 * que salva uma imagem em arquivo
 * Para compilar use:
 * $gcc ex9.c -o ex9.x -Wall -lm `allegro-config --cflags --libs`
 */
 
 /* Definicoes de algumas cores */

#define CORBRANCO (makecol(255,255,255))
#define CORPRETO 1
#define CORCINZA (makecol(160,160,160))
#define CORAZUL (makecol(0, 0, 255))
#define CORVERDE (makecol(0, 255, 0))
#define CORAMARELO (makecol(255,255,100))
#define CORVERMELHO (makecol(255, 0, 0))

#define MODULO(x) ((x)>=0 ? (x) : (-1*(x))
#define PI 3.14159265

#define IMAGENAME "ex9.bmp" /* nome do arquivo de imagem*/ 

#include <stdio.h>
#include <allegro.h>
#include <math.h> 

int entrada(char letra[][2]);
int quant_graf(char letra[][2], char *graf, int i);
int seta(BITMAP *buff, float x_circ1, float y_circ1, float x_circ2, float y_circ2);

/* --------------------------------------------------------------------------*/
/**
 * \brief 
 *
 * \return 
 */
int main(void)
{
    PALETTE pal;
    char letra[20][2], graf[20];
    int j,/*numero de automatos*/
        xtela, ytela; /*valores centrais*/
        l, k, /*variaveis de controle*/
    double x_circulo1, y_circulo1;
    double x_circulo2, y_circulo2;
    float raio = 20.0, /*320 e 240 dimencoes do bitmap - sugestao*/
          posx, posy;
    double ang, cosse, raio, sen, grau;
    
    /*configuracoes alegro*/
    if(install_allegro(SYSTEM_NONE, &errno, atexit)!=0)
        exit(EXIT_FAILURE);
         
    set_color_depth(16);
    get_palette(pal);
    /*fim parte1 - alegro*/
             
    /*comeco do codigo*/

    i = entrada(letra);
    j = quant_graf(letra, graf, i);
    graus = (2*PI)/n;    /* (2*PI)/j */
    xtela = 600*j/8;
    ytela = 400*j/8;
    
    BITMAP *buff = create_bitmap(xtela,ytela);
    if(buff == NULL)
    {
        printf("Could not create buffer!\n");
        exit(EXIT_FAILURE);
    }
    /*Create a buffer for smooth animation.*/
    
    /*raio = sqrt(pow(x1 - x_circulo1,2) + pow(y1 - y_circulo1,2)); calculo do raio*/
    
    putpixel(buff,x1,y1,CORVERDE); 

    arc(buff,x1,y1,itofix(tang),itofix(tang+60), raio ,CORAMARELO);
    circlefill(buff, x_circulo1, y_circulo1,20, CORAZUL);
    circlefill(buff, x_circulo2, y_circulo2, 20, CORAZUL);
    
    /*fim do codigo*/
    save_bitmap(IMAGENAME, buff, pal);
    destroy_bitmap(buff);
    allegro_exit();
    
    printf("Imagem %s salva com sucesso!\n", IMAGENAME);
    return EXIT_SUCCESS;
}
END_OF_MAIN();

/* --------------------------------------------------------------------------*/
/**
 * \brief 
 *
 * \param letra[][2]
 *
 * \return 
 */
int entrada(char letra[][2])
{
    int i = 0, k;
    FILE  *arquivo=NULL; 

    arquivo = fopen("entrada.txt", "r");

    if(arquivo==NULL)
        printf("erro no carregamento do arquivo\n");
        /*return EXIT_FAILURE;*/
    while(fscanf(arquivo, "%c %c\n", &letra[i][0], &letra[i][1]) != EOF) 
        i++;

    printf("letra:\n");
    for(k=0; k<i; k++)
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
    int k, j, m, l; /*variaveis de controle*/
    
    for(k = 0; k < 20; k++)
        graf[k] = 0;
    j = 0;
    l = 0;
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

    return j
}

int seta(BITMAP *buff, float x_circ1, float y_circ1, float x_circ2, float y_circ2)
{   int/* r,*/v[8], xa, y, xd, yd;
    float  A,x1,x2,x3,y1,y2,y3,sent,cost;/*circunferencia1*/
    float  seno1,seno2,cosseno1,cosseno2,distancia1,distancia2;/*d,xm,ym,*/
    int xmedio,ymedio;/*ponto medio entre elas*/
    
    xmedio = (x_circ1+x_circ2)/2;
    ymedio = (y_circ1+y_circ2)/2;

    distancia2=sqrt(pow(xmedio - x_circ2,2)+pow(ymedio - y_circ2,2)); /*distacia entre os dois centros*/ 

    distancia1=sqrt(pow(xmedio - x_circ1,2)+pow(ymedio - y_circ1,2)); /*distacia entre os dois centros*/ 

    seno2 = (ymedio - y_circ2)/distancia2;
    cosseno2 = (xmedio -  x_circ2)/distancia2
    seno1 = (ymedio - y_circ1)/distancia1;
    cosseno1 = (xmedio -  x_circ1)/distancia1;

    return 0;
}
