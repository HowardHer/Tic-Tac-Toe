#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tic_tac_toe.h"


/*
 * initialize a new person
 */
struct people initialize_person(struct people person, char name[]){
	strcpy(person.name, name);
	person.win = 0;
	person.tie = 0;
	person.loss = 0;
	return person;
}

/*
 * read the record stored in the file
 * and store it to the people array
 */
void read_record(FILE *record, struct people *players, int *number_of_players){
	char line[50];
	int i = 0;
	int count;
	char win[10];
	char tie[10];
	char loss[10];
	int char_count = 0;

	/*skip the first two lines*/
	if(fgets(line,50,record) == NULL){
		printf("No Record to show");
		return;
	}
	fgets(line,50,record);

	while(fgets(line,50,record) != NULL){
		/*parse player name*/
		for(count = 0;count < 20;count++){
			if(line[count] != ' '){
				players[i].name[count] = line[count];
			}else{
				players[i].name[count] = '\0';
				break;
			}
		}

		for(count = 21;count < 29;count++){
			if(line[count] != '|'){
				win[char_count] = line[count];
				char_count++;
			}else{
				win[char_count] = '\0';
				break;
			}
		}
		char_count = 0;
		players[i].win = atoi(win);

		for(count = 29;count < 37;count++){
			if(line[count] != '|'){
				tie[char_count] = line[count];
				char_count++;
			}else{
				tie[char_count] = '\0';
				break;
			}
		}
		char_count = 0;
		players[i].tie = atoi(tie);

		for(count = 37;count < 45;count++){
			if(line[count] != '|'){
				loss[char_count] = line[count];
				char_count++;
			}else{
				loss[char_count] = '\0';
				break;
			}
		}
		char_count = 0;
		players[i].loss = atoi(loss);
		i++;
	}
	*number_of_players = i;
	return;
}

/*
 * print the record stored in the people array
 */
void print_record(struct people *players, int number_of_players){
	int i = 0;
	printf("Name                |   wins|   ties| losses|\n"
		   "---------------------------------------------\n");
	for(i = 0;i < number_of_players;i++){
		printf("%-20s|%7d|%7d|%7d|\n",players[i].name,players[i].win,players[i].loss,players[i].tie);
	}
}

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