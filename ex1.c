#include <stdio.h>
#include <stdlib.h>

int odd(int number)
{
	/* Is the number odd? */
	if ((number / 2) * 2 == number) {
		return 0;
	} else {
		return 1;
	}
}

void binary(unsigned int number)
{
	/* print decimal `number' in binary */
	int index;
	char result[4];

	for (index = sizeof(result) - 1; index >= 0; index--) {
		result[index] = (char)odd(number);
		number = number / 2;
	}

	for (index = 0; index < sizeof(result); index++) {
		printf("%d", result[index]);
	}
}

void base(unsigned int number, unsigned int base)
{
	/* print decimal `number' to the given `base' */
	int index;
	unsigned int new, remainder;
	char result[4];

	for (index = sizeof(result) - 1; index >= 0; index--) {
		new = number / base;
		remainder = number - (new * base);
		result[index] = (char)remainder;
		number = new;
	}

	for (index = 0; index < sizeof(result); index++) {
		printf("%d", result[index]);
	}
}

int main()
{
	// Test odd
	unsigned int number;
	for (number = 0; number < 10; number++) {
		printf("%d is ", number);
		if (1 == odd(number)) {
			printf("ODD");
		} else {
			printf("EVEN");
		}
		printf("\n");
	}
	printf("\n");

	// Test binary
	for (number = 0; number < 10; number++) {
		printf("%d == 0x", number);
		binary(number);
		printf("\n");
	}
	printf("\n");

	// Test base
	unsigned int b;
	for (b = 2; b < 11; b++) {
		for (number = 0; number < 11; number++) {
			printf("%d in base 10 is ", number);
			base(number, b);
			printf(" in base %d", b);
			printf("\n");
		}
		printf("\n");
	}
	printf("\n");

	exit(EXIT_SUCCESS);
}
