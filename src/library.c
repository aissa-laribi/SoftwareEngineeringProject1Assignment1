#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "library.h"



int insertArtists(char data[MAX_ARTISTS][MAX_SONGS][MAX_LENGTH], unsigned short numOfArtists) {

	unsigned short length; /*Variable get the length of the string artist (data[current number of artists][0]) */

	/*Do while loop to force the user to always enter an artist*/
	do{
		printf("Insert an artist/group name:");
		fgets(data[numOfArtists][0], MAX_LENGTH, stdin);
		if(strcmp(data[numOfArtists][0], "\n") == 0){
			printf("Please enter a valid artist/group name\n");
		}

		}
		while(strcmp(data[numOfArtists][0] , "\n") == 0);

	/*Here we need the length of the artist data[current number of artists][0] to add '\0'
	 * at the end of the string. Otherwise, the later printing output will not fit in one line*/
	length = strlen(data[numOfArtists][0]);
	data[numOfArtists][0][length - 1] = '\0';
	/*Then, the current number of artists is incremented and returned. This way, the function to
	 * insert songs can be called. See while loop in line 36 in the main.c file                        */
	++numOfArtists;
	return numOfArtists;
}

void insertSongs(char data[MAX_ARTISTS][MAX_SONGS][MAX_LENGTH], unsigned short numOfArtists){
	/*Variable to track the number of songs, it starts at 1 (data[numOfArtists][1])
	 * because data[numOfArtists][0] is for the name of the artist                */

	unsigned short numOfSongs = 1;

	/*Do while loop to ensure the user always enter at least one song*/
	do{
		printf("Insert Song %d for %s: ", numOfSongs, data[numOfArtists][0]);
		fgets(data[numOfArtists][numOfSongs], MAX_LENGTH, stdin);

		if(strcmp(data[numOfArtists][1], "\n") == 0)
			printf("Please enter at least one song for %s\n", data[numOfArtists][0]);
	}
	while(strcmp(data[numOfArtists][1], "\n") == 0);
	++numOfSongs; /*Now, numOfSongs is equal to 1*/
	/*This while loop will get the songs until numOfSongs equal 4 or until the user enters an empty song*/
	while(numOfSongs < 4 ){
		printf("Insert Song %d for %s: ", numOfSongs, data[numOfArtists][0]);
		fgets(data[numOfArtists][numOfSongs], MAX_LENGTH, stdin);

		/*If the user enter no artist, then it is assumed the user is done
		 * with this artist and wants to either enter a new artist or get the shuffled playlist*/
		if(strcmp(data[numOfArtists][numOfSongs], "\n") == 0){
				break;
						}
		++numOfSongs;
	}
}

void sortArtists(char data[MAX_ARTISTS][MAX_SONGS][MAX_LENGTH], unsigned short numOfArtists){

	/*This string will be used as a buffer for swapping 2 strings*/
	char buffer[1][MAX_SONGS][MAX_LENGTH];

	unsigned short i;
	unsigned short j;
	/*The minIndex variable is a variable to track the index from where the data has to be sorted*/
	/*All elements below minIndex are sorted*/
	unsigned short minIndex = 0;
	/* minIndexChanged kind of boolean-like variable to track the state of the current minimum index *
	 * of data whether the mimimum index of the sort need to be changed*/
	unsigned short minIndexChanged = 0;

	/*This nested loop will sort the artists and corresponding songs using a Selection Sort algorithm *
	 * It starts with i assigned 0, j assigned 1; j will keep comparing with data[i] data[j] until    *
	 * data[j] < data[i]. If so; it will swap them and iterate from i, otherwise it will keep iterating*
	 * from j   */
	for(i= 0; i < numOfArtists; i++){
		/*Always assigning MinIndex to i after a swap because it is compared with j until j is lower than i*/
		minIndex = i;
		/*Always assigning MinIndexChanged to 0 otherwise it will keep swapping i and j even if i is lower than j*/
		minIndexChanged = 0;
		for(j=i+1; j < numOfArtists; j++){
				/*Check if the current the next artist (j)is lower than the artist located at minIndex*/
				/*If so, a swap will be needed*/
	            if(strcmp(data[j][0], data[minIndex][0]) < 0){
	                minIndex = j;
	                minIndexChanged = 1; /*Trigger the need to swap*/
	            }
	        }
				/*If a swap is needed it will swap the 2 artists and their corresponding songs
				 * and iterates from i, otherwise it keeps iterating from j to find any value lower than i*/
	            if(minIndexChanged){

	            	/* Swapping artists*/
	                strcpy(buffer[0][0],data[i][0]);
	                strcpy(data[i][0], data[minIndex][0]);
	                strcpy(data[minIndex][0], buffer[0][0]);

	                /* Swapping artists song 1*/
	                strcpy(buffer[0][1],data[i][1]);
	                strcpy(data[i][1], data[minIndex][1]);
	                strcpy(data[minIndex][1], buffer[0][1]);

	                /* Swapping artists song 2*/
	                strcpy(buffer[0][2],data[i][2]);
	                strcpy(data[i][2], data[minIndex][2]);
	                strcpy(data[minIndex][2], buffer[0][2]);

	                /* Swapping artists song 3*/
	                strcpy(buffer[0][3],data[i][3]);
	                strcpy(data[i][3], data[minIndex][3]);
	                strcpy(data[minIndex][3], buffer[0][3]);

	            }
	    }
}
void sortSongs(char data[MAX_ARTISTS][MAX_SONGS][MAX_LENGTH]) {

	/*current artist will keep track of the row in the data (data[current artist][MAX_SONGS][MAX_LENGTH]*/
	/*i,j used for iterating data*/
	unsigned short current_artist,i,j;
	/*The minIndex variable is a variable to track the index from where the data has to be sorted*/
	/*All elements below minIndex are sorted*/
	unsigned short minIndex;
	/* minIndexChanged kind of boolean-like variable to track the state of the current minimum index *
	 * of data whether the minimum index of the sort need to be changed*/
	unsigned short minIndexChanged;
	/*This string will be used as a buffer for swapping 2 strings*/
    char swap[MAX_LENGTH];
    /*Same Selection sort algorithm, except one loop is added to keep track of the songs of the *
     * current artist and it is not used in the comparison process*/


    for (current_artist = 0; current_artist < MAX_ARTISTS; current_artist++) {
    	for (i = 1; i < MAX_SONGS - 1; i++) {
    		minIndex = i;
    		minIndexChanged =0;
            for (j = i + 1; j < MAX_SONGS; j++) {
                if (strcmp(data[current_artist][j], data[current_artist][minIndex]) < 0) {
                    minIndex = j;
                    minIndexChanged = 1;
                }

            }

            if (minIndexChanged) {
                strcpy(swap, data[current_artist][i]);
                strcpy(data[current_artist][i], data[current_artist][minIndex]);
                strcpy(data[current_artist][minIndex], swap);
            }
        }
    }
}

void shuffle(char data[MAX_ARTISTS][MAX_SONGS][MAX_LENGTH]){
	/*Keep track of the total_songs to be played*/
	unsigned short total_songs = 0;
	/*Arbitrary array of 4 integers to be shuffled later and each index of this array *
	 * will be passed to data to be printed*/
	unsigned short artist_order[MAX_ARTISTS] = {2,1,0,3};
	unsigned short i,j,swap;

	/*Call the random generator taking as input current Unix time*/
	srand(time(NULL));

	/*Shuffling the value of each index of data[MAX_ARTISTS]*/
	for(i = 1; i < MAX_ARTISTS; i++){
		j = rand()%(i+1);
		if(j!=i){
			swap = artist_order[j];
			artist_order[j] = artist_order[i];
			artist_order[i] = swap;
		}
	}

	/*If 4 artists and 3 songs per artist it will return 24 songs shuffled*/
	while(total_songs < 25){
	for(i = 0; i < 4 ; i++) {
			j = (rand()%(3)) + 1;
			if(strcmp(data[i][j], "\n") != 0){
			printf("%s - %s", data[artist_order[i]][0], data[artist_order[i]][j]);
			total_songs++;
			}
			if(total_songs == 24)
				break;
			if(j== 3 && strcmp(data[artist_order[i]][1], "\n") != 0 && strcmp(data[artist_order[i]][2], "\n") != 0){
				/*It will print 2 additional songs from the same artist*/
				if(strcmp(data[artist_order[i]][1], "\n") != 0)
				printf("%s - %s", data[artist_order[i]][0], data[artist_order[i]][1]);
				total_songs++;
				if(total_songs == 24)
								break;
				if(strcmp(data[artist_order[i]][2], "\n") != 0)
				printf("%s - %s", data[artist_order[i]][0], data[artist_order[i]][2]);
				total_songs++;
				if(total_songs == 24)
								break;
			} else if(j== 1 && strcmp(data[i][j], "\n") != 0 && strcmp(data[artist_order[i]][3], "\n") != 0){
				/*It will print 1 additional songs from the same artist*/
				if(strcmp(data[artist_order[i]][3], "\n") != 0)
				printf("%s - %s", data[artist_order[i]][0], data[artist_order[i]][3]);
				total_songs++;
				if(total_songs == 24)
								break;
			}
	}
	if(total_songs == 24)
					break;
	}
}

/*Printing the sorted playlist*/
void printSongs(char data[MAX_ARTISTS][MAX_SONGS][MAX_LENGTH], unsigned short numOfArtists){
	for(size_t i = 0;    i < numOfArtists ;i++)  {
		printf("%s \n",data[i][0]);
		for(  size_t j = 1; j < 4;j++){
			if(strcmp(data[i][j], "\n") != 0){
				printf("  - %s",data[i][j]);
			}
			else if(strcmp(data[i][j], "\n") != 0){
				continue;
			}
		}
	}
}
