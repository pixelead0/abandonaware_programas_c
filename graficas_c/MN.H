void presentacion(void);
void graficos(void);

 int gd,gm;
void presentacion(void)
{
 graficos();
 rectangle(0,0,639,479);
 rectangle(10,10,629,469);
 setfillstyle(1,1);
 floodfill(320,240,WHITE);
 settextjustify(CENTER_TEXT,CENTER_TEXT);
 settextstyle(TRIPLEX_FONT,HORIZ_DIR,7);
 outtextxy(320,150,"METODOS");
 outtextxy(320,210,"");
 outtextxy(320,270,"NUMERICOS");
 settextjustify(LEFT_TEXT,LEFT_TEXT);
 settextstyle(DEFAULT_FONT,HORIZ_DIR,1);

 outtextxy(465,430,"Garcia Quiroz Adan");
 outtextxy(490,445,"8/02/2001");
 outtextxy(500,460,"C4V4");
 settextjustify(CENTER_TEXT,LEFT_TEXT);
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
