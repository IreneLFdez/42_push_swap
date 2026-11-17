/* =========================================================== */
/*        TEST 1: How does the computer print out bits?        */
/* =========================================================== */

#include <stdio.h>

void print_binary(unsigned int number) {
	int started = 0;

	printf("  ----- Printing nº %u -----\n", number);
	printf("       ---[PARAMS]---\n");
	printf("sizeof(number) * 8 - 1 = %lu\n", sizeof(number) * 8 - 1);
	printf("[RESULT] = ");
	for (int i = sizeof(number) * 8 - 1; i >= 0; i--)
	{
		int bit = (number >> i) & 1U;

		if (bit)
			started = 1;

		if (started)
			printf("%d", bit);
	}

	if (!started)
		printf("0");

	printf("\n");
}

int main() {
	printf("\n===== PRINTING OUT BITS =====\n");
	print_binary(42);  // 101010
	print_binary(10);  // 1010
	print_binary(0);   // 0
}