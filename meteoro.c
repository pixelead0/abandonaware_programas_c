#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <time.h>
#include <stdlib.h>
#include <dos.h>

 int NAVE[32], POS_METEORO[32][25];

 void main (void)
 {

    void CARACTERISTICAS_JUEGO (int *VELOCIDAD, int *DIFICULTAD);
    void INICIALIZAR_ESPACIO (void);
    void OBTENER_POS_ALEAT_METEOROS (int DIFICULTAD);
    void INCREMENTAR_MATRIZ_METEOROS (void);
    void ACTUALIZAR_PANTALLA_METEOROS (int VELOCIDAD, char *TECLA, char *CHOQUE, int *DESTRUIDOS);
    void BOOM (char CHOQUE);
    void PUNTUACION (char TECLA, float fin, float inicio, int MODO, int *DESTRUIDOS);
    char COMPROBAR_SALIDA (int TECLA);

    int DRIVER, MODO, POS_INI, DIFICULTAD, VELOCIDAD;
    int DESTRUIDOS = 0;
    char CHOQUE = 'N', TECLA;
    int SALIDA;
    clock_t inicio, fin;

    randomize();
    detectgraph (&DRIVER, &MODO);
    initgraph (&DRIVER, &MODO, "C:\\BC4\\BGI");
    do
    {
       CARACTERISTICAS_JUEGO (&VELOCIDAD, &DIFICULTAD);
       INICIALIZAR_ESPACIO ();
       inicio = clock();
       do
       { 
          OBTENER_POS_ALEAT_METEOROS (DIFICULTAD);
          INCREMENTAR_MATRIZ_METEOROS ();
          ACTUALIZAR_PANTALLA_METEOROS (VELOCIDAD, &TECLA, &CHOQUE, &DESTRUIDOS);
       }
       while ((TECLA != 27) && (CHOQUE != 'S')); 
       fin = clock();
       BOOM (CHOQUE);
       CHOQUE = 'N';
       PUNTUACION (TECLA, fin, inicio, MODO, &DESTRUIDOS);
       SALIDA = COMPROBAR_SALIDA(TECLA) == 'S';
    }
    while (!SALIDA);
    closegraph ();
 }

/************************************************************************/
    void CARACTERISTICAS_JUEGO (int *VELOCIDAD, int *DIFICULTAD)
    {
      do
      {
         setcolor (15);
         rectangle (100,100,540,300);
         outtextxy (250,150,"VELOCIDAD");
         outtextxy (255,185,"Dormido: 1");
         outtextxy (255,205,"Crucero: 2");
         outtextxy (255,225,"R pido:  3");
         outtextxy (255,245,"V‚rtigo: 4");
         *VELOCIDAD = getch();
         if (*VELOCIDAD == 49)
         {
            *VELOCIDAD = 50;
         }
         else if (*VELOCIDAD == 50)
         {
            *VELOCIDAD = 25;
         }
         else if (*VELOCIDAD == 51)
         {
            *VELOCIDAD = 4;
         }
         else if (*VELOCIDAD == 52)
         {
            *VELOCIDAD = 0;
         }
         cleardevice();
      }
      while ((*VELOCIDAD != 50)&&(*VELOCIDAD != 25)&&(*VELOCIDAD != 4)&&(*VELOCIDAD != 0));

      do
      {
         rectangle (100,100,540,300);
         outtextxy (250,150,"DIFICULTAD ");
         outtextxy (255,180,"F cil:   1");
         outtextxy (255,200,"Normal:  2");
         outtextxy (255,220,"Dif¡cil: 3");
         *DIFICULTAD = getch();
         if (*DIFICULTAD == 49)
         {
            *DIFICULTAD = 2;
         }
         else if (*DIFICULTAD == 50)
         {
            *DIFICULTAD = 3;
         }
         else if (*DIFICULTAD == 51)
         {
            *DIFICULTAD = 5;
         }
         cleardevice();
      }
      while ((*DIFICULTAD != 2) && (*DIFICULTAD != 3) && (*DIFICULTAD != 5));
      delay(2000);
    }
/************************************************************************/
    void INICIALIZAR_ESPACIO (void)
    {
       int X, Y ,POS;
       POS = 16;
       NAVE [POS] = 1;
       for (Y=0; Y<=24; Y++)
       {
          for (X=0; X<=31; X++)
          {
               POS_METEORO [X][Y] = 0;
               if ((Y == 23)  && (X != POS))
               {
                   NAVE[X] = 0;
               }
          }
       }
    }

/*************************************************************************/

    void OBTENER_POS_ALEAT_METEOROS (int DIFICULTAD)
    {
       int NUM_MAX_METEOROS, AUX, POS;

       NUM_MAX_METEOROS = random (DIFICULTAD);
       for (AUX=1; AUX <= NUM_MAX_METEOROS; AUX++)
       {
         POS = random(32);
         POS_METEORO [POS][0] = 1;
       }
    }
/*****************************************************************/

    void INCREMENTAR_MATRIZ_METEOROS (void)
    {
       int X,Y;
       for (Y=24; Y>=0; Y--)
       {
          for (X=31; X>=0; X--)
          {
             if ((POS_METEORO [X][Y] == 1) && (Y!=24))
             {
                POS_METEORO [X][Y] = 0;
                POS_METEORO [X][Y+1] = 1;
             }
             else if (Y==24)
             {
                POS_METEORO [X][24] = 0;
             }
          }
       }
    }

/*************************************************************************/

    void ACTUALIZAR_PANTALLA_METEOROS (int VELOCIDAD, char *TECLA, char *CHOQUE, int *DESTRUIDOS)
    {
       void DIBUJAR_METEOROS (int X, int Y);
       void COMPROBAR_TECLA (char *TECLA, char *CHOQUE, int *DESTRUIDOS);

       int X, Y, PIXEL, POS_INI;
       for (Y=0; Y<=24; Y++)
       {
          for (X=0; X<=31; X++)
          {
             if (POS_METEORO [X][Y] == 1)
             {
                   DIBUJAR_METEOROS (X,Y);
                   delay (VELOCIDAD);
             }
          }
          COMPROBAR_TECLA (TECLA, CHOQUE, DESTRUIDOS);
       }
    }

/*************************************************************************/
    void DIBUJAR_METEOROS (int X, int Y)
    {
       setcolor(0);
       setfillstyle(1,0);
       circle ((X*20)+10, ((Y-1)*20)+10, 5);
       floodfill ((X*20)+10, ((Y-1)*20)+10, 0);

       setcolor(8);
       setfillstyle(1,8);
       circle ((X*20)+10,(Y*20)+10, 5);
       floodfill ((X*20)+10,(Y*20)+10, 8);

       setcolor(4);
       setfillstyle(1,4);
       circle ((X*20)+10,(Y*20)+10, 2);
       floodfill ((X*20)+10,(Y*20)+10, 4);

       putpixel ((X*20)+10,(Y*20)+10, 14);
    }

/**************************************************************************/

    void COMPROBAR_TECLA (char *TECLA, char *CHOQUE, int *DESTRUIDOS)
    {
       void ACTUALIZAR_PANTALLA_NAVE (int POS_INI);
       void COMPROBAR_POS_NAVE (char *CHOQUE);
    
       int AUX, POS_INI, X, Y;
       AUX = 0;
       do    
       {      
          if (NAVE [AUX] == 0)
          {
             AUX++;
          }  
       }
       while (NAVE [AUX] == 0);
       POS_INI = AUX;
       if (kbhit())
       {
          *TECLA = getch();
          if ((AUX >= 0) && (AUX <= 31))
          {
             if ((*TECLA == 75) && (AUX!=0))
             {
                NAVE [AUX] = 0;
                NAVE [AUX - 1] = 1;
             }
             else if ((*TECLA == 77) && (AUX!=31))
             {
                   NAVE [AUX] = 0;
                   NAVE [AUX + 1] = 1;
             }
             else if (*TECLA == 'a')
             {
                cleardevice();
                for (Y=0; Y<=24; Y++)
                {
                   printf ("\n");
                   for (X=0; X<=31; X++)
                   {
                      printf (" %d", POS_METEORO [X][Y]);
                   }
                }
                delay (1000);
                cleardevice();
             }
             else if (*TECLA == 32)
             {
                Y=24;
                do
                {
                   Y--;
                   putpixel ((AUX*20)+10, (Y*20)+10, 15);
                   putpixel ((AUX*20)+10, (Y*20)+10-1, 15);
                   putpixel ((AUX*20)+10, (Y*20)+10-2, 15);
                   delay (3);
                   putpixel ((AUX*20)+10, (Y*20)+10, 0);
                   putpixel ((AUX*20)+10, (Y*20)+10-1, 0);
                   putpixel ((AUX*20)+10, (Y*20)+10-2, 0);
                   for (X=24;X>=0;X--)
                   {
                      setcolor(0);
                      setfillstyle(1,0);
                      circle ((AUX*20)+10, ((X)*20)+10, 5);
                      floodfill ((AUX*20)+10, ((X)*20)+10, 0);
                   }
                   if (POS_METEORO[AUX][Y] == 1)
                   {
                      (*DESTRUIDOS)++;
                   } 
                }
                while ((Y > 0) && (POS_METEORO[AUX][Y] == 0));
                POS_METEORO[AUX][Y] = 0;
             }
          }
       }
       ACTUALIZAR_PANTALLA_NAVE (POS_INI);
       COMPROBAR_POS_NAVE (CHOQUE);
    }

/************************************************************************/

void ACTUALIZAR_PANTALLA_NAVE (int POS_INI)
{
    int Y, X, PIXEL;
    Y=23;
    for (X=0; X<=31; X++)
    {
       if ((NAVE [X] == 1) && (Y == 23))
       {
          if (POS_INI < X)  /* DERECHA */
          {
             for (PIXEL=0; PIXEL<=20; PIXEL++)
             {
                setcolor (0);
                setfillstyle (1,0);
                circle (((X-1)*20)+10+PIXEL-1, Y*20+10, 9);
                floodfill (((X-1)*20)+10+PIXEL-1, Y*20+10, 0);
                line (((X-1)*20)+8+PIXEL-1, Y*20+10, ((X-1)*20)+8+PIXEL-1, Y*20-8);
                line (((X-1)*20)+12+PIXEL-1, Y*20+10, ((X-1)*20)+12+PIXEL-1, Y*20-8);
                line (((X-1)*20)+1+PIXEL-1, Y*20+20, ((X-1)*20)+1+PIXEL-1, Y*20-3);
                line (((X-1)*20)+19+PIXEL-1, Y*20+20, ((X-1)*20)+19+PIXEL-1, Y*20-3);
                putpixel (((X-1)*20)+10+PIXEL-1,(Y*20)+10,0);

                setcolor (9);
                setfillstyle (1,9);
                circle (((X-1)*20)+10+PIXEL, Y*20+10, 8);  
                floodfill (((X-1)*20)+10+PIXEL, Y*20+10, 9);
                line (((X-1)*20)+8+PIXEL, Y*20+10, ((X-1)*20)+8+PIXEL, Y*20-8);
                line (((X-1)*20)+12+PIXEL, Y*20+10, ((X-1)*20)+12+PIXEL, Y*20-8);
                line (((X-1)*20)+1+PIXEL, Y*20+20, ((X-1)*20)+1+PIXEL, Y*20-3);
                line (((X-1)*20)+19+PIXEL, Y*20+20, ((X-1)*20)+19+PIXEL, Y*20-3);

                setcolor(2);
                setfillstyle(1,2);
                circle (((X-1)*20)+10+PIXEL,(Y*20)+10, 5);
                floodfill (((X-1)*20)+10+PIXEL,(Y*20)+10, 2);

                setcolor(4);
                setfillstyle(1,4);
                circle (((X-1)*20)+10+PIXEL,(Y*20)+10, 3);
                floodfill (((X-1)*20)+10+PIXEL,(Y*20)+10, 4);

                setcolor(14);
                putpixel (((X-1)*20)+10+PIXEL,(Y*20)+10,14);
             }
          }
          else if (POS_INI > X)      /*  IZQUIERDA  */
          {
             for (PIXEL=0;PIXEL<=20;PIXEL++)
             {
                 setcolor (0);
                 setfillstyle (1,0);
                 circle (((X+1)*20)+10-PIXEL+1,Y*20+10,9);  
                 floodfill (((X+1)*20)+10-PIXEL+1,Y*20+10,0);
                 line (((X+1)*20)+8-PIXEL+1, Y*20+10, ((X+1)*20)+8-PIXEL+1, Y*20-8);
                 line (((X+1)*20)+12-PIXEL+1, Y*20+10, ((X+1)*20)+12-PIXEL+1, Y*20-8);
                 line (((X+1)*20)+1-PIXEL+1, Y*20+20, ((X+1)*20)+1-PIXEL+1, Y*20-3);
                 line (((X+1)*20)+19-PIXEL+1, Y*20+20, ((X+1)*20)+19-PIXEL+1, Y*20-3);
                 putpixel (((X-1)*20)+10-PIXEL+1,(Y*20)+10,0);

                 setcolor (9);
                 setfillstyle (1,9);
                 circle (((X+1)*20)+10-PIXEL, Y*20+10, 8);  
                 floodfill (((X+1)*20)+10-PIXEL, Y*20+10, 9);

                 line (((X+1)*20)+8-PIXEL, Y*20+10, ((X+1)*20)+8-PIXEL, Y*20-8);
                 line (((X+1)*20)+12-PIXEL, Y*20+10, ((X+1)*20)+12-PIXEL, Y*20-8);
                 line (((X+1)*20)+1-PIXEL, Y*20+20, ((X+1)*20)+1-PIXEL, Y*20-3);
                 line (((X+1)*20)+19-PIXEL, Y*20+20, ((X+1)*20)+19-PIXEL, Y*20-3);


                 setcolor(2);
                 setfillstyle(1,2);
                 circle (((X+1)*20-PIXEL)+10,(Y*20)+10, 5);
                 floodfill (((X+1)*20)+10-PIXEL,(Y*20)+10, 2);

                 setcolor(4);
                 setfillstyle(1,4);
                 circle (((X+1)*20-PIXEL)+10,(Y*20)+10, 3);
                 floodfill (((X+1)*20)+10-PIXEL,(Y*20)+10, 4);

                 setcolor(14);
                 putpixel (((X+1)*20)+10-PIXEL,(Y*20)+10,14);
             }
          }
          else
          {
             setcolor(9);
             setfillstyle(1,9);
             circle (X*20+10, Y*20+10, 8);  
             floodfill(X*20+10, Y*20+10, 9);

             line (X*20+8, Y*20+10, X*20+8, Y*20-8);
             line (X*20+12, Y*20+10, X*20+12, Y*20-8);
             line (X*20+1, Y*20+20, X*20+1, Y*20-3);
             line (X*20+19, Y*20+20, X*20+19, Y*20-3);

             setcolor(2);
             setfillstyle(1,2);
             circle ((X*20)+10,(Y*20)+10, 5);
             floodfill ((X*20)+10,(Y*20)+10, 2);

             setcolor(4);
             setfillstyle(1,4);
             circle ((X*20)+10,(Y*20)+10, 3);
             floodfill ((X*20)+10,(Y*20)+10, 4);

             setcolor(14);
             putpixel ((X*20)+10,(Y*20)+10,14);
          }
       }
    }

}
 
/********************************************************************/       

    void COMPROBAR_POS_NAVE (char *CHOQUE)
    {
       int Y=23, AUX=0;

       do
       {
          if (NAVE [AUX] == 0)
          {
             AUX++;
          }
       }
       while (NAVE [AUX] == 0);
       if (NAVE [AUX] == POS_METEORO [AUX][Y+1])
       {
           *CHOQUE = 'S';
       }
    }

/*********************************************************************/
   void BOOM (char CHOQUE)
   {
      if (CHOQUE == 'S')
      {
         setcolor (15);
         cleardevice();
         outtextxy(120 , 200," ­­­­­­  HA COLISIONADO CON UN METEORITO !!!!!!!");
         delay (2500);
      }
   }
/*********************************************************************/

   char COMPROBAR_SALIDA (int TECLA)
   {
      char SALIR;
      cleardevice ();
      if (TECLA != 27)
      {
         outtextxy (230,220," FIN DE LA PARTIDA");
         outtextxy (200,250," DESEA SALIR DEL JUEGO [S/N]");
         SALIR = getch();
         if (SALIR == 's')
         {
            SALIR = 'S';
         }
      }
      else
      {
        SALIR = 'S';
      }
      cleardevice();
      return SALIR;
   }
     
/************************************************************************/

  void PUNTUACION (char TECLA, float fin, float inicio, int MODO, int *DESTRUIDOS)
  {
    char CONTINUA;
    float TOTAL;
    if (TECLA != 27)
    {
       cleardevice();
       restorecrtmode();
       gotoxy (15,12); 
       printf("Has sobrevivido durante %0.2f segundos. ( %0.2f minutos )\n", (fin - inicio) / CLK_TCK ,((fin - inicio) / CLK_TCK) / 60);
       gotoxy (23,14);
       printf("  Meteoritos destruidos: %d", *DESTRUIDOS);
       gotoxy (23,16);
       TOTAL = ((((fin - inicio) / CLK_TCK) * 20) + (*DESTRUIDOS * 40));
       printf(" La puntuaci¢n es: %0.0f puntos.", TOTAL);
       gotoxy(23,19);
       if (TOTAL < 2000)
       {
         printf( "!  NO TIENES NI PU¥ETERA IDEA ­");
       }
       else if ((TOTAL >=2000) && (TOTAL < 10000))
       {
         printf (" ENPIEZAS A DOMINAR EL TEMA ");
       }
       else
       {
         printf (" SI JUEGAS AL NIVEL FACIL CAMBIATE AL DIFICIL ");
       }
       gotoxy (3,25);
       printf("Pulsa INTRO para continuar ...");
       do
       {
          CONTINUA = getch();
       }
       while ( CONTINUA != 13);
       setgraphmode (MODO);
       cleardevice();
       *DESTRUIDOS = 0;
       TOTAL = 0;
    }
  }
/**********************************************************************************************/
