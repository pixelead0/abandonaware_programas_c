#include<stdio.h>
#include<conio.h>
main(void)
{
 int pos=0;
 int neg=0;
 int nulo=0;
 int i,num;
 int x=100;

 textbackground(BLUE);
 textcolor(WHITE);
 clrscr();

 gotoxy (15,2);
 printf ("Programa que lee la secuencia de 100 numeros");
 gotoxy(10,3);
 printf ("y obtiene e imprime cuantos hay positivos, negativos y nulos");

 window  (25,8,51,15);
 textbackground(RED);
 textcolor(YELLOW);
 clrscr();

 for(i=1; i<=x; i++)
 {
  cprintf ("\n\r  Dame el numero (%d) : ", i);
  scanf  ("%d",&num);
  if (num>0)
    pos+=1;
  else if (num<0)
    neg+=1;
 }
 window  (1,1,80,25);
 nulo=x - (pos+neg);
 textbackground(BLUE);
 textcolor(LIGHTGREEN);

 gotoxy(20,18);
 cprintf("Introduciste %d numeros positivos,", pos);
 gotoxy(33,19);
 cprintf("%d negativos",neg);
 gotoxy(31,20);
 cprintf("y %d nulos", nulo);


 textbackground(BLACK);
 textcolor(LIGHTGRAY);

 gotoxy(37,25);
 cprintf("Presione cualquier tecla para terminar...");
 getch();
}
