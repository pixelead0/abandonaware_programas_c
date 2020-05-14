void presentacion(void);
void graficos(void);

 int gd,gm,i;
void presentacion(void)
{
 graficos();
  for (i=5; i>=1; i--)
 {
  settextjustify(LEFT_TEXT,LEFT_TEXT);
  settextstyle(DEFAULT_FONT,HORIZ_DIR,i);
  outtextxy((465+i),460,"8/02/2001");
  outtextxy(465,445,"Garcia Quiroz Adan");
  delay(200);
  cleardevice();
 }

 rectangle(0,0,639,479);
 rectangle(10,10,629,469);
 setfillstyle(1,1);
 floodfill(320,240,WHITE);
 settextjustify(CENTER_TEXT,CENTER_TEXT);
 settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
 outtextxy(320,150,"PROGRAMACION");
 outtextxy(320,210,"");
 outtextxy(320,270,"ESTRUCTURADA");
  settextjustify(CENTER_TEXT,LEFT_TEXT);
 settextstyle(TRIPLEX_FONT,HORIZ_DIR,0);
 setcolor(14);
 outtextxy(320,479,"Presione Enter Para Continuar");
 getche();
 closegraph();
}

void graficos(void)
{
 gd=VGA;
 gm=VGAHI;
 initgraph(&gd,&gm,"\\tc\\bgi");
}
