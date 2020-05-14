/*   E . S . I . M . E .  C U L H U A C A N
		ING. EN COMPUTACION
	      PROGRAMA ELABORADO POR:

	 *    ADAN GARCIA QUIROZ
	 *          C2M1
	 *   PROGRAMACION ESTRUCTURADA
	 *               MARZO / 2001 */

#include"a:\pe.h"

void main()
{

   limpia(15,4);
   marco(179,196,191,218,217,192);

   gotoxy(30,8); 	printf("Programa que calcula si");
   gotoxy(31,9); 	printf("dos numeros son amigos");
   textcolor (14+blink);
   gotoxy(25,11); 	cprintf("(dos numeros son amigos si la suma");
   gotoxy(25,12); 	cprintf("de los divisores del primer numero ");
   gotoxy(24,13); 	cprintf("excepto el mismo es igual al segundo");
   gotoxy(38,14); 	cprintf("y viceversa)");

   getch();

   limpia(15,1);
   marco(176,178,191,218,217,192);

int n,r,j,suma1,m,i,suma2;
 gotoxy(10,4); 	printf("Dame el primer numero ");
 scanf("%d",&n);
 gotoxy(10,6); 	printf("Dame el segundo numero ");
 scanf("%d",&m);

 gotoxy(15,10); 	printf("Los divisores de %d son:",n);
 gotoxy(10,11);		textcolor(10+blink);

 suma1=0;
   for (j=1; j<n; j++)
    {
     r=n%j;
     if(r==0)
       {
       cprintf("%d, ",j);
       suma1=suma1 + j;
       }
    }
   gotoxy(20,12);
   printf("La suma de los divisores de %d es %d",n,suma1);

 gotoxy(15,16); 	printf("Los divisores de %d son:",m);
 gotoxy(10,17);		textcolor(14+blink);

 suma2=0;
   for (i=1; i<m; i++)
    {
     r=m%i;
     if(r==0)
       {
       cprintf("%d, ",i);
       suma2=suma2 + i;
       }
    }
   gotoxy(20,18);
   printf("La suma de los divisores de %d es %d",m,suma2);

  gotoxy(23,23);	textcolor(11+blink);
  if(suma1==suma2)
   {
    cprintf("%d y %d son numeros amigos",n,m);
   }
  else
   {
    cprintf("%d y %d son numeros enemigos",n,m);
   }

  getch();
}