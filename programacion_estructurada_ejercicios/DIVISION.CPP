/*   E . S . I . M . E .  C U L H U A C A N
		ING. EN COMPUTACION
	      PROGRAMA ELABORADO POR:

	 *    ADAN GARCIA QUIROZ
	 *          C2M1
	 *   PROGRAMACION ESTRUCTURADA
	 *               MARZO / 2001 */

#include"d:\c4v4\pe\pe.h"
void main()
{

 portada();

 limpia(0,7);
 marco(169,145,4,4,4,4);
 gotoxy(30,11);	printf("Programa que obtiene");
 gotoxy(28,12);	printf("el cociente y el residuo");
 gotoxy(29,13);	printf("de dos numeros enteros");
 gotoxy(28,14);	printf("mediante restas sucesivas");

 getch();
 limpia(15,3);
 marco(1,64,2,4,5,6);
 int a,b;
 int c;
pidenumero:
 gotoxy(15,10);	printf("Dame el valor del divisor");
 gotoxy(42,10);	scanf("%d",&a);
 gotoxy(18,12);	printf("Cual es el dividendo");
 gotoxy(42,12);	scanf("%d",&b);

 if((a<=0) || (b<=0))
    {
     error();
     gotoxy(25,15); textcolor(12);
     clreol();
     cprintf("Solo numeros positivos");
     gotoxy(42,10);
     clreol();
     gotoxy(42,12);
     clreol();
     goto pidenumero;
    }

 if(a<b)
    {
     error();
     gotoxy(25,15); textcolor(10);
     clreol();
     cprintf("El divisor debe ser menor que el dividendo");
     gotoxy(42,10);
     clreol();
     gotoxy(42,12);
     clreol();
     goto pidenumero;
    }


 c=0;
 while(a>=b)
 {
  a=a-b;
  c=c+1;
  }

  gotoxy(25,20);	textcolor(14+blink);
  cprintf("Cociente %d, resto %d",c,a);
 getch();

}
