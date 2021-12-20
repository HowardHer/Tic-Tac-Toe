#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tic_tac_toe.h"

int main(){
	int choice = 0;
	int current_number_of_players = 0;
	char player1[20];
	char player2[20];
	struct people players[SIZE];
	FILE *record_file;
	record_file = fopen("record.txt", "r+");

	/* Check if the record file exist.
	 * If exists, then read the record.
	 * Otherwise, return -1 and exit.
	 */
	if(record_file == NULL){
		printf("The record file does not exist.\n");
		return -1;
	}else{
		read_record(record_file, players, &current_number_of_players);
	}

	printf("Welcome to the Tic-Tac_Toe game!\n");

	while(choice != 3){
		printf("\nEnter a number to proceed:\n");
		printf("1. Start a new game\n");
		printf("2. View Tic-Tac-Toe record\n");
		printf("3. Quit\n\n");
		scanf("%d", &choice);
		printf("\n");

		if(choice == 1){
			printf("Enter player 1's name:\n");
			scanf("%s", player1);
			printf("Enter player 2's name:\n"); 
			scanf("%s", player2);
			//start_a_game()
		}else if(choice == 2){
			print_record(players, current_number_of_players);
		}
	}
	fclose(record_file);
	return 0;
}