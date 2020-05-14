/*   E . S . I . M . E .  C U L H U A C A N
		ING. EN COMPUTACION
	      PROGRAMA ELABORADO POR:

	 *    ADAN GARCIA QUIROZ
	 *          C2M1
	 *   PROGRAMACION ESTRUCTURADA   */

#include"d:\c4v4\pe\pe.h"
void main()
{
portada();
limpia(10,5);
marco(155,155,243,243,243,243);

gotoxy(20,3);	printf("Programa que calcula los numeros perfectos");
gotoxy(25,4);	printf("comprendidos entre el 1 y el 1000");
textcolor(14+blink);
gotoxy(21,6);	cprintf("(un numero perfecto es aquel en el que la");
gotoxy(23,7);	cprintf("suma de sus divisores excepto el mismo");
gotoxy(30,8);	cprintf("es igual a dicho numero)");
int n,r,suma,j,i;

n=1000;
gotoxy(1,12);
for(i=1; i<=n; i++)
  {
   suma=0;
   for (j=1; j<i; j++)
    {
     r=i%j;
     if(r==0)
      {
       suma=suma+j;
      }
     }
   if(suma==i)
    {
    printf("\n\r\t%d es numero perfecto",i);
    }
  }
 getch();
}