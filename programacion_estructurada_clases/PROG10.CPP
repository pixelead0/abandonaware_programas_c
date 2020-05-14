/*Programa que evalue un polinomio de grado n.Los datos de entrada*/
       /*son el valor de la variable y de los coeficientes*/
#include <stdio.h>
#include <conio.h>
#include <dos.h>
  void main ()
  {
  clrscr ();
  int a,c,g,i,n,x,var[50];
  printf ("\n Dame el grado del polinomio:");
  scanf ("%d",&g);
  printf ("\n Dame el valor de la variable:");
  scanf ("%d",&x);
     for (i=0;i<g;i++)
     {
       printf ("\n El coeficiente %d es :",i);
       scanf ("%d",&var [i]);
     }

     i=0;
     a=0;
	do{
	a=a+x*var[i];
	i++;
	}
   while (i<g);
     printf ("\n El resultado es :%d",a);
     printf ("\n Presione cualquier tecla para salir");
   getch ();
   }
