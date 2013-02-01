#include <stdio.h>
#include <stdlib.h>
#define PRIME 1     /* Create aliases for 0 and 1 */
#define NONPRIME 0

#define LENGTH(x) (sizeof(x)/sizeof(*(x)))

int numbers[1000];


void mark_multiples(int num){
    int ii = num;
    int primes = LENGTH(numbers);

    /* Set all elements which represent multiples of num to NONPRIME. */
    for ( ii = num + num; ii < primes; ii += num ) {
        numbers[ii] = NONPRIME;
    }
}

int get_next_prime(int num){
    /* find the next prime number after `num' */
    int answer;
    int primes = LENGTH(numbers);
    answer = num+1;
    while (numbers[answer] == NONPRIME){
        answer= answer +1;
        if (answer == primes)
            break;
    }
    return answer;
}

main(){
    int ii, next_prime;
    int primes = LENGTH(numbers);

    /* Set all the elements to PRIME. */
    for ( ii = 0; ii < primes; ii++ ) {
        numbers[ii] = PRIME;
    }

    /* 0 and 1 aren't prime, so set numbers[0] and numbers[1] to NONPRIME */
    numbers[0] = NONPRIME;
    numbers[1] = NONPRIME;

    next_prime = 2;
    do{
        mark_multiples(next_prime);
        next_prime = get_next_prime(next_prime);
    } while(next_prime < primes);

    /* Print out the indices of elements which are still set to PRIME */
    for ( ii = 0; ii < primes; ii++ ) {
        if ( PRIME == numbers[ii] ) {
            printf("%d\n", ii);
        }
    }

    exit(0);
}

