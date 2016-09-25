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
    int i,ent[20][2],saida[20][2],posicoes[20][3],
        j,/*numero de automatos*/
        xtela, ytela, /*valores centrais*/
        l, k; /*variaveis de controle*/
    float raio = 20.0, /*320 e 240 dimencoes do bitmap - sugestao*/
          posx, posy;
    double graus,anguloatual=0;
    
    /*configuracoes alegro*/
    if(install_allegro(SYSTEM_NONE, &errno, atexit)!=0)
        exit(EXIT_FAILURE);
         
    set_color_depth(16);
    get_palette(pal);
    /*fim parte1 - alegro*/
             
    /*comeco do codigo*/

    i = entrada(letra);
    j = quant_graf(letra, graf, i);
    graus = (2*PI)/j;    /* (2*PI)/j */
    xtela = 600*j/8;
    ytela = 400*j/8;
    
    BITMAP *buff = create_bitmap(xtela,ytela);
    if(buff == NULL)
    {
        printf("Could not create buffer!\n");
        exit(EXIT_FAILURE);
    }
    /*Create a buffer for smooth animation.*/
    for(k = 0;k<=l;k++)
    { 
        posx= xtela/2 +cos(anguloatual)*raio*j;
        posy= ytela/2 +cos(anguloatual)*raio*j;
        anguloatual+= graus;
        posicoes[k][0] = graf[k];
        posicoes[k][1] = posx;
        posicoes[k][2] = posy;
        printf("posicoes %d\n", posicoes[k][1]);
        textprintf_ex(buff, font, posx, posy, CORVERDE, CORPRETO, "%c", graf[k]);
    }
    for(k=0;k<i;k++)
        for(l = 0; l<j; l++)
        {
            if(letra[k][0] == posicoes[l][0])
            {
                ent[k][0]  = posicoes[l][1];   
                ent[k][1]  = posicoes[l][2];   
            }
            if(letra[k][1] == posicoes[l][0])
            {
                saida[k][0]  = posicoes[l][1];
                saida[k][1]  = posicoes[l][2];
            }
        }    
    
    for(k = 0;k < i ; k++ )
        seta(buff, ent[k][0], ent[k][1], saida[k][0], saida[k][1]);
         

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
{
    int v[8], xa, y, xd, yd;
    float  A,x1,x2,x3,y1,y2,y3,sent,cost;/*circunferencia1*/
    float  seno1,seno2,cosseno1,cosseno2,distancia1,distancia2;
    int xmedio,ymedio;/*ponto medio entre elas*/
    
    xmedio = (x_circ1+x_circ2)/2;
    ymedio = (y_circ1+y_circ2)/2;

    distancia2=sqrt(pow(xmedio - x_circ2,2)+pow(ymedio - y_circ2,2)); /*distacia entre os dois centros*/ 

    distancia1=sqrt(pow(xmedio - x_circ1,2)+pow(ymedio - y_circ1,2)); /*distacia entre os dois centros*/ 

    seno2 = (ymedio - y_circ2)/distancia2; /*calculo do seno do segundo ponto*/
    cosseno2 = (xmedio -  x_circ2)/distancia2; /*calculo do cosseno do segundo ponto*/
    seno1 = (ymedio - y_circ1)/distancia1; /*calculo do seno do primeiro ponto*/ 
    cosseno1 = (xmedio -  x_circ1)/distancia1; /*calculo do cosseno do segundo ponto*/

    circle(buff, x_circ1, y_circ1,20, CORVERDE);
    ciracle(buff, x_circ2, y_circ2, 20, CORAMARELO); 

    v[0]=x_circ1+20*cosseno1;
    v[1]=y_circ1+20*seno1;
    v[6]=x_circ2+20*cosseno2;
    v[7]=y_circ2+20*seno2;
    
    xa = (v[0] + v[6])/2;
    y = (v[1] + v[7])/2;
    xd = v[0] - v[6];
    yd = v[1] - v[7];
    xd = MODULO(xd);
    if(v[6]<v[0])
    {
        yd = MODULO(yd);
        if(v[7]<v[1])
            xd = -1 * MODULO(xd);
    }
    v[4]=v[2]=xa - yd*0.35;
    v[5]=v[3]=y - xd*0.35;
    
    A =sqrt(pow(v[6]-v[4],2)+pow(v[7]-v[5],2));

    sent=(v[7]-v[5])/A;
    cost=(v[6]-v[4])/A;
    x1=v[6];
    y1=v[7];
    x2=v[6] -10*cost +4*sent;
    y2=v[7] -10*sent -4*cost;
    x3=v[6] -10*cost -4*sent;
    y3=v[7] -10*sent +4*cost;


    spline(buff, v , CORVERDE);

    triangle(buff, x1,y1,x2,y2,x3,y3,CORVERMELHO);

    return 0;
}

