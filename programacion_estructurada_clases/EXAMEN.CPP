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
  limpia(14,7);
  marco(15,15,4,4,4,4);
 int um,c,d,u,num;
 gotoxy(20,2);
 printf("Programa que hace la conversion de numeros");

 gotoxy(30,4);
 printf("Arabigos a numeros Romanos");

 gotoxy(10,10);
 printf("Dame un numero ");
 scanf("%d",&num);

 if(num>3999)
   {
   error();
   goto salida;
   }
bien();
gotoxy(20,14);
 textcolor(15+blink);
 cprintf("Su equivalente en romano es: ");

 gotoxy(25,16);
 um=0;
 c=0;
 d=0;
 u=0;
 /* Calcula Unidades de millar*/
 while(num>=1000)
 {
  num-=1000;
  um+=1;
 }

 /* Calcula Centenas*/
 while(num>=100)
 {
  num-=100;
  c+=1;
 }

 /*Calcula decenas*/
 while(num>=10)
 {
  num-=10;
  d+=1;
 }

 /* Unidad es el resto de las operaciones anteriores*/
u=num;

textcolor(10);
if (um==1)
   cprintf("M");
else if (um==2)
   cprintf("MM");
else if (um==3)
   cprintf("MMM");

textcolor(11);
if (c==1)
   cprintf("C");
else if (c==2)
   cprintf("CC");
else if (c==3)
   cprintf("CCC");
else if (c==4)
   cprintf("CD");
else if (c==5)
   cprintf("D");
else if (c==6)
   cprintf("DC");
else if (c==7)
   cprintf("DCC");
else if (c==8)
   cprintf("DCCC");
else if (c==9)
   cprintf("CM");

textcolor(12);
if (d==1)
   cprintf("X");
else if (d==2)
   cprintf("XX");
else if (d==3)
   cprintf("XXX");
else if (d==4)
   cprintf("XL");
else if (d==5)
   cprintf("L");
else if (d==6)
   cprintf("LX");
else if (d==7)
   cprintf("LXX");
else if (d==8)
   cprintf("LXXX");
else if (d==9)
   cprintf("XC");


textcolor(13);
if (u==1)
   cprintf("I");
else if (u==2)
   cprintf("II");
else if (u==3)
   cprintf("III");
else if (u==4)
   cprintf("IV");
else if (u==5)
   cprintf("V");
else if (u==6)
   cprintf("VI");
else if (u==7)
   cprintf("VII");
else if (u==8)
   cprintf("VIII");
else if (u==9)
   cprintf("IX");

   getch();
 salida:

}