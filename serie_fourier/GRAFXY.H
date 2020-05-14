	/*   E . S . I . M . E .  C U L H U A C A N
		ING. EN COMPUTACION
	      PROGRAMA ELABORADO POR:

	 *    ADAN GARCIA QUIROZ
	 *          C5V1
	 *               SEPTIEMBRE / 2002 */

/*GRAFXY.H
Su uso se centra en la grafica de puntos y figuras en la pantalla,
principalmente de "graphics.h", pero tomando a la pantalla
como si fuera el plano cartesiano.
*/
#ifndef __GRAPHICS_H
#include <graphics.h>
#endif

#include "vector.h"
//#include"stdlib.h"
#include "ifuncade.h"
#include <stdio.h>

#define CONECTAR 1
#define NO_CONECTAR 0

class CRegionXY
{

protected:

//coordenadas de la region XY, (VALOR EN COORDENAS REALES)
double Xmin;
double Xmax;
double Ymin;
double Ymax;

//VENTANA MARCO
//coordenadas de la ventana donde se mostrara el grafico (VALOR EN PIXELES)
int x1;
int x2;
int y1;
int y2;

public:
//constructor
	CRegionXY(double XMIN, double XMAX, double YMIN, double YMAX)
	{
	Xmin=XMIN;
	Xmax=XMAX;
	Ymin=YMIN;
	Ymax=YMAX;
	x1=0;
	x2=getmaxx();
	y1=0;
	y2=getmaxy();
	}

	CRegionXY(double XMIN, double XMAX, double YMIN, double YMAX,
		  int X1,int Y1, int X2, int  Y2)
	{
	Xmin=XMIN;
	Xmax=XMAX;
	Ymin=YMIN;
	Ymax=YMAX;
	x1=X1;
	y1=Y1;
	x2=X2;
	y2=Y2;
	}

	double xmin(){ return Xmin; };
	double xmax(){ return Xmax; };
	double ymin(){ return Ymin; };
	double ymax(){ return Ymax; };

	//Funciones Miembro
	vector conver(vector P);
	vector converl(vector R);
	void punto(vector P,char color, char conectar);
	void punto(double x,double y,char color, char conectar);
	void punto(double x,double y,int color,double minX,double maxX,double minY,double maxY);
	void Graficar( char Formula[], char conectar, char color, float Particion);
	void Ejes();

};//fin de la clase CRegionXY

//Convierte un vector R de coordenadas reales a un vector M de
//coordenadas enteras, relativas al tama¤o de la pantalla
//II=(0,0) SD=(getmaxx,getmaxy)
//      |          |
//    entero      entero
//
//Donde la pantalla representara a una regi¢n rectangular R donde
//las esquinas son los vectores de coordenadas reales II y SD;
//II=InferiorIzquierda de la pantalla
//SD=SuperiorDerecha de la pantalla
//En resumen la Region R se transforma a una region rectangular W pero
//de coordenadas enteras que encaja en la pantalla

/*
vector CRegionXY::conver(vector P)
{

return vector( (P.x-Xmin)*getmaxx()/(Xmax-Xmin)+1, 	//Conversion de real a entero x-->m
		getmaxy()-(P.y-Ymin)*getmaxy()/(Ymax-Ymin)+1 );//Conversion de real a entero y-->n
}
*/

vector CRegionXY::conver(vector P)
{

return vector( (P.x-Xmin)*(x2-x1)/(Xmax-Xmin)+x1+1, 	//Conversion de real a entero x-->m
		y2-(P.y-Ymin)*(y2-y1)/(Ymax-Ymin)+1 );//Conversion de real a entero y-->n
}


vector CRegionXY::converl(vector R)
{
vector M;
M=conver(R);
M=vector(M.x,getmaxy()-M.y);

return M;
}

//Grafica un punto que representa al punto P en la region rectangular
//especificada por II y SD y lo pinta del color especificado en color

void CRegionXY::punto(vector P,char color, char conectar = 0)
{
 vector M=conver(P);

 if( x1< M.x && M.x< x2 && y1< M.y && M.y< y2) //para que no se pinte fuera de la ventana marco
 {
  if( conectar )
   {
    if(getcolor()!=color)moveto(M.x,M.y);
    setcolor(color);
    lineto(M.x,M.y); //conecta los puntos
   }
  else
   putpixel(M.x,M.y,color);  //grafica la funcion en pantalla

 }

}

void CRegionXY::punto(double x, double y,char color, char conectar = 0)
{
punto( vector(x,y) , color , conectar );
}


//Igual que la funcion anterior pero sin vectores
//Grafica un punto en la pantalla pero tomando coordenadas reales (x,y)
//y un color especificado en color, donde su dominio es la region
//rectangular de esquinas:
//inferior izquierda (minX,minY) hasta superior derecha (maxX,maxY)

void CRegionXY::punto(double x,double y,int color,double minX,double maxX,double minY,double maxY){
//Se establece las particiones de la pantalla (RANGO DE VISION DE LA FUNCION)
//desde (minX,minY) hasta (maxX,maxY)
int m,n;

m=(x-minX)*getmaxx()/(maxX-minX)+1; 	//Conversion de real a entero x-->m
n=getmaxy()-(y-minY)*getmaxy()/(maxY-minY)+1;//Conversion de real a entero y-->n

putpixel(m,n,color);  //grafica la funcion en pantalla

}

void CRegionXY::Ejes()
{
//Se grafican los ejes cartesianos
vector M = conver(vector(0,0));
setcolor(14);
int x = (int) M.x , y = (int) M.y;


line(x, y1, x, y2); //eje y
line(x1,y-1,x2,y-1); // eje x

char str[18];

int i;
float num;

setcolor(15);

for(i=0;i<20;i++)
{
//Eje Y
num = Ymin + ( Ymax-Ymin )/20*i;
//gcvt(num, 6, str);
sprintf(str,"%g",num);

M=conver(vector(0,num));
x = (int) M.x;
y = (int) M.y;

fillellipse( x, y, 2, 1);
outtextxy(x, y, str);

 if(i%2)
 {
 //Eje X
 num = Xmin + ( Xmax-Xmin )/20*i;
// gcvt(num, 6, str);
 sprintf(str,"%g",num);
 M=conver(vector(num,0));
 x = (int) M.x;
 y = (int) M.y;

 fillellipse( x, y, 1, 3);
 outtextxy(x, y-10, str);
 }

}

}


void CRegionXY::Graficar( char *Formula, char conectar = 0, char color = 9, float Particion = 0.01)
{

float x,y;

CFuncad funcion(Formula,"X");
//Funcion a graficar y=f(x)

for(x=Xmin;x<Xmax;x+=Particion)
{
  y=funcion.f(x);
  if(!funcion.error)
  punto( vector(x,y), color, conectar);
  else punto( vector(x,y), GREEN, conectar);
}

}

//void CRegionXY::buscar_domino( char *Formula )
//{


void autoini(char *ruta)
{
int gd=DETECT,gm;
initgraph(&gd,&gm,ruta);
}


