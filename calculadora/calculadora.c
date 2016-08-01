#include <stdio.h>
#include <stdlib.h>
#include "suma.h"
#include "resta.h"
#include "multiplicacion.h"
#include "division.h"
int main(void)
{
	int opc;
	char espera;
	float num1,num2,result;
	system("clear");
	printf("\t\t..::Calculadora::..\n\n");
	printf("Ingrese el numero de la operacion a realizar\n\n");
	printf("1.- Suma\n");
	printf("2.- Resta\n");
	printf("3.- Multiplicacion\n");
	printf("4.- Division\n");
	scanf("%d",&opc);
	if(opc<=4 && opc>0)
	{
		float result,num1,num2;
		system("clear");
		printf("opc: %d\n\n",opc);
		printf("Ingresa el primer numero\n");
		scanf("%f",&num1);
		printf("Ingresa el segundo numero\n");
		scanf("%f",&num2);

		if(opc==1)
			result=suma(num1,num2);
		if(opc==2)
			result=resta(num1,num2);
		if(opc==3)
			result=multiplica(num1,num2);
		if(opc==4)
			result=division(num1,num2);
		printf("Resultado: %f\n\n",result);
	}
	else
	{
		printf("Error: Opcion no valida\n");
		sleep(2);
	}
	return 0;
}

void mensaje()
{}
