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

 int main(void)
{
      PALETTE pal;
      int n,/*numero de automatos*/
          xtela, ytela; /*valores centrais*/
          l, k, /*variaveis de controle*/
      double x_circulo1, y_circulo1;
      double x_circulo2, y_circulo2;
      float y1, distancia=0, x1, tang;
      double ang, cosse, raio, sen, grau;
      
      /*configuracoes alegro*/
      if(install_allegro(SYSTEM_NONE, &errno, atexit)!=0)
          exit(EXIT_FAILURE);
           
      set_color_depth(16);
      get_palette(pal);
      /*fim parte1 - alegro*/
               
      /*comeco do codigo*/

      graus = (2*PI)/n; 
      xtela = 600*n/8;
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

