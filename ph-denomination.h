#pragma once
#define PH_PESO_LENGTH 9
#define PH_CENTAVO_LENGTH 3

enum PH_PESOS
{
	ONE_THOUSAND_PESOS,
	FIVE_HUNDRED_PESOS,
	TWO_HUNDRED_PESOS,
	ONE_HUNDRED_PESOS,
	FIFTY_PESOS,
	TWENTY_PESOS,
	TEN_PESOS,
	FIVE_PESOS,
	ONE_PESOS
};
enum PH_CENTAVOS
{
	TWENTY_FIVE_CENTAVOS,
	TEN_CENTAVOS,
	ONE_CENTAVOS
};


// Holds the count of denominations separated into pesos and centavos
typedef struct PHCashDenomination
{
	int pesos[PH_PESO_LENGTH];
	int centavos[PH_CENTAVO_LENGTH];
	int totalPesos;
	int totalCentavos;
} PHCashDenomination;

/**
 * Generates a denomination from amount given
 */
PHCashDenomination generateDenomination(int pesos, int centavos);

/**
 * Retrieves the number of pesos from a denomination
 * 
 * @param denomination Struct where values will be retrieved
 * @param unit See PH_PESOS enum for possible values
 *
 * @return number of pesos from unit
 */
int getPesosFromDenomination(const PHCashDenomination* denomination, enum PH_PESOS unit);

/**
 * Retrieves the number of centavos from a denomination
 * 
 * @param denomination Struct where values will be retrieved
 * @param unit See PH_CENTAVOS enum for possible values
 *
 * @return number of centavos from unit
 */
int getCentavosFromDenomination(const PHCashDenomination* denomination, enum PH_CENTAVOS unit);

/**
 * Prints all values from denomination
 */
void printDenomination(const PHCashDenomination* denomination);

