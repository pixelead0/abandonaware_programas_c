/*   E . S . I . M . E .  C U L H U A C A N
		ING. EN COMPUTACION
	      PROGRAMA ELABORADO POR:

	 *    ADAN GARCIA QUIROZ
	 *          C1M1
	 *   PROGRAMACION ESTRUCTURADA   */

/*Programa que calcula el Maximo Comun Divisor de dos numeros enteros
	 positivos por medio del Algoritmo de Euclides*/

#include"d:\c4v4\pe\pe.h"
#include<stdlib.h>

void main ()
{
 portada();
 limpia(15,5);
 marco(184,220,189,189,251,251);

 int a,b,x,y,q,p,r;
 gotoxy(30,4);	printf ("Programa que calcula el");
 gotoxy(31,5);	printf ("Maximo Comun Divisor");
 gotoxy(22,6);	printf ("de dos numeros enteros por medio del ");
 gotoxy(31,7);	printf ("Algoritmo de Euclides");

 gotoxy(15,10);	printf ("Introduce el numero mayor:");
 gotoxy(42,10);	scanf ("%d",&x);
 gotoxy(15,12);	printf ("Introduce el numero menor:");
 gotoxy(42,12);	scanf ("%d",& y);
  a=x;
  b=y;

  p=(a/b);
  q=abs(p);
  r=a-(q*b);

  while (r!=0)
  {
  a=b;
  b=r;
  p=(a/b);
  q=abs(p);
  r=a-(q*b);
  }


  if(b!=1)
     {
      bien();
      gotoxy(20,18);	textcolor(14+blink);
      cprintf ("El Maximo Comun Divisor de %d y %d es: %d",x,y,b);
     }

 if (b==1)
 {
  error();
  gotoxy(20,18);	textcolor(12+blink);
  cprintf ("Los numeros: %d y %d son primos relativos porque",x,y);
  gotoxy(30,19);
  cprintf ("su Maximo Comun Divisor es uno.");
 }
 getch ();
 }
