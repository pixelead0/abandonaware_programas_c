/*   E . S . I . M . E .  C U L H U A C A N
		ING. EN COMPUTACION
	      PROGRAMA ELABORADO POR:

	 *    ADAN GARCIA QUIROZ
	 *          C2M1
	 *   PROGRAMACION ESTRUCTURADA
	 *               MARZO / 2001 */

#include"a:\pe.h"

void main()
{
 int opc;
 float a,b,r,r2;

menu:
 limpia(15,1);
 marco(2,3,4,5,2,3);
 gotoxy(10,3);	printf("Programa que calcula cualquiera de las 4 operaciones basicas\n");

 gotoxy(15,5);	printf("Dame el valor de a ");
 scanf("%f",&a);
 gotoxy(15,7);	printf("Dame el valor de b ");
 scanf("%f",&b);

 window(15,9,35,20);
 limpia(14,5);

 cprintf("1.- Suma\n\r");
 cprintf("2.- Resta\n\r");
 cprintf("3.- Multiplicacion\n\r");
 cprintf("4.- Division\n\r");
 cprintf("5.- Salir\n\r");

 cprintf("\n\n Que operacion desea realizar? ");
 scanf("%d",&opc);

window(1,1,80,25);
gotoxy(10,22);
if (opc==1)
   {
    r=a+b;
    printf("La suma de %.0f + %.0f = %.0f\r",a,b,r);
    delay(1000);
    clreol();
    goto menu;
   }

else if (opc==2)
   {
    r=a-b;
    printf("La diferencia de %.0f - %.0f = %.0f\r",a,b,r);
    delay(1000);
    clreol();
    r2=b-a;
    printf("\nLa diferencia de %.0f - %.0f = %.0f\r",b,a,r2);
    delay(1000);
    clreol();
    goto menu;
   }

else if (opc==3)
   {
    r=a*b;
    printf("El producto de %.0f * %.0f = %.0f\r",a,b,r);
    delay(1000);
    clreol();
    goto menu;
   }

else if (opc==4)
   {
    r=a/b;
    printf("La divison de %.2f / %.2f = %.4f\r",a,b,r);
    delay(1000);
    clreol();
    r2=b/a;
    printf("\nLa divison de %.2f / %.2f = %.4f\r",a,b,r2);
    delay(1000);
    clreol();
    goto menu;
   }

else if (opc==5)
   {
    bien();
    goto salir;
   }

else
    {
    error();
    printf("OPCION INVALIDA\r");
    delay(1000);
    clreol();
    goto menu;
    }
 salir:
}
