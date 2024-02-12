#include "ph-denomination.h"
#include <stdio.h>

// Didn't use float to prevent floating point inaccuracies
const int phPesoValues[] = { 1000, 500, 200, 100, 50, 20, 10, 5, 1 };
const int phCentavoValues[] = { 25, 10, 1 };


int getPesosFromDenomination(const PHCashDenomination* denomination, enum PH_PESOS unit)
{
	return denomination->pesos[unit];
}

int getCentavosFromDenomination(const PHCashDenomination* denomination, enum PH_CENTAVOS unit)
{
	return denomination->centavos[unit];
}

PHCashDenomination generateDenomination(int pesos, int centavos)
{
	PHCashDenomination denomination;
	denomination.totalPesos = pesos;
	denomination.totalCentavos = centavos;

	for (int i = 0; i < PH_PESO_LENGTH; i++)
	{
		const int count = pesos / phPesoValues[i];
		denomination.pesos[i] = count;
		pesos -= count * phPesoValues[i];
		
	}

	for (int i = 0; i < PH_CENTAVO_LENGTH; i++)
	{
		const int count = centavos / phCentavoValues[i];
		denomination.centavos[i] = count;
		centavos -= count * phCentavoValues[i];
	}

	return denomination;
}

void printDenomination(const PHCashDenomination* denomination)
{
	for (int i = 0; i < PH_PESO_LENGTH; i++)
	{
		printf("PHP %d x%d = %d\n",
			       	phPesoValues[i], 
				denomination->pesos[i], 
				phPesoValues[i] * denomination->pesos[i]);
	}

	for (int i = 0; i < PH_CENTAVO_LENGTH; i++)
	{
		printf("PHP 0.%d x%d = 0.%d\n", 
				phCentavoValues[i], 
				denomination->centavos[i],
				phCentavoValues[i] * denomination->centavos[i]);
	}

	printf("==============\nPHP %d.%d\n", denomination->totalPesos, denomination->totalCentavos);
}

