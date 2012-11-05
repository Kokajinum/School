/*
 * Udělat to přes "asociativní" pole
 * 	- místo klíču v podobě 'x' dát (int)'x'
 * 	- Zjistit počet přidaných dokážu, protože to teď mám v kódu
 * Zjištovat největší výskyt znaku už při přidávání do pole
 */
/* Zadání: Napište program, který pro vstupní řetězec
 *     o maximální délce 200 znaků, vypíše,
 *     kolikrát se v něm který znak vyskytuje
 *     (vypište pouze znaky, které se v řetězci vyskytují)
 *     a znak (respektive více znaků), které se v řetězci
 *     vyskytují nejčastěji. Velká a malá písmena se v tomto případě
 *     chápou jako stejné znaky
 *
 * Jakub Kadlčík [jakub.kadlcik01@upol.cz]
 *
 * Product is under The BSD 3-Clause License
 * Copyright (c) 2012, Jakub Kadlčík
 * All rights reserved.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // tolower

int main(int argc, char **argv)
{
	printf("Zadej řetězec: ");
	char slovo[200] = {};
	scanf("%s", slovo);
	printf("\n");

	// Česká abeceda sestává ze 42 písmen
	// Do pole budeme přidávat strukturované prvky
	//    alternativa k asociativnímu poli.
	int vyskyt[200] = { 0 };

	// Unikátní znaky nalezené ve slově
	char uqZnaky[43] = {};

	// Počet výskytů nejvíce se vyskytujícího znaku
	int nejVyskyt = 0;

	// Projdeme slovo a uložíme počet výskytů jednotlivých znaků
	int count = 0;
	int i;
	for(i=0; i<strlen(slovo); i++)
	{
		int poziceNovehoZnaku = count;
		int j=0;
		for(j=0; j<poziceNovehoZnaku; j++)
		{
			if(uqZnaky[j]==tolower(slovo[i]))
			{
				poziceNovehoZnaku = j;
				break;
			}
		}
		vyskyt[tolower(slovo[i])]++;
		uqZnaky[poziceNovehoZnaku] = tolower(slovo[i]);

		if(nejVyskyt<vyskyt[tolower(slovo[i])])
			nejVyskyt=vyskyt[tolower(slovo[i])];

		if(count==poziceNovehoZnaku)
			count++;
	}

	// Vypíšeme kolikrát se který znak vyskytuje
	for(i=0; i<count; i++)
	{
		printf("Znak %c se v řetězci vyskytuje %ix\n", uqZnaky[i], vyskyt[uqZnaky[i]]);
	}
	printf("\n");

	// Vypíšeme nejpočetnější znaky
	printf("Nejčastěji se v řetězci vyskytuje znak: ");
	for(i=0; i<count; i++)
	{
		if(vyskyt[uqZnaky[i]]==nejVyskyt)
			printf("%c ", uqZnaky[i]);
	}
	printf("\n");

	return 0;
}