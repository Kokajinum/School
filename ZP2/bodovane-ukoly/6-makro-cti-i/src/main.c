/* Zadání:
 *
 * Jakub Kadlčík [jakub.kadlcik01@upol.cz]
 *
 * Product is under The BSD 3-Clause License
 * Copyright (c) 2012, Jakub Kadlčík
 * All rights reserved.
 */

#define cti_int(i) (scanf("%d", &i), i)

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int j, k;

	//scanf("%d", &j) && j;

	printf("Zadejte cele čislo: ");
	if((j = cti_int(k)) == 0)
		printf("nula\n");
	else
		printf("%i %i\n", j, k);
	return 0;
}
