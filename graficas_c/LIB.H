double f(double x);
double a,b,x,ftol,xtol;
int   n,ntol;

void adquis(void);
void siguiente (void);
void  Resultado(void);
void  final(float);


   void adquis(void)
      {
      do {
	  printf("\n introduce el valor del extremo izqdo.....a : ");
	  do {
	    scanf("%lf",&a);
	    if (f(a)==0)
	    {
	    printf ("\n El valor %lf es una raiz \n",a);
	    printf ("introduce el valor del extremo izqdo.....a: ");
	    }
	  } while (f(a)!=0);
	  printf("introduce el valor del extremo derecho...b : ");
	  do {
	    scanf ("%lf",&b);
	    if (f(b)==0)
	    {
	    printf (" \nEl valor %lf es una raiz\n",b);
	    printf("introduce el valor del extremo derecho...b : ");
	    }
	  } while (f(b)!=0);

	  if ((f(a)*f(b))>0)
	  {
	     printf("\n\n********************************************\n");
	     printf("     en este intervalo la funcion definida no tiene ninguna raiz \n");
	     printf("     o tiene un numero par de ellas \n");
	     printf("     introduce un nuevo intervalo \n");
	     printf("********************************************\n");
	  }
	  } while ((f(a)*f(b))<0);

	  printf("introduce la tolerancia de la funcion, %lf : ", ftol);
	  scanf("%lf",ftol);
	  printf("introduce la tolerancia del interval %lf ", xtol);
	  scanf("%lf",xtol);
	  printf("introduce la tolerancia de las iteraciones %d",ntol);
	  scanf("%d",ntol);
	  n=1;
	  x=(a+b)/2;
   }


   void siguiente (void)
      {
	  if ((f(a)*f(x))<0)
	    {
	     b=x;
	     printf ("    &lf , %lf,",a,x);
	     printf(" %d   iteracion/es",n);
	    }
	  else
	    {
	     a=x;
	     printf("  %lf  , %lf",x,b);
	     printf("%d  iteracion/es",n);
	    }
      x=(a+b)/2;
      n=n+1;
      }

   void  Resultado(void)
      {
	  if (f(x)==0)
	    {
		printf("\n\n ********** EL PROCESO DE BUSQUEDA HA FINALIZADO **********\n");
		printf ("\n CAUSA DE LA FINALIZACION : f(x)=0\n");
		printf("En %lf he encontrado una raiz exacta\n",x);
	    }
	  else
	     if (abs(f(x))<ftol)
	     {
		printf ("\n\nCAUSA DE LA FINALIZACION : abs(f(x))< FTOL \n");
		printf("valor de f(x) es:%lf \n ",f(x));
		printf("He encontrado una raiz aproximada siendo esta..:%lf \n", x);
	     }
	     else
		 if (abs(b-a)<xtol)
		    {
			printf ("\n\nCAUSA DE LA FINALIZACION : abs (b-a)< XTOL \n");
			printf("valor de f(x) es: %lf \n",f(x));
			printf("Hemos llegado a un intervalo demasiado peque¤o \n");
			printf("siendo la raiz %lf \n",x);
		    }
		else
		    if (n==ntol)
		    {
		      printf ("CAUSA DE LA FINALIZACION : n=ntol\n");
		      printf("valor de f(x) es: %lf \n",f(x));
		      printf("El numero de iteraciones es mayor que %lf \n ",ntol);
		    }
      }

      void final(float res)
	  {
	  float x;
	      res=(n=ntol) || (f(x)=0) || (abs(f(x))<ftol) || (abs(b-a)<xtol);
	      final=res;
	  }


double f(double x)
  {
   f = x - (2*x)-10);
  }
