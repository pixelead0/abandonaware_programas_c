/*   E . S . I . M . E .  C U L H U A C A N
		ING. EN COMPUTACION
	      PROGRAMA ELABORADO POR:

	 *    ADAN GARCIA QUIROZ
	 *          C1M1
	 *   PROGRAMACION ESTRUCTURADA   */
/* Programa que visualiza cualquier tabla de multiplicar usando WHILE */

#include<conio.h>
#include<stdio.h>
#include<dos.h>

void main()
{

 int m,n, tabla;
 clrscr();
 printf("Programa que imprime cualquier tabla de multiplicar");
 printf("\nUsando WHILE\n\n");
 printf("\n Cual es la tabla que desea? ");
 scanf("%d",&n);
 m=1;
 while (m<=10)
  {

   tabla=n*m;
   printf("\n %d x %d = %d",n,m,tabla);
   m++;
  }
    sound(2200);
  delay(800);
  textcolor(15);
  gotoxy(30,20);
  cprintf("Fin");

  sound(1800);
  delay(900);
  textcolor(9);
  cprintf(" del");

  sound(2000);
  delay(500);
  textcolor(15);
  cprintf(" programa");

  sound(3600);
  delay(500);
  nosound();

  printf("\nPresione cualquier tecla...");
  getch();

}