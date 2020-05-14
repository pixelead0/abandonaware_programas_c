/*   E . S . I . M . E .  C U L H U A C A N
		ING. EN COMPUTACION
	      PROGRAMA ELABORADO POR:

	 *    ADAN GARCIA QUIROZ
	 *          C1M1
	 *   PROGRAMACION ESTRUCTURADA   */

#include<stdio.h>
#include<conio.h>
#include<dos.h>

void fin(void);
void marco(void);
void marco2(void);
void portada(void);

void fin(void)
 {
  int t=1;
  int x=20;
  int y=10;
  clrscr();
  while (y<14)
    {
     textcolor(3001);
     textbackground(0);
     gotoxy(x,y);cprintf("*");
     gotoxy(50,y);cprintf("*");
     y++;
    }
  x=20;
  y=10;
  while(x<51)
    {
     textcolor(3001);
     textbackground(0);
     gotoxy(x,y);cprintf("*");
     gotoxy(x,14);cprintf("*");
     x++;
    }

  while(t<100)
   {
    t++;
    textcolor(t);
    textbackground(0);
    gotoxy(27,12);cprintf("FIN DEL PROGRAMA");
    delay(50);
   }
  delay(100);
  clrscr();
 }

void marco(void)
 {
  int x=1;
  int y=1;
  clrscr();
  textbackground(0);
  while (y<25)
    {
     textcolor(2);
     gotoxy(x,y);cprintf("³");
     gotoxy(80,y);cprintf("³");
     y++;
    }
  x=1;
  y=1;
  while(x<80)
    {
     textcolor(2);
     gotoxy(x,y);cprintf("Ä");
     gotoxy(x,24);cprintf("Ä");
     x++;
    }
  gotoxy(1,1);cprintf("Ú");
  gotoxy(1,24);cprintf("À");
  gotoxy(80,1);cprintf("¿");
  gotoxy(80,24);cprintf("Ù");
 }

void portada (void)
{
textcolor (140);
gotoxy(37, 4);
cprintf("I  P  N ");

textcolor (138);
gotoxy(30, 6);
cprintf("E.S.I.M.E.  CULHUACAN");

textcolor (137);
gotoxy(31, 8);
cprintf("ING. EN COMPUTACION");

textcolor (14);
gotoxy(10, 12);
cprintf("PROGRAMA ELABORADO POR:");

textcolor (11);
gotoxy(25, 14);
cprintf("ADAN GARCIA QUIROZ");

textcolor (14);
gotoxy(10, 16);
cprintf("MATERIA:");

textcolor (11);
gotoxy(25, 18);
cprintf("PROGRAMACION ESTRUCTURADA");

textcolor (14);
gotoxy(10, 20);
cprintf("GRUPO:");

textcolor (11);
gotoxy(25, 22);
cprintf("C1M1");
getch();
}




void marco2(void)
 {
  int x=1;
  int y=1;
  clrscr();
  textbackground(0);
  while (y<25)
    {
     textcolor(2);
     gotoxy(x,y);cprintf("º");
     gotoxy(80,y);cprintf("º");
     y++;
    }
  x=1;
  y=1;
  while(x<80)
    {
//     textcolor(14);
     gotoxy(x,y);cprintf("Í");
     gotoxy(x,24);cprintf("Í");
     x++;
    }
  gotoxy(1,1);cprintf("É");
  gotoxy(1,24);cprintf("È");
  gotoxy(80,1);cprintf("»");
  gotoxy(80,24);cprintf("¼");
 }
