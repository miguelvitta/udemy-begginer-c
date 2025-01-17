#include <stdio.h>
#include <stdbool.h>

int main()
{
    int p = 0;
    int i = 0;

    int primes[2000] = {0};
    int primeIndex = 2;

    bool isPrime = false;

    primes[0] = 2;
    primes[1] = 3;

    for(p = 5; p <= 8000; p = p + 2)
    {
        isPrime = true;

        for(i = 1; isPrime && p / primes[i] >= primes[i]; ++i)
            if(p % primes[i] == 0)
                isPrime = false;

        if(isPrime == true)
        {
            primes[primeIndex] = p;
            ++primeIndex;
        }
    }

    for(i = 0; i < primeIndex;  ++i )
         printf("%i  ", primes[i]);

    printf("\n");
    return 0;
}
