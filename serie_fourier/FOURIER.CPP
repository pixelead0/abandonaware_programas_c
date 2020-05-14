	/*   E . S . I . M . E .  C U L H U A C A N
		ING. EN COMPUTACION
	      PROGRAMA ELABORADO POR:

	 *    ADAN GARCIA QUIROZ
	 *          C5V1
	 *               SEPTIEMBRE / 2002 */

/*********************************************************************
SE TRANSFORMA UNA FUNCION f(t) PERIODICA A SU RESPECTIVA SERIE
DE FOURIER (LA MISMA FUNCION PERO REPRESENTADA EN UNA SUMA DE
SENOS.
*********************************************************************/

#include <conio.h>
#include <dos.h>
#include "grafxy.h"
#include "ASA.h"

class CSerieFourier
 {
  public:
    inline CSerieFourier(){ };

    inline void ConstruirSerie(double _a,double _b , int _num_terminos = 10)
     {
      a=_a;       b=_b;
      num_terminos = _num_terminos;
      T=b-a;      Wo=(2*M_PI)/T;
     }
  private:
    double T; //periodo de la funcion
    double Wo; //frecuencia
    double a,b; //Intervalo periodico donde se define la funcion T=b-a
    int num_terminos;  //contiene el numero de terminos que se utilizara en
		       //la serie
  public:

    double evaluar_serie( double t );
    inline void Setnum_terminos(int _num_terminos)
     {
      num_terminos = _num_terminos;
     }
 };

double CSerieFourier::evaluar_serie( double t )
{
 double S=0;
 for(int n=1;n<=num_terminos; n+=2)
  S+=(4/(M_PI*n))*sin(n*M_PI*t);
  return S;
}

void main()
{
 autoini("");

 presentacion();
 sale();
 sale2();
 int terminos, escala;
 printf("P r o g r a m a   q u e   c a l c u l a   l a   s e r i e   d e   F O U R I E R \n");
 printf("        4/(n ú Wo) * sin (n ú Wo ú t )   y   l a   g r a f i c a \n\n");
 printf("Hasta cuantos terminos desea graficar la Serie de FOURIER: ");
 scanf("%d",&terminos);
 printf("A que escala desea ver la Grafica: ");
 scanf("%d",&escala);
// getch();

 CRegionXY R(-escala,escala,-escala/2,escala/2);
 R.Ejes();
 double t;
 CSerieFourier escalon;
 escalon.ConstruirSerie(-1,1);

 for(int i=1;i<=terminos;i+=2)
 {
  escalon.Setnum_terminos(i);
  cleardevice();
   R.Ejes();

  for(t=R.xmin(); t<R.xmax(); t+=0.0001 )
   {
   R.punto( t, escalon.evaluar_serie(t), GREEN/*, CONECTAR*/ );
   }
   char *msg=NULL;
   sprintf(msg,"Numero de Terminos de Fourier = %i",i);
   settextjustify(0,0);
   outtextxy(10,10,msg);
   delay(1200);
 }
  getch();
  sale();
  bien();
  sale3();
  closegraph();
}