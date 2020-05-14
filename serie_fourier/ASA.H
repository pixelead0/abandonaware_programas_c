	/*   E . S . I . M . E .  C U L H U A C A N
		ING. EN COMPUTACION
	      PROGRAMA ELABORADO POR:

	 *    ADAN GARCIA QUIROZ
	 *          C5V1
	 *               SEPTIEMBRE / 2002 */

#include <dos.h>
#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <graphics.h>
#include <stdlib.h>

void presentacion(void);	// Presentacion en modo Grafica
void graficos(void);		// Carga graficos
void error(void);
void bien(void);
void entra(int color);
void sale(void);
void sale2(void);
void sale3(void);

void linea(int startx, int starty,int endx, int endy,int color);
void circulo(int x_centro, int y_centro,int radio, int color);
void puntocirculo(int x, int y, int x_centro, int y_centro, int color);

void error(void)
{
  sound(200);    delay(500);
  nosound();
}

void bien(void)
{
  sound(2200);    delay(800);
  sound(1800);    delay(900);
  sound(2000);    delay(500);
  sound(3600);    delay(500);
  nosound();
 }

void presentacion(void)
{
 graficos();
 rectangle(0,0,639,479);
 rectangle(10,10,629,469);
 setfillstyle(1,1);
 floodfill(320,240,WHITE);
 settextjustify(CENTER_TEXT,CENTER_TEXT);
 settextstyle(TRIPLEX_FONT,HORIZ_DIR,6);
 outtextxy(320,50,"ANALISIS DE");
 outtextxy(320,110,"SE¥ALES");
 outtextxy(320,170,"ANALOGICAS");
 settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
 outtextxy(320,250,"SERIE DE");
 outtextxy(320,300,"FOURIER");
 settextjustify(LEFT_TEXT,LEFT_TEXT);
 settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
 outtextxy(465,460,"Septiembre /2002");
 outtextxy(465,445,"Garcia Quiroz Adan");
 settextjustify(CENTER_TEXT,LEFT_TEXT);
 setcolor(14);
 outtextxy(320,479,"Presione Enter Para Continuar");
 getche();
// closegraph();
}

int gd=DETECT,gm,errorcode;
void graficos(void)
{
 gd=VGA; gm=VGAHI;
 initgraph(&gd,&gm,"d:\\tc\\bgi");
}

/* Dibuja una linea por el metodo de BRESENHAM */
void linea(int startx, int starty, /*puntos de inicio */
	   int endx, int endy, /* puntos hasta donde llega la linea */
	   int color) /* color de la linea*/
 {
  register int v, distancia;
  int x=0, y=0, delta_x, delta_y;
  int incy, incx;
  int t;

  /*Calcula las distancia entre los dos puntos */
  delta_x=endx - startx;
  delta_y=endy - starty;

  /* Hacia donde debe de ir la linea ?? */
  if (delta_x>0) incx =1;
  else if (delta_x==0) incx =0;
  else incx= -1;

  if (delta_y>0) incy =1;
  else if (delta_y==0) incy =0;
  else incy= -1;

  delta_x = abs(delta_x);
  delta_y = abs(delta_y);

 if (delta_x>delta_y) distancia=delta_x;
 else distancia= delta_y;

 /* Ahora si a dibujar se ha dicho */
 for (t=0; t<distancia+1; t++) {
   putpixel(startx, starty, color);
   x+= delta_x;
   y+= delta_y;
   if (x>distancia) {
      x-=distancia;
      startx += incx;
     }
   if (y>distancia) {
      y-=distancia;
      starty += incy;
     }
  }
 }
float asp_ratio=1.0;

void circulo(int x_centro, int y_centro, int radio, int color)
{
 register int x, y, delta;
 y=radio;delta=3-2*radio;
 for(x=0; x<y; ){
   puntocirculo(x,y,x_centro, y_centro, color);

   if (delta<0)
      delta +=4*x+6;
   else {
     delta +=4*(x-y)+10;
     y--;
    }
    x++;
   }
  x=y;
  if(y) puntocirculo(x,y,x_centro, y_centro, color);
  }

  /* Dibuja el circulo punto x punto */
  void puntocirculo(int x, int y, int x_centro, int y_centro, int color)
  {
   int startx, endx, x1, starty, endy, y1;

   starty=y*asp_ratio;
   endy=(y+1)*asp_ratio;
   startx=x*asp_ratio;
   endx=(x+1)*asp_ratio;

   for (x1=startx; x1<endx; ++x1) {
    putpixel(x1+x_centro, y+y_centro, color);
    putpixel(x1+x_centro, y_centro-y, color);
    putpixel(x_centro-x1, y_centro-y, color);
    putpixel(x_centro-x1, y+y_centro, color);
   }

   for (y1=starty; y1<endy; ++y1) {
    putpixel(y1+x_centro, x+y_centro, color);
    putpixel(y1+x_centro, y_centro-x, color);
    putpixel(x_centro-y1, y_centro-x, color);
    putpixel(x_centro-y1, x+y_centro, color);
   }
}

void entra(int color)
{
// coordenadas de el circulo (310,240,400);
 int x_centro=310, y_centro=240, radio=400;
  while (radio)
  {
  circulo(x_centro, y_centro, radio,color);
  radio--;
  }
}


void sale(void)
{
// coordenadas de el circulo (310,240,400);
 int x_centro=310, y_centro=240, radio=0, max=400;
// int max=radio;
 while (radio<=max)
 {
  circulo(x_centro, y_centro, radio, 0);
  radio++;
 }
}

void sale2(void)
{

 int starty=0, endy=480;
 register int i, begin, end;
 begin=0;
 end=640;
 for (i=begin; i<=end; i++){
  linea(i,starty, i, endy, 0);
  }
 }


void sale3(void)
{

int starty=0, endy=480;
 register int i, begin, end;
 begin=640;
 end=0;
 for (i=begin; i>=end; i--){
  linea(i,starty, i, endy, 0);
  }
 }