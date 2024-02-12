/*
Jamesdale Paldeng
BSCS 1-5

Create a program in C where a client withdraws cash from the bank, the system will print a
report and give it to the client as the teller gives the cash.   The report shows the number of
denominations (notes and coins) of the total cash withdrawn.   Use Philippine currency.

The teller inputs the total cash to be withdrawn.

Use a function to count for the number of each denomination and its total.   At the end of the
report add the total amount which should be equal to the amount withdrawn by the client.


Program Arguments:
--help for list of commands
--denomination [amount] to get count of denomination from amount
--test to run unit tests
*/

#include <stdio.h>
#include <errno.h>
#include <string.h>

#include "ph-input.h"
#include "ph-denomination.h"
#include "test.h"

void getDenominationAndPrint(const char* amount)
{
	int pesos = getPesos(amount);
	int centavos = getCentavos(amount);

	PHCashDenomination denomination = generateDenomination(pesos, centavos);
	printDenomination(&denomination);
}

int main(int argc, char* argv[])
{
	if (argc <= 1)
	{
		// Gui mode
		char amount[50];  // Increase if overflow
		printf("Enter amount (PHP): ");
		scanf("%s", amount);
	
		if (!isValidPhValue(amount))
		{
			fprintf(stderr, "Invalid input\n");
			return 1;
		}

		getDenominationAndPrint(amount);
		return 0;
	}

	// Argument handling
	for (int i = 1; i < argc; i++)
	{
		const char* arg = argv[i];
		if (strcmp(arg, "--help") == 0)
		{
			printf("List of Commands:\n"
					"--denomination [amount] \n"
					"--test\n");
		}
		else if (strcmp(arg, "--denomination") == 0)
		{
			// For retrieving denominations from amount given in argument
			if (i + 1 > argc)
			{
				fprintf(stderr, "Argument too short, proper command is --denomination [amount]\n");
				errno = EINVAL;
				return 1;
			}

			const char* amount = argv[i + 1];
			if (!isValidPhValue(amount))
			{
				fprintf(stderr, "Argument invalid, %s is not a valid Philippine monetary unit\n", amount);
				errno = EINVAL;
				return 1;
			}

			getDenominationAndPrint(amount);
			i += 1;  // To skip the amount argument
		}
		else if (strcmp(arg, "--test") == 0)
		{
			RUN_ALL_TESTS();
		}
		else
		{
			printf("Type --help for list of commands\n");
			return 0;
		}
	} 
}

