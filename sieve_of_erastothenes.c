#include <stdint.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int_fast32_t sieve(int_fast32_t limit, int_fast32_t *primes);

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "usage: %s", argv[0]);
		return 1;
	}
	char *p;
	int_fast32_t limit = strtol(argv[1], &p, 10);

	int_fast32_t primes[limit];
	int_fast32_t size = sieve(limit, primes);

	for (int i = 0; i < size; i++)
	{
		printf("%i\n", primes[i]);
	}
	//free(primes);
	return 0;
}

int_fast32_t sieve(int_fast32_t limit, int_fast32_t *primes)
{
	if (limit < 2) return 0;

	int_fast32_t number_of_primes = 0;
	char *primes_array = calloc(limit + 1, sizeof(char));
	memset(primes_array, 1, limit + 1);
	memset(primes, 0, sizeof(*primes));

	for (size_t i = 0; i < 2; i++)
	{
		primes_array[i] = 0;
	}

	for (int_fast32_t idx = 2; idx < (sqrt(limit) + 1);)
	{
		for (int_fast32_t n_idx = (idx * 2);
			 n_idx < (limit + 1); n_idx += idx)
			 {
				 primes_array[n_idx] = 0;
			 }
			 do
			 {
				 idx++;
				 if (primes_array[idx]) break;
			 } while (idx < (sqrt(limit) + 1));
	}

	for (int_fast32_t j = 1; j < (limit + 1); j++)
	{
		if (primes_array[j])
		{
			primes[number_of_primes++] = j;
		}
	}

	free(primes_array);
	return number_of_primes;
}
