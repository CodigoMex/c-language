#include <stdio.h>
#include "division.h"
float division(float num1, float num2)
{
	if(num2>0)
	{
		return (num1/num2);
	}
	else
	{
		printf("El segndo numero tiene que ser mayor a 0\n");
	}
}

