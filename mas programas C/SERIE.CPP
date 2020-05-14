#include<stdio.h>
#include<conio.h>
void main()
{
 int i,x;
 long float fact, div, suma;
 textbackground(BLUE);
 textcolor(WHITE);
 clrscr();

 gotoxy(25,2);
 printf("Programa que calcula la serie");
 gotoxy(20,4);
 printf("1/0! + 1/1! + 1/2! + 1/3! + ... + 1/N!");

 gotoxy(15,10);
 printf("Dame el valor para N: ");
 scanf("%ld",&x);

 getch();

  fact=1;
  suma=1;

  for (i=1; i<=x; i++)
   {
    fact *=i;
    div=1/fact;
    suma=suma+div;
   }
  gotoxy(20,22);
  printf(" La suma de la serie es %lf ",suma);
getch();
}