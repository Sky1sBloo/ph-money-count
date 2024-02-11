#include "ph-input.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getPesos(const char* str)
{
	int integerPart = 0;
	sscanf(str, "%d", &integerPart);

	return integerPart;
}

int getCentavos(const char* str)
{
	int decimalPart = 0;
	const char* decimalPoint = strchr(str, '.');
	if (decimalPoint == NULL) return 0;

	sscanf(decimalPoint + 1, "%d", &decimalPart);

	return decimalPart;
}

bool isValidPhValue(const char* str)
{
	char* number;

	double dTest = strtod(str, &number);
	if (number == str) return false;
	if (number[strspn(number, "\t\r\n")] != '\0') return false;  // For white trailing

	// Since centavos are at most two digits
	if (getCentavos(str) >= 100) return false;
	
	return true;	
}
