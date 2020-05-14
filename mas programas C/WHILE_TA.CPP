/*   E . S . I . M . E .  C U L H U A C A N
		ING. EN COMPUTACION
	      PROGRAMA ELABORADO POR:

	 *    ADAN GARCIA QUIROZ
	 *          C1M1
	 *   PROGRAMACION ESTRUCTURADA   */
/* Programa que visualiza cualquier tabla de multiplicar usando WHILE */

#include<conio.h>
#include<stdio.h>

void main()
{
 int m,n, tabla;
 clrscr();
 printf("Programa que imprime cualquier tabla de multiplicar");
 printf("\n Cual es la tabla que desea? ");
 scanf("%d",&n);
 m=1;
 while (m<=10)
  {

   tabla=n*m;
   printf("\n %d x %d = %d",n,m,tabla);
   m++;
  }
  getch();
}