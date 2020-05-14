#include<stdio.h>
#include<conio.h>
#include<dos.h>

void main()
{
 long int fact,x,i;
 textbackground(BLUE);
 textcolor(WHITE);
 clrscr();
  otro:
gotoxy(15,2);
 printf("Programa que calcula el factorial de un numero N");
 gotoxy(25,12);
 cprintf("El numero debe estar entre 1 y 16");
 gotoxy(15,10);
 printf("Hasta que numero desea que se calcule el facorial: ");
 scanf("%ld",&x);

 if ((x<=0) || (x>16))
   {
    sound(300);
    delay(200);
    nosound();

    textcolor(LIGHTGREEN);
    gotoxy(25,12);
    cprintf("El numero debe estar entre 1 y 16");
    goto otro;
   }

  textcolor(WHITE);
  clrscr();

  fact=1;
  for (i=1; i<=x; i++)
   {
    fact *=i;
    printf("\n %ld! = %ld",i,fact);
   }
   getch();
}