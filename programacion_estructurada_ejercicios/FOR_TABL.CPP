/*   E . S . I . M . E .  C U L H U A C A N
		ING. EN COMPUTACION
	      PROGRAMA ELABORADO POR:

	 *    ADAN GARCIA QUIROZ
	 *          C2M1
	 *   PROGRAMACION ESTRUCTURADA   */
/* Programa que visualiza cualquier tabla de multiplicar usando FOR */

#include"d:\c4v4\pe\pe.h"

void main()
{

 portada();
 limpia(14,4);
 marco(25,22,250,30,31,12);

  int m,n, tabla;
  gotoxy(15,4);	printf("Programa que imprime cualquier tabla de multiplicar");
  gotoxy(35,5);	printf("Usando FOR");
  gotoxy(15,8);	printf("Cual es la tabla que desea? ");
  gotoxy(30,9);	scanf("%d",&n);
  m=1;

  bien();
  window(30,12,50,23);
  limpia(15,0);

 for (m=1; m<=10; m++)
  {
   tabla=n*m;
   cprintf("\n\r %d x %d = %d",n,m,tabla);
  }
getch();
}