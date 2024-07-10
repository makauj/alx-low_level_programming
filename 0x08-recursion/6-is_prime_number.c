#include "main.h"
int is_prime_helper(int n, int div);

/**
 * is_prime_number - deermine if n is prime number
 * @n: number
 * Return: 1 is prime else null
 */

int is_prime_number(int n)
{
	if (n <= 1)
	{
		/* 0 and 1 are not prime numbers */
		return (0);
	}
	return (is_prime_helper(n, 2));
}
/**
 * is_prime_helper - recusrively iterates through n
 * @n: number
 * @div: divisor to test if n is prime
 * Return: 1 if prime else null
 */

int is_prime_helper(int n, int div)
{
	if (div * div > n)
	{
		/* if div squared is greater than n, n is prime */
		return (1);
	}
	if (n % div == 0)
	{
		/* if n is divisible by div, n is not prime */
		return (0);
	}
	/* recursively check the next div */
	return (is_prime_helper(n, div + 1));
}
