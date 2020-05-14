//    E . S . I . M . E .  C U L H U A C A N
//              ING. EN COMPUTACION
//            PROGRAMA ELABORADO POR:
//
//       * ADAN GARCIA QUIROZ
//       *   C3V4

void fin(void);
void marco(void);
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
  int y=2;
  clrscr();
  textbackground(0);
  while (y<25)
    {
     textcolor(12);
     gotoxy(x,y);cprintf("|");
     gotoxy(80,y);cprintf("|");
     y++;
    }
  x=2;
  y=1;
  while(x<80)
    {
     textcolor(12);
     gotoxy(x,y);cprintf("_");
     gotoxy(x,24);cprintf("_");
     x++;
    }
  gotoxy(2,2);cprintf("*");
  gotoxy(2,24);cprintf("*");
  gotoxy(79,2);cprintf("*");
  gotoxy(79,24);cprintf("*");
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
cprintf("ESTRUCTURA DE DATOS");

textcolor (14);
gotoxy(10, 20);
cprintf("GRUPO:");

textcolor (11);
gotoxy(25, 22);
cprintf("C3V4");
getch();
}