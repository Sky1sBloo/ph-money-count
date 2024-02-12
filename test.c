#include <stdio.h>

#include "ph-input.h"
#include "ph-denomination.h"

/**
 * Tests all input functions
 */
bool TEST_PH_INPUT()
{
	char testA[][50] = {"9872", "12A3.f", "123.2f", "94321234121.21", "123.123", "0.21"};
	bool testAAnswers[] = { true, false, false, true, false, true};
	const int testALength = sizeof(testA) / sizeof(testA[0]);

	for (int i = 0; i < testALength; i++)
	{
		if (isValidPhValue(testA[i]) != testAAnswers[i])
		{
			fprintf(stderr, "%s doesn't match %d\n", testA[i], testAAnswers[i]);
			return false;
		}
	}

	char testBAndC[][50] = { "1234", "123.", "123.45", ".43", "0.32" };
	int testBAnswers[] = { 1234, 123, 123, 0, 0 };
	int testCAnswers[] = { 0, 0, 45, 43, 32 };
	const int testBAndCLength = sizeof(testBAndC) / sizeof(testBAndC[0]);

	for (int i = 0; i < testBAndCLength; i++)
	{
		if (getPesos(testBAndC[i]) != testBAnswers[i])
		{
			fprintf(stderr, "%s doesn't match %d\n", testBAndC[i], testBAnswers[i]);
			return false;
		}

		if (getCentavos(testBAndC[i]) != testCAnswers[i])
		{
			fprintf(stderr, "%s doesn't match %d\n", testBAndC[i], testCAnswers[i]);
			return false;
		}
	}

	return true;
}

/**
 * Tests all ph denomination functions
 */
bool TEST_PH_DENOMINATION()
{
	int testPesos = 1024;
	int testCentavos = 32;

	// See PH_PESOS enum to undertand format
	int testPesosExpected[] = { 1, 0, 0, 0, 0, 1, 0, 0, 4 };
	int testCentavosExpected[] = { 1, 0, 7 }; 

	PHCashDenomination denomination = generateDenomination(testPesos, testCentavos);

	for (int i = 0; i < PH_PESO_LENGTH; i++)
	{
		if (denomination.pesos[i] != testPesosExpected[i])
		{
			fprintf(stderr, "%d doesn't match %d\n", denomination.pesos[i], testPesosExpected[i]);
			return false;
		}
	}
	for (int i = 0; i < PH_CENTAVO_LENGTH; i++)
	{
		if (denomination.centavos[i] != testCentavosExpected[i])
		{
			fprintf(stderr, "%d doesn't match %d\n", denomination.centavos[i], testPesosExpected[i]);
			return false;
		}
	}

	return true;
}

void RUN_ALL_TESTS()
{
	printf("=======================\n");
	if (TEST_PH_INPUT())
	{
		printf("TEST_PH_INPUT --Success\n");
	}
	else
	{
		printf("TEST_PH_INPUT --FAILED\n");
	}

	if (TEST_PH_DENOMINATION())
	{
		printf("TEST_PH_DENOMINATION --Success\n");
	}
	else
	{
		printf("TEST_PH_DENOMINATION --FAILED\n");
	}
	printf("=======================\n");
}
