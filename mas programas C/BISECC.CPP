#include<stdio.h>
#include<conio.h>
#include<math.h>

void main()
{
textbackground(0);
clrscr();

int i,n;
float a,b,c,fa,fb,fc;

n=14;
printf("Este programa saca las raices de una ecuacion, por el\n");
printf("METODO DE BISECCION\n\n\n");
printf("De la ecuacion xü + 4xý + 10\t en el intervalo de [A,B]\n");
printf("\nInserte el valor del intervalo A: ");
scanf("%f",&a);
printf("\nInserte el valor del intervalo B: ");
scanf("%f",&b);

printf("   a      c        b                fa     fc       fb");

	printf("\n%.4f \t%.4f\t %.4f\t",a,c,b);

  do
     {
	c=(a+b)/2;
	fa= a*a*a + 4*(a*a)-10;
	printf("\t%.4f",fa);
	fc= c*c*c + 4*(c*c)-10;
	printf("\t%.4f",fc);
	fb= b*b*b + 4*(b*b)-10;
	printf("\t%.4f",fb);

	if (((fc<0)&&(fa<0)) || ((fc>0)&&(fa>0)))
	   {
	    printf("\n%.4f",c);
	    c=(a+b)/2;
	    printf("\t%.4f",c);
	    printf("\t%.4f",b);
	    fa= a*a*a + 4*(a*a)-10;
	printf("\t%.4f",fa);
	fc= c*c*c + 4*(c*c)-10;
	printf("\t%.4f",fc);
	fb= b*b*b + 4*(b*b)-10;
	printf("\t%.4f",fb);

	   }

	  else if (((fc<0)&&(fb<0)) || ((fc>0)&&(fb>0)))
	   {
	    printf("\n%.4f",a);
	    b=c;
	    c=(a+b)/2;
	    printf("\t%.4f",c);
	    printf("\t%.4f",b);
	    	fa= a*a*a + 4*(a*a)-10;
	printf("\t%.4f",fa);
	fc= c*c*c + 4*(c*c)-10;
	printf("\t%.4f",fc);
	fb= b*b*b + 4*(b*b)-10;
	printf("\t%.4f",fb);

	   }
   i++;
   }while(i <= n);

getch();
}
