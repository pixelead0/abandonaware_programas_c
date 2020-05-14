#include<stdio.h>
#include<conio.h>
void primos(void);
void main()
{
int n,r,suma,i,j;
 clrscr();
 gotoxy(15,2);
 printf("Programa que calcula los los primeros N numeros primos");
 gotoxy(20,4);
 textcolor(YELLOW);
 cprintf("(Un numero primo es aquel que es divisible");
 gotoxy(28,6);
 cprintf("entre si mismo y entre uno)");

 gotoxy(18,8);
 textcolor(10);
 cprintf("el valor maximo de N que caben en la pantalla es: ");
 gotoxy(40,10);
 cprintf("1500");

 gotoxy(10,15);
 printf("Hasta que numero desea que calcule? ");
 scanf("%d",&n);

 textcolor(WHITE);
 textbackground(BLUE);
 clrscr();
 for(i=1; i<=n; i++)
  {
   suma=0;
   for (j=1; j<i; j++)
    {
     r=i%j;
     if(r==0)
	suma=suma+j;
    }
   if (suma==1)
    printf("\t%d",i);
 }
  gotoxy(25,25);
  textcolor(139);
  cprintf("son los primeros %d numeros primos",n);
  getch();
}