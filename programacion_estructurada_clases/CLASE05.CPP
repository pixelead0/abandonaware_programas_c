/*   E . S . I . M . E .  C U L H U A C A N
		ING. EN COMPUTACION
	      PROGRAMA ELABORADO POR:

	 *    ADAN GARCIA QUIROZ
	 *          C2M1
	 *   PROGRAMACION ESTRUCTURADA   */

/* Programa que visualiza cualquier tabla de multiplicar usando DO WHILE */

#include"a:\pe.h"

void main()
{
 long int fact,x,i;
 limpia(15,1);
 marco(1,1,1,1,1,1);

 gotoxy(15,3);	printf("Programa que calcula el factorial de un numero N");
 gotoxy(25,8);	printf("El numero debe estar entre 1 y 16");
otro:
 gotoxy(15,6);
 printf("Hasta que numero desea que se calcule el facorial: ");
 scanf("%ld",&x);

 if ((x<=0) || (x>16))
   {
    error();
    textcolor(LIGHTGREEN+blink);    gotoxy(25,8);
    cprintf("El numero debe estar entre 1 y 16");
    gotoxy(65,8);
    clreol();
    goto otro;
   }


window(30,9,50,24);
limpia(14,6);

  fact=1;
  for (i=1; i<=x; i++)
   {
    fact *=i;
    cprintf("\n\r %ld! = %ld",i,fact);
   }
   getch();
}