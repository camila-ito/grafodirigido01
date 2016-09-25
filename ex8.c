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
 * $gcc ex8.c -o ex8.x -Wall `allegro-config --cflags --libs`
 */


/* Definicoes de algumas cores */

#define CORBRANCO (makecol(255,255,255))
#define CORPRETO 1
#define CORCINZA (makecol(160,160,160))
#define CORAZUL (makecol(0, 0, 255))
#define CORVERDE (makecol(0, 255, 0))
#define CORAMARELO (makecol(255,255,100))
#define CORVERMELHO (makecol(255, 0, 0))
#define MODULO(x) ((x)>=0?(x):(-1*(x)))

#define IMAGENAME "ex8.bmp" /* nome do arquivo de imagem*/ 
#include <stdio.h>
#include <allegro.h>
#include <math.h>

int main(void)
{
    BITMAP *buff;
    PALETTE pal;
    int v[8], xa, y, xd, yd, xmedio, ymedio;
    float A, x1, x2, x3, y1, y2, y3, sent, cost, x_circ1, y_circ1;
    float seno1, seno2, cosseno1, cosseno2; distancia1, distancia2, x_circ2, y_circ2;
    if(install_allegro(SYSTEM_NONE, &errno, atexit)!=0)
        exit(EXIT_FAILURE);

    set_color_depth(16);
    get_palette(pal);

    /*Create a buffer for smooth animation.*/
    buff = create_bitmap(600,400);
    if(buff == NULL)
    {
        printf("Could not create buffer!\n");
        exit(EXIT_FAILURE);
    }
    /*comeco do codigo*/

    printf("digite o valor do x circulo1\n");
    scanf("%lf",&x_circulo1);
    printf("digite o valor y do circulo1\n");
    scanf("%lf",&y_circulo1);
    printf("digite o valor do x do circulo2\n");
    scanf("%lf",&x_circulo2_);
    printf("digite o valor do y do circulo2\n");
    scanf("%lf", &y_circulo2);

    xmedio = (x_circ1+x_circ2)/2;
    ymedio = (y_circ1+y_circ2)/2;

    distancia2=sqrt(pow(xmedio - x_circ2,2)+pow(ymedio - y_circ2,2));
    distancia1=sqrt(pow(xmedio - x_circ1,2)+pow(ymedio - y_circ1,2));

    seno2 = (ymedio - y_circ2)/distancia2;
    cosseno2 = (xmedio - x_circ2)/distancia2;
    seno1 = (ymedio - y_circ1)/distancia1;
    cosseno1 = (xmedio - x_circ1)/distancia1;

    circle(buff, x_circ1, y_circ1, 20, CORVERDE);
    circle(buff, x_circ2, y_circ2, 20, CORAMARELO);

    v[0]=x_circ1+20*cosseno1;
    v[1]=y_circ1+20*seno1;
    v[6]=x_circ2+20*cosseno2;
    v[7]=y_circ2+20*seno2;

    xa = (v[0]+v[6])/2;
    y = (v[1]+v[7])/2;
    xd = v[0] - v[6];
    yd = v[1] - v[7];
    xd = MODULO(xd);
    if(v[6]<v[0])
    {
        yd = MODULO(yd);
        if(v[7]<v[1])
            xd = -1* MODULO(xd);
    }   
    v[4] = v[2] = xa - yd*0.35;
    v[5] = v[3] = y - xd*o.35;
   
  /*  if(v[5]<v[7])
    {*/     
  /*  d=sqrt(pow(v[6]-x_circ2,2)+pow(v[7]-y_circ2,2));
    d/=2;
    if(v[0]<v[6]||(v[0]>v[6]&&v[1]<v[7]))
    {
        xm=x_circ2-(cos(45))*d;
        ym=y_circ2-(sin(45))*d);
        v[6]=xm-r/4.3;
        v[7]=ym-r/4.3;
    }
    else
    {
        xm=x_circ2+(cos(45)*d);
        ym=y_circ2+(sin(45)*d);
        v[6]=xm+r/4.3;
        v[7]=ym+r/4.3;
    }*/
    
    
    spline(buff, v, CORVERDE); 

    /*printf("Considerando que o primeiro circulo e a origem do indicador, qual a coordenada em que deseja o eixo x do primeiro circulo?(max 640)");
      scanf("%d", &x1);
      while(x1<0||x1>640)
      {
      scanf("%d", &x1);
      }*/    

    /*fim do codigo*/
    save_bitmap(IMAGENAME, buff, pal);
    destroy_bitmap(buff);
    allegro_exit();

    printf("Imagem %s salva com sucesso!\n", IMAGENAME);
    return EXIT_SUCCESS;
}
END_OF_MAIN();
