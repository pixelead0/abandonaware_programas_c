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
 limpia(10,3);
 marco(25,24,30,30,31,31);

 gotoxy(25,11);printf("Programa que lee tres numeros,");
 gotoxy(27,12);printf("los ordena ascendentemente");
 gotoxy(26,13);printf("y manda un mensaje diciendo");
 gotoxy(27,14);printf("si estaban ordenados o no");
 getch();
 limpia(14,6);
 marco(24,22,250,30,31,12);

 int a,b;
 int c,d,ord;
 gotoxy(12,3);	printf("Dame el valor de A ");
 scanf("%d",&a);
 gotoxy(12,4);	printf("Dame el valor de B ");
 scanf("%d",&b);
 gotoxy(12,5);	printf("Dame el valor de C ");
 scanf("%d",&c);
 ord=0;
 if (a>b)
  {
   d=a;
   a=b;
   b=d;
   ord=1;
  }
 if (b>c)
  {
   d=b;
   b=c;
   c=d;
   ord=1;
  }
 if (a>b)
  {
   d=a;
   a=b;
   b=d;
  }

 gotoxy(25,10); printf (" Los numeros ordenados son:");
 gotoxy(30,11); printf (" %d %d %d",a,b,c);

 gotoxy(20,15);
 if(ord==0)
 {
  bien();
  printf("Estaban ordenados");
 }
 else
  {
  error();
  printf("Estaban desordenados");
  }

 getch();
}
