#include<stdio.h>
#include<conio.h>
void main()
{
 int opc;
 float a,b,r,r2;
 printf("Programa que calcula cualquiera de las 4 operaciones basicas\n");
 printf("Dame el valor de a");
 scanf("%f",&a);
 printf("Dame el valor de b");
 scanf("%f",&b);
menu:
 printf("\n1.- Suma \n");
 printf("2.- Resta\n");
 printf("3.- Multiplicacion\n");
 printf("4.- Division\n");
 printf("\n\n Que operacion desea realizar? ");
 scanf("%d",&opc);

if (opc==1)
   {
    r=a+b;
    printf("La suma de %.0f + %.0f = %.0f",a,b,r);
   }  

else if (opc==2)
   {
    r=a-b;
    printf("\nLa diferencia de %.0f - %.0f = %.0f",a,b,r);
    r2=b-a;
    printf("\nLa diferencia de %.0f - %.0f = %.0f",b,a,r2);
   }

else if (opc==3)
   { 
    r=a*b;
    printf("El producto de %.0f * %.0f = %.0f",a,b,r);
   }  

else if (opc==4)
   {
    r=a/b;
    printf("\nLa divison de %.2f / %.2f = %.4f",a,b,r);
    r2=b/a;
    printf("\nLa divison de %.2f / %.2f = %.4f",a,b,r2);
   }  

else
    printf("OPCION INVALIDA\n");
}
     