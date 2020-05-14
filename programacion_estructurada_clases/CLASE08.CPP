/*   E . S . I . M . E .  C U L H U A C A N
		ING. EN COMPUTACION
	      PROGRAMA ELABORADO POR:

	 *    ADAN GARCIA QUIROZ
	 *          C2M1
	 *   PROGRAMACION ESTRUCTURADA   */

/* Programa que realiza las 4 operaciones basicas
    SUMA, RESTA, MULTIPLICACION, DIVISION*/

#include"a:\pe.h"

void main()
{

 portada();
 limpia(15,3);
 marco(190,1,1,1,1,1);
 int opc;
 float a,b,r;

 gotoxy(5,3);	printf("Programa que Calcula cualquiera de las 4 operaciones basicas\n");

 gotoxy(10,10);	printf("Inserte un numero:");
 scanf("%f",&a);
 gotoxy(10,12);	printf("Inserte otro numero:");
 scanf("%f",&b);

menu:
  clrscr();
 marco(190,1,1,1,1,1);
  gotoxy(15,6);  printf("Que operacion desea realizar?\n\n");

   gotoxy(10,8);	textcolor(15);
   cprintf("1 = Suma");
   gotoxy(10,9);	textcolor(14);
   cprintf("2 = Resta");
   gotoxy(10,10);	textcolor(13);
   cprintf("3 = Multiplicacion ");
   gotoxy(10,11);	textcolor(12);
   cprintf("4 = Division");
   gotoxy(10,12);	textcolor(11);
   cprintf("5 = Salir");

   printf("\n\n      Seleccione una opcion:  ");
   scanf("%d",&opc);

   if (opc==1)
      {
	r=a+b;
	printf("\nLa suma de %.0f + %.0f es: %.0f",a,b,r);
	getch();
	goto menu;
      }
      else if (opc==2)
      {
	r=a-b;
	printf("\nLa diferencia de %.0f - %.0f es: %.0f",a,b,r);
	getch();
	goto menu;
      }
      else if (opc==3)
      {
	r=a*b;
	printf("\nEl producto de %.0f * %.0f es: %.0f",a,b,r);
	getch();
	goto menu;
      }
      else if (opc==4)
      {
	r=a/b;
	printf("\nLa division de %.0f / %.0f es: %f",a,b,r);
	r=b/a;
	printf("\ny la division de %.0f / %.0f es: %f",b,a,r);
	getch();
	goto menu;
      }
      else if (opc==5)
      {
	  bien();
	  printf("\nPresione cualquier tecla...");
      }

      else
	{
	error();
	printf("Opcion no valida");
	getch();
	goto menu;
	}
  getch();
}