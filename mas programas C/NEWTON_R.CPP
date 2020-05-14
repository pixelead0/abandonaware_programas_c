//Este programa encuentra la raiz de una funcion f(x)=xý - x - 3
//aplicando el método de Newton_Raphson.


double Newton_R (void)
{
	int NCS2=4;
	int itera=0;
	double aux1=0;
	double datos[7];
	for (aux1=0; aux1<7; aux1++)
		datos[aux1]=0;


		textcolor(15);
		cprintf("Este programna encuentra las races de la funci•n f(x)=xý-x-3 por el mŠtodo de \n\rNewton-Raphson.\n\n\r");
		cprintf("Introduce Xl: ");
		scanf("%lf", &datos[2]);
		datos[3]=evaluar(datos[2]);


	clrscr();
	errores_NR(datos, 7, 0, itera);
	datos[6]=0.5 * pow(10, 2-NCS2);

	do{
		if(itera==18)
			{

			 textcolor(4);
			 gotoxy(10,24), cprintf("­Presiona enter para presentar los siguientes valores!");
			 do{ }while(getch()!=13);
			 clrscr();
			 itera=0;
			 errores_NR(datos, 7, 0, itera);
			}
		itera++;
/*************************************************************************/
		flushall();
		datos[3]=evaluar(datos[2]);
		datos[4]=evaluar_DF(datos[2]);
		aux1=datos[3]/datos[4];
		datos[1]=datos[2]-aux1;
		datos[0]++;
		if(datos[0]>=2)
			datos[5]=ERPA(datos[2], datos[1]);


		errores_NR(datos, 7, 1, itera);
		datos[2]=datos[1];
/*************************************************************************/
	}while(datos[5]>datos[6] || datos[0]<=2);

	return datos[1];
}