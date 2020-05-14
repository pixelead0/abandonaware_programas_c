#include <stdio.h>
#include <conio.h>
main()
{
  int i;
  long int x;
  printf ("\n programa que realiza la suma del 1 al 1000\n");
  x=0;
  for(i=1;i<=1000;i++)
  x=i+x;
  printf("%ld",x);
  getch();
}

