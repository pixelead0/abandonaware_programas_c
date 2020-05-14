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
 printf("5.- Salir");
 printf("\n\n Que operacion desea realizar? ");
 scanf("%d",&opc);
 switch (opc)
 {
  case 1:
   {
    r=a+b;
    printf("La suma de %.0f + %.0f = %.0f",a,b,r);
    goto menu;
   }  
  case 2: 
   {
    r=a-b;
    printf("\nLa diferencia de %.0f - %.0f = %.0f",a,b,r);
    r2=b-a;
    printf("\nLa diferencia de %.0f - %.0f = %.0f",b,a,r2);
    goto menu;
   }
  case 3:
   {
    r=a*b;
    printf("El producto de %.0f * %.0f = %.0f",a,b,r);
    goto menu;
   }  
  case 4:
   {
    r=a/b;
    printf("\nLa divison de %.2f / %.2f = %.4f",a,b,r);
    r2=b/a;
    printf("\nLa divison de %.2f / %.2f = %.4f",a,b,r2);
    goto menu;
   }  
   case 5:
   {
     break;
   }  

  default:
    {
    printf("OPCION INVALIDA\n");
    goto menu;
    }
 }

}
