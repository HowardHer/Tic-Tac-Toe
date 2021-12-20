#define SIZE 20

struct people{
	char name[20];
	int win;
	int tie;
	int loss;
};

/*
 * initialize a new person
 */
struct people initialize_person(struct people person, char name[]);

/*
 * read the record stored in the file
 * and store it to the people array
 */
void read_record(FILE *record, struct people *players, int *number_of_players);

/*
 * print the record stored in the people array
 */
void print_record(struct people *players, int number_of_players);

/* 
 * return 0 if participant1 wins
 * return 1 if participant2 wins
 * return 2 if the players are tied
 */
int start_a_game(char participant1[], char participant2[], struct people *players);

/*
 * sort the record according to the number of wins
 */
void sort(struct people *players);