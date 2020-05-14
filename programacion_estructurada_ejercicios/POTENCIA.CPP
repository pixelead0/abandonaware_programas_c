#include<stdio.h>
#include<conio.h>

void main()
{
 clrscr();

 long int x,n;
 long int p;
 printf("Dame el valor del numero  ");
 scanf("%ld",&x);
 printf("A que potencia lo deseas elevar    ");
 scanf("%ld",&n);
 p=1;
 while(n>0)
 {
  p=p*x;
  n=n-1;
  }

 printf("\n\nEl resultado es %ld",p);
 getch();
}
