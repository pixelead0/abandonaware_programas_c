/*
  ÚÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¿
  ³ Palette.h  (versi¢n 0.1)                                               ³
  ³                                                                        ³
  ³ Librer¡a gr fica para el tratamiento de la paleta                      ³
  ³                                                                        ³
  ³ Se incluyen funciones para cambiar los colores de la paleta o          ³
  ³ efectos como fundidos o rotaci¢n de paleta.                            ³
  ³                                                                        ³
  ³ Para incluirla en cualquier programa C basta con usar la orden         ³
  ³ #include "Palette.h"                 al principio del mismo.           ³
  ³                                                                        ³
  ³ Nota : Para utilizar esta libreria es necesario compilar con la        ³
  ³        opci¢n del compilador '-1' para que utilice las instrucciones   ³
  ³        del 286.    ( bcc -1 nombre.c )                                 ³
  ³                                                                        ³
  ³ C¢digo y texto: ÄÄÄ] Bizarre inc. [ÄÄÄ  de Compiler SoftWare.          ³
  ÀÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ1997 C.S.ÍÙ
*/

#ifndef __DOS_H
  #include <dos.h>
#endif                            /* si no est  incluida dos.h, incluirla */
			  

/* ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Funciones implementadas: ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ */

void SetPaletteC(char, char, char, char );
			/* Cambia un color con funciones C */
void GetPaletteC(char, char *, char *, char *);
			/* Captura un color con funciones C  */
void SetPaletteBIOS( char far * );
			/* Cambia la paleta entera con interrupciones  */
void GetPaletteBIOS( char far * );
			/* Captura la paleta entera con interrupciones */
void SetPalette( char far * );
			/* Cambia la paleta entera con puertos         */
void GetPalette( char far * );
			/* Captura la paleta entera con puertos        */

void SetRGBValue( char, char, char, char );
			/* Cambia un solo valor con puertos            */
void GetRGBValue( char, char *, char *, char * );
			/* Captura un solo valor con puertos           */

/*void WaitVRetraceC(void); /* ** */
			/* Se espera an retrazo vertical con func. C   */
/*void WaitVRetrace(void);
			/* Se espera al retrazo con ensamblador        */

void FadeOut( void );   /* Realiza un fundido a negro                  */
void FadeIn( char * );  /* Hace un fundido del negro a una paleta      */
void FadeTo( char * );  /* Hace un fundido desde una paleta a otra     */
void RotatePaletteLeft ( char * );  /* Rota la paleta                  */
void RotatePaletteRight( char * );  /* Rota la paleta                  */

void NegativePalette ( char * );    /* Hace el negativo de una imagen    */
void GreyPalette (char *);          /* Pasa la paleta a escala de grises */

/* ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ */
/* ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ */

/* ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ */
void SetPaletteC ( char color, char r, char g, char b)
{
   outportb (0x3C8, color);
   outportb (0x3C9, r);
   outportb (0x3C9, g);
   outportb (0x3C9, b);
}

/* ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ */
void GetPaletteC ( char color, char *r,  char *g,  char *b)
{
   outportb (0x3C7, color);
   *r = inportb (0x3C9);
   *g = inportb (0x3C9);
   *b = inportb (0x3C9);
}

/* ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ */
void SetPaletteBIOS  ( char far *paleta)
{
   asm {
	les dx, [paleta]
	mov ax, 0x1012
	mov bx, 0
	mov cx, 256
	int 0x10
       }
}

/* ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ */
void GetPaletteBIOS  ( char far *paleta)
{
   asm {
	les dx, [paleta]
	mov ax, 0x1017
	mov bx, 0
	mov cx, 256
	int 0x10
       }
}

/* ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ */
void SetPalette  ( char far *paleta)
{
   asm {
	push ds
	lds si, [paleta]
	mov cx, 256*3
	mov al, 0
	mov dx, 3c8h
	out dx, al
	inc dx
	rep outsb
	pop ds
       }
}

/* ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ */
void GetPalette  ( char far *paleta)
{
   asm {
	les di, [paleta]
	mov cx, 256*3
	mov al, 0
	mov dx, 3c7h
	out dx, al
	add dx, 2
	rep insb
       }
}

/* ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ */
void SetRGBValue(  char color, char r, char g, char b )
{
  asm {
      mov dx, 0x3C8
      mov al, [color]
      out dx, al
      inc dx
      mov al, [r]
      out dx, al
      mov al, [g]
      out dx, al
      mov al, [b]
      out dx, al
  }
}

/* ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ */
void SetRGBPalette(  char *paleta )
{
   int x;

  outportb (0x3C8, 0);
  
  for (x=0;x<768;x++)
    outportb (0x3C9, paleta[x]);
}

/* ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ */
void GetRGBValue(  char color,  char *r,  char *g,  char *b )
{
  asm {
      mov dx, 0x3C7
      mov al, [color]
      out dx, al
      add dx, 2
      in al, dx
      mov bl, al
      in al, dx
      mov bh, al
      in al, dx
      mov cl, al
      }
  *r = _BL;
  *g = _BH;
  *b = _CL;
}

/* ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ 
void WaitVRetraceC(void)
{
  while ((inportb(0x03DA) & 8) != 0);
  while ((inportb(0x03DA) & 8) == 0);
} */

/* ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ 
void WaitVRetrace (void)
{
asm   mov dx, 0x03DA
Retrazo1:
asm {
	in      al, dx
	test    al, 8
	jnz     Retrazo1
    }
Retrazo2:
asm {
	in      al, dx
	test    al, 8
	jz      Retrazo2
    }
}*/

/* ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ */
/*
   ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
	Hace un fundido a negro desde la paleta que est‚ en el DAC
   ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
*/
void FadeOut(void)
{
   char paleta[768];
   int x, y;

  GetPalette (paleta);

  for (y=0; y<63; y++)
  {
      for (x=0;x<768;x++)
	if (paleta[x] > 0) paleta[x]--;
      WaitVRetrace ();
      SetPalette(paleta);
  }
}

/* ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ */
/*
  ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
    Hace un fundido desde negros hasta la paleta que se le indique como 
	  par metro. La paleta debe tener como m¡nimo 768 bytes
  ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
*/
void FadeIn ( char *paleta )
{
   char pal[768];
   int x, y;

  for (y=0;y<768;y++) pal[y] = 0;

  for (y=0; y<63; y++)
  {
      for (x=0;x<768;x++)
	if (pal[x] < paleta[x]) pal[x]++;

  WaitVRetrace();
  SetPalette(pal);
  }
}

/* ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ */
/*
  ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
   Hace un fundido desde la paleta actual (del DAC) hasta la paleta que
   se pase como par metro. Esta debe tener un tama¤o minimo de 768 bytes
  ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
*/
void FadeTo ( char *paleta)
{
   char pal[768];
   int x, y;

  GetPalette (pal);

  for (y=0;y<63;y++)
  {
      for (x=0;x<768;x++)
      {
	if (pal[x] < paleta[x]) pal[x]++;
	if (pal[x] > paleta[x]) pal[x]--;
      }
  WaitVRetrace();
  WaitVRetrace();
  SetPalette(pal);
  }
}
/* ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ */
/*
  ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
    Rota la paleta hacia la derecha una posici¢n cada vez que es llamada
			       la funci¢n
  ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
*/

void RotatePaletteLeft ( char *paleta)
{
   char r, g, b;
   int x;

    r = paleta[0];
    g = paleta[1];
    b = paleta[2];
    for (x=0;x<765;x+=3)
    {
    paleta[x] = paleta[x+3];
    paleta[x+1] = paleta[x+4];
    paleta[x+2] = paleta[x+5];
    }
    paleta[765] = r;
    paleta[766] = g;
    paleta[767] = b;

    WaitVRetrace();
    SetPalette (paleta);
}
/* ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ */
/*
  ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
    Rota la paleta hacia la izquierda una posici¢n cada vez que es
			llamada la funci¢n
  ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
*/

void RotatePaletteRight ( char *paleta)
{
   char r, g, b;
   int x;

    r = paleta[765];
    g = paleta[766];
    b = paleta[767];
    for (x=767;x>3;x-=3)
    {
    paleta[x] = paleta[x-3];
    paleta[x-1] = paleta[x-4];
    paleta[x-2] = paleta[x-5];
    }
    paleta[0] = r;
    paleta[1] = g;
    paleta[2] = b;

    WaitVRetrace();
    SetPalette (paleta);
}
/* ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ */
/*
  ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
		     Realiza el negativo de la  paleta
  ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
*/

void NegativePalette ( char *paleta )
{
  int x;
  for (x=0;x<768;x+=3) 
	{
	 paleta[x] = 63-paleta[x];
	 paleta[x+1] = 63 - paleta[x+1];
	 paleta[x+2] = 63 - paleta[x+2];
	}
  SetPalette (paleta);
}

/* ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ */
/*
  ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
		     Pasa la paleta a escala de grises
  ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
*/

void GreyPalette (char *paleta)
{
  int x, y;
  int media;

  for (x=0;x<768;x+=3)
  {
     media = (paleta[x] + paleta[x+1] + paleta[x+2]) / 3;
     paleta[x] = media;
     paleta[x+1] = media;
     paleta[x+2] = media;
  }
  SetPalette (paleta);
}

/*
+-----------------------------------------------------------------------+
|                          Fin de fichero                               |
+------------------------------------------------------- E.S.I.M.E -----+
*/
