	/*   E . S . I . M . E .  C U L H U A C A N
		ING. EN COMPUTACION
	      PROGRAMA ELABORADO POR:

	 *    ADAN GARCIA QUIROZ
	 *          C5V4
	 *               AGOSTO / 2001 */

#include <dos.h>
#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <graphics.h>

void presentacion(void);	// Presentacion en modo Grafica
void graficos(void);		// Carga graficos
void marco(char lados,char arriba,char esd,char esi,char eid,char eii);
void portada(void);		/* Presentacion en modo texto */
void limpia(int letras, int fondo);
void error(void);
void bien(void);


int blink=128;

void marco(char lados,char arriba,char esd,char esi,char eid,char eii)
 {
  int x;
  int y;
  clrscr();
x=2;
y=2;

  while (y<25)
    {
     gotoxy(x,y);	printf("%c",lados);
     gotoxy(79,y);	printf("%c",lados);
     y++;
	 }

x=2;
y=1;

  while(x<79)
    {
	  gotoxy(x,1);	printf("%c",arriba);
     gotoxy(x,25);	printf("%c",arriba);
     x++;
    }
  gotoxy(2,1);		printf("%c",esi);
  gotoxy(79,1);		printf("%c",esd);
  gotoxy(2,25);		printf("%c",eii);
  gotoxy(79,25);	printf("%c",eid);

 }

void limpia(int letras, int fondo)
 {
 textbackground(fondo);
 textcolor(letras);
 clrscr();
 }

void portada (void)
{
limpia(10,2);
marco(186,205,187,201,188,200);
textcolor (140);	gotoxy(37, 4);
cprintf("I  P  N ");
textcolor (138);	gotoxy(30, 6);
cprintf("E.S.I.M.E.  CULHUACAN");
textcolor (137);	gotoxy(31, 8);
cprintf("ING. EN COMPUTACION");
textcolor (14);		gotoxy(10, 12);
cprintf("PROGRAMA ELABORADO POR:");
textcolor (11);		gotoxy(25, 14);
cprintf("ADAN GARCIA QUIROZ");
textcolor (14);		gotoxy(10, 16);
cprintf("MATERIA:");
textcolor (11);		gotoxy(25, 18);
cprintf("COMPILADORES");
textcolor (14);		gotoxy(10, 20);
cprintf("GRUPO:");
textcolor (11);		gotoxy(25, 22);
cprintf("C5V4");
getch();
}

void error(void)
{
  sound(200);
  delay(500);
  nosound();
}

void bien(void)
{
  sound(2200);
  delay(800);
//  textcolor(15);
//  gotoxy(30,20);
//  cprintf("Fin");*/

  sound(1800);
  delay(900);
//  textcolor(9);
//  cprintf(" del");

  sound(2000);
  delay(500);
//  textcolor(15);
//  cprintf(" programa");

  sound(3600);
  delay(500);
  nosound();

//  printf("\nPresione cualquier tecla...");
//  getch();
 }



void presentacion(void)
{
 graficos();
 rectangle(0,0,639,479);
 rectangle(10,10,629,469);
 setfillstyle(1,1);
 floodfill(320,240,WHITE);
 settextjustify(CENTER_TEXT,CENTER_TEXT);
 settextstyle(TRIPLEX_FONT,HORIZ_DIR,7);
 outtextxy(320,150,"GRAFICACION");
 outtextxy(320,210,"PRACTICA");
 outtextxy(320,270,"#1");
 settextjustify(LEFT_TEXT,LEFT_TEXT);
 settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
 outtextxy(465,460,"Agosto /2001");
 outtextxy(465,445,"Garcia Quiroz Adan");
 settextjustify(CENTER_TEXT,LEFT_TEXT);
 setcolor(14);
 outtextxy(320,479,"Presione Enter Para Continuar");
 getche();
// closegraph();
}

int gd=DETECT,gm,errorcode;
void graficos(void)
{
 gd=VGA; gm=VGAHI;

 initgraph(&gd,&gm,"d:\\tc\\bgi");
/*	errorcode = graphresult(); /* check for any errors
	if (errorcode != grOk)
	{
		printf("Graphics error: %s\n", grapherrormsg(errorcode));
		printf("Press any key to halt:");
		getch();
		exit();
	}                                                  */

}
