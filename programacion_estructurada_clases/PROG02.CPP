/*   E . S . I . M . E .  C U L H U A C A N
		ING. EN COMPUTACION
	      PROGRAMA ELABORADO POR:

	 *    ADAN GARCIA QUIROZ
	 *          C2M1
	 *   PROGRAMACION ESTRUCTURADA   */
/* Programa que visualiza cualquier tabla de multiplicar usando FOR */

#include"a:\pe.h"

void main()
{
 portada();
 int mayor=0;
 int neg=0;
 int i=1;
 int num;


 limpia(15,1);
 marco(176,176,4,4,4,4);
 gotoxy (15,2);
 printf ("Programa que lee una secuencia de numeros no nulos");
 gotoxy(10,3);
 printf ("e imprime cual fue el mayor, y si se introducieron numeros negativos");

 textbackground(BROWN);
 gotoxy (55,20);
 cprintf("                         ");
 gotoxy (55,21);
 cprintf("Para terminar el programa");
 gotoxy (55,22);
 cprintf(" debe de teclear un cero ");
 gotoxy (55,23);
 cprintf("                         ");

 window  (25,8,51,15);
 limpia(15,4);

 do{
  cprintf ("\n\r  Dame el numero (%d) : ", i);
  scanf  ("%d",&num);
  if (num>mayor)
    mayor=num;
  else if (num<0)
    neg=1;
    i++;
   }while(num!=0);



 window  (1,1,80,25);
 textbackground(BLUE);
 textcolor(LIGHTGREEN);


  for (i=20; i<=24; i++)
   {
   gotoxy(55,i);
   clreol();
   }

 gotoxy(28,18);
 cprintf("El numero mayor fue %d", mayor);
 if(neg!=1)
 {
  gotoxy(23,19);
  cprintf("Introduciste solo numeros positivos");
 }
 else
 {
 gotoxy(31,20);
 cprintf("Si hay negativos");
 }


 textbackground(BLACK);
 textcolor(LIGHTGRAY);

 gotoxy(37,25);
 cprintf("Presione cualquier tecla para terminar...");
 getch();
}
