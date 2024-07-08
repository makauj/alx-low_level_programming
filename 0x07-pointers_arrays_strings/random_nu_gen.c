#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void generate_random_combination(char *result)
{
	const char letters[] = "abcdefghijklmnopqrstuvwxyz";
	const char numbers[] = "0123456789";
	int i;
	
	for (i = 0; i < 3; i++)
		result[i] = letters[rand() % 26];
	for (i = 0; i < 3; i++)
		result[3 + i] = numbers[rand() % 10];
	result[6] = '\0';
}

int main()
{
	char target[] = "abc123"; /* The desired combination */
	char combination[7];      
	/**
	 * 3 letters + 3 numbers + null terminator
	 * Seed the random number generator
	 */
	srand(time(NULL));

    /* Generate combinations until the target is found */
	do
	{
		generate_random_combination(combination);
		printf("Generated combination: %s\n", combination);
	}
	while (strcmp(combination, target) != 0);
	printf("Target combination found: %s\n", combination);
	return 0;
}
