//PROYECTO:
//	PROGRAMA DEL METODO DE NEWTON-RAPHSON
//---INSTRUCCIONES AL PREPROCESADOR---
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<dos.h>
//-------------------
float LnEs=0.5*pow(10,-6);

//DEFINICION DE PROTOTIPOS DE FUNCION---
float evalua(float);
float derivada(float);
//-------------------

//DEFINICION DE FUNCION
float evalua(float Xm)
{
	const float LnE=2.718281;
	float Fxm;
	Fxm=pow(LnE,-Xm)-Xm;
	return Fxm;
}

float derivada(float Xm)
{
	int cont;
	float numerador, LnFpxi, tempo;
	while(cont<=30)
	{
		numerador=evalua(Xm)-evalua(tempo);
		LnFpxi=numerador/0.2;
		tempo=Xm;
		Xm=LnFpxi;
		cont++;
	}
	return LnFpxi;
}
//-------------------

//BLOQUE PRINCIPAL MAIN---
void main(void)
{
 float LnXi, LnXi1, LnFxi, LnFxi1, LnEa;
 int LnCont;
 clrscr();
 printf("\n\n\n\n\n\n\t\t  PROGRAMA DEL METODO DE NEWTON-RAPHSON");
 printf("\n\n\t\t presione cualquier tecla para continuar:");
 getch();
 clrscr();
 printf("\n\n\n\n\n\n\t\t introduzca el valor inicial de Xi: ");
 scanf("%f",&LnXi);
 printf("\n\n\t\t Calculando...");
 LnCont=0;
 do{
	LnXi1=LnXi-(evalua(LnXi)/derivada(LnXi));
	if(evalua(LnXi1)==0)
	{
		printf("Raiz encontrada en: %3.10f",LnXi1);
		getch();
		exit(0);
	}
	LnEa=(LnXi1-LnXi)/LnXi1;
	LnXi=LnXi1;
	LnCont++;
	delay(150);
	printf("±");
 }while(LnEa>LnEs||LnCont<=30);
 printf("\n\n\t\t La mejor aproximacion de la raiz es:\t %3.10f", LnXi1);
 getch();
 clrscr();
}
//-------------------