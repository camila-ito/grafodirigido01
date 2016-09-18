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
  
#define IMAGENAME "ex8.bmp" /* nome do arquivo de imagem*/ 
#include <stdio.h>
#include <allegro.h>
  
 int main(void)
{
      BITMAP *buff;
      PALETTE pal;
      double x_circulo1, y_circulo1;
      double x_circulo2, y_circulo2;
      float y1, distancia=0, x1, tang;
      double ang, cosse, raio, sen, cosse2, cossef, grau;
         
      if(install_allegro(SYSTEM_NONE, &errno, atexit)!=0)
          exit(EXIT_FAILURE);
           
      set_color_depth(16);
      get_palette(pal);
               
      /*Create a buffer for smooth animation.*/
      buff = create_bitmap(320,240);
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
      scanf("%lf", &y_circulo2)
      
      distancia = sqrt(pow(x_circulo2 - x_circulo1,2)+pow(y_circulo2 - y_circulo1,2)); 
      
      /*distacia entre os dois centros*/ 
      printf("distancia %f\n ",distancia);
      printf("divisao %f \n",(x_circulo2 - x_circulo1)/y_circulo2 - y_circulo1);
      printf("diferenca y %f \n",y_circulo2 - y_circulo1);
     
      ang= acos((y_circulo2 - y_circulo1)/(x_circulo2 - x_circulo1));/*angulo total de abertura*/

      printf("ang %f\n",ang);
      grau = ang*180/3.14; 
      printf("grau %f\n",grau);
      sen = sin(grau - 60);
      cosse = cos(grau-60);
     
      y1 = y_circulo1 + sen*distancia; /*descubro a altura do centro */
      x1 = x_circulo1 + cosse *distancia; /*o valor em x do cento*/
      tang = atan((y_circulo2-y_circulo1)/(x_circulo2-x_circulo1));

      raio = sqrt(pow(x1 - x_circulo1,2) + pow(y1 - y_circulo1,2));
      putpixel(buff,x1,y1,CORVERDE);

      arc(buff,x1,y1,itofix(tang),itofix(tang+60), raio ,CORAMARELO);

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
