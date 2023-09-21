#include <stdlib.h>
#include <stdio.h>
#include <time.h>  // to use time function for random seed.

#define NB_CASES  5
#define MAX_TRY  10


typedef unsigned short int sint;


void init(sint *hidden_cases) {
	time_t *p_t = NULL;
	srand(time(p_t));  // take current timestamp for the random seed;

	// Generate NB_CASES times the random
	// values between 1 and 9.
	for (sint pos = 0; pos < NB_CASES; pos ++)
		hidden_cases[pos] = (rand() % 8) + 1;
}


sint get_and_compare(sint *hidden_cases) {
	/** we ask to the player to propose a combinaison,
      as the typing progresses, we compar*e each number entered
	    to each number contained at hidden cases array. **/
	sint nb_corrects = 0;
	sint value;
	sint pos;

	for (pos = 0; pos < NB_CASES; pos++) {
		scanf("%hu", &value);
		if (value == (*(hidden_cases + pos))) {
			// the current value entered at this position is equal to the
			// value located at this position in array of hidden cases.
			nb_corrects += 1;
		}
	}

	return nb_corrects;
}


void print_combinaison(sint *cases) {
	for (sint pos = 0; pos < NB_CASES; pos++)
		printf("%2d ", cases[pos]);
}


int main() {
	/** Main function */
	sint cases[NB_CASES];
	sint nb_tries = 0;
	sint nb_corrects;

	// do presentation of this game.
	printf("\n");
	printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("@             BIENVENU DANS MASTERMIND             @\n");
	printf("@ Le but de ce jeu est de decouvrir les numeros    @\n");
	printf("@ (de 1 a 9 pris au hasard) contenus dans %02d       @\n", NB_CASES);
	printf("@ cases cachees. Voici un exemple de combinaison   @\n");
	printf("@ pour ces cinq cases cachees :                    @\n");
	printf("@               3  1  3  6  1                      @\n");
	printf("@ Pour decouvrir cette combinaison, vous devez     @\n");
	printf("@ proposer des combinaisons. Apres chaque          @\n");
	printf("@ proposition, on vous indiquera le nombre de      @\n");
	printf("@ numeros corrects et bien places.                 @\n");
	printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");

	// initialise the cases with random numbers:
	init(cases);
	// print_combinaison(cases);

	printf("PS: Vous avez %02d essaies !\n", MAX_TRY);

	do {
		// Get and compare numbers:
		printf("\nProposer une nouvelle combinaison : ");
		nb_corrects = get_and_compare(cases);
		nb_tries += 1;

		if (nb_corrects != NB_CASES) {
			printf("%d numero(s) bien places.\n", nb_corrects);

			if (nb_tries < MAX_TRY)
				printf("Il vous reste encore %d essaies.\n", MAX_TRY - nb_tries);
		}
		else {
			if (nb_tries == 1)
				printf("bravo, vous avez gagne au premier essais !\n");
			else
				printf("bravo, vous avez gagne en %deme essais !\n", nb_tries);

			return EXIT_SUCCESS;
		}

	} while (nb_tries < MAX_TRY);

	printf("\nvous avez perdu ! La bonne combinaison était :");
	print_combinaison(cases);

	printf("\n");
	return EXIT_SUCCESS;
}
