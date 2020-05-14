/*   E . S . I . M . E .  C U L H U A C A N
		ING. EN COMPUTACION
	      PROGRAMA ELABORADO POR:

	 *    ADAN GARCIA QUIROZ
	 *          C2M1
	 *   PROGRAMACION ESTRUCTURADA   */

#include"a:\pe.h"

void main()
{
 portada();
 limpia(5,7);
 marco(169,145,4,4,4,4);
 gotoxy(30,11);	printf("Programa que calcula");
 gotoxy(32,12);	printf("la multiplicacion");
 gotoxy(29,13);	printf("de dos numeros enteros");
 gotoxy(28,14);	printf("mediante sumas sucesivas");

 getch();
 limpia(10,4);
 marco(176,178,191,218,217,192);

 int a,b,a1;
 int p;

 pidenumero:
 gotoxy(10,10);	printf("Dame el valor del pirmer numero");
 gotoxy(42,10);	scanf("%d",&a1);
 gotoxy(10,12);	printf("Dme el valor del segundo numero");
 gotoxy(42,12);	scanf("%d",&b);
 a=a1;

 if((a<=0) || (b<=0))
    {
     error();
     gotoxy(25,15); textcolor(12+blink);
     clreol();
     cprintf("Solo numeros positivos");
     gotoxy(42,10);
     clreol();
     gotoxy(42,12);
     clreol();
     goto pidenumero;
    }

 p=0;
 while(a>0)
 {
  p=p+b;
  a=a-1;
  }

 gotoxy(30,18); printf("%d * %d = %d",a1,b,p);
 getch();
}
