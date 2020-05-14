#include <graphics.h>
#include<math.h>
#include<conio.h>
float pasos,x,y,xp,cambio,yp;
float XPM,Xm,Xpm,XM,yM,ym,ypm,ypM;

float cambioxp(float x)
 {
  return((x-Xm)/(XM-Xm)*(XPM-Xpm)+Xm);
 }

float cambioyp(float y)
 {
  return ((ym-y)/(yM-ym)*(ypM-ypm)+ypM);
 }
float ft=0;
/*
float fun(float x)
 {
  // ft=((4/(M_PI*1))*sin(M_PI*x*1));
  if(x==0)
    return 1;
  else
    return ft;
 }
*/
main()
 {
  Xm=-10,   XM=10,  Xpm=0;
  ym=-15,   yM=15,   ypm=0;

  int driver=VGA,modo=1;
  initgraph(&driver,&modo,"d:\\tc\\bgi");

  XPM=getmaxx(); ypM=getmaxy();
  pasos=(XM-Xm)/(XPM-Xpm);
  int i=1;
  float ft=0;
  for (i=1;i<8;i+=2)
  {
   ft=y;
   for(x=Xm;x<=XM;x+=pasos)
    {
      y=ft+((4/(M_PI*i))*sin(M_PI*x*i));
      xp=cambioxp(x);
      yp=cambioyp(y);
      putpixel(xp,yp,YELLOW);
    }
  }
//    getch();
//    cleardevice();
  getch();
  closegraph();
  return 0;
 }

