#include<stdio.h>
#include<conio.h>
#include<math.h>
//#include<stdlib.h>
void main()
{
 clrscr();
 float c,fa,fb,fc,a,b;

 gotoxy(30,4); printf("***METODO DE BISECCION***\n\n\n");
 printf("Porfavor,introduce el valor A del intervalo:");
 scanf("%f",&a);
 printf("Porfavor,introduce el valor B del intervalo:");
 scanf("%f",&b);
 c=(a+b)/2;
 printf("a=%f",a);
 printf("b=%f",b);
 printf("c=%f",c);
 fa= a*a*a + 4*(a*a) - 10;
 fb= b*b*b + 4*(b*b) - 10;
 fc= c*c*c + 4*(c*c) - 10;
 printf("fa=%f",fa);
 printf("fb=%f",fb);
 printf("fc=%f",fc);
    if(fa<0 && fa<fc)
     {
       b=c;
     }
    else
    {
       c=a;
    }
c=(a+b)/2;
 printf("a=%f",a);
 printf("b=%f",b);
 printf("c=%f",c);
 fa= a*a*a + 4*(a*a) - 10;
 fb= b*b*b + 4*(b*b) - 10;
 fc= c*c*c + 4*(c*c) - 10;
printf("fa=%f",fa);
printf("fb=%f",fb);
printf("fc=%f",fc);
}

