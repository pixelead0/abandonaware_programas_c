//PROYECTO:
//			PROGRAMA DEL METODO DE NEWTON-RAPHSON

//DIRECTIVAS AL PREPROCESADOR

#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<dos.h>
#include<process.h>

//------------------------------------------------------------

//DECLARACION DE VARIABLES Y CONSTANTES GLOBALES
//------------------------------------------------------------

//DEFINICION DE PROTOTIPOS DE FUNCION
float evalua(float);
float derivada(float);
//------------------------------------------------------------

//DEFINICION DE FUNCION
float evalua(float Xm)
{
	const float LnE=2.728182;
	float LnFxm;
	LnFxm=(pow(LnE,-Xm))-Xm;
	return LnFxm;
}
float derivada(float Xi)
{

}
//------------------------------------------------------------

//BLOQUE PRINCIPAL MAIN
void main(void)
{
  float LnXi1, LnXi, LnFxi, LndFxi, LnEs, LnEa;
  int LnCont=0;
  clrscr();
  printf("\n\n\n\n\n\n\t\t PROGRAMA DEL METODO DE NEWTON RAPHSON");
  printf("\n\t\t\t presione cualquier tecla para continuar");
  getch();
  clrscr();
  printf("\n\n\n\n\n\n\t\t introduzca el valor inicial");
  scanf("%f",&LnXi);
  printf("\n\t\t Calculando:");
  LnEs=0.5*(pow(10,-4));
  do{
		LnXi1=LnXi-evalua(LnXi)/derivada(LnXi);
		if(evalua(LnXi1)==0)
		{
			printf("La raiz exacta es: %f", LnXi1);
			getch();
			exit(0);
		}
		LnEa=LnXi1-LnXi/LnXi1;
		LnXi=LnXi1;
		LnCont++;
		printf("±");
		delay(150);
	}while(LnEa>LnEs||LnCont<31);
  printf("\n La mejor aproximacion de la raiz es: %f", LnXi1);
  getch();
  clrscr();
}