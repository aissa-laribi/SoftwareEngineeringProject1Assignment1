/*
 ============================================================================
 Name        : assignment1.c
 Author      : Aissa Laribi
 Version     :1.0.0
 Copyright   : Your copyright notice
 Description : Command Line Interface sorting and shuffling a list of songs
			   received as input
 ============================================================================
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "library.h"


int main(void) {
	/*****************************************************************************************************************
	 * Variables declaration and initialized:																		 *
	 * 			char artistsAndSongs will store all the artists and songs from user input;							 *
	 * 			unsigned short numOfArtists will keep track of the number of artists								 *
	 * 			unsigned short *numOfArtistsPtr is a pointer pointing to the address of the variable numOfArtists	 *
	 *****************************************************************************************************************/
	char artistsAndSongs[MAX_ARTISTS][MAX_SONGS][MAX_LENGTH] = {};
	unsigned short numOfArtists = 0;
	unsigned short *numOfArtistsPtr = &numOfArtists;
	unsigned short numOfSongs = 0;
	unsigned short *numOfSongsPtr = &numOfSongs;

	/***************************************************
	*				USER INPUT						   *
	***************************************************/
	/* This while loop will prompt the user to enter artists and songs as input
	While the function to insert artists is true, it calls the function to insert songs
	and pre-increment the value of the number of artists until we get 4 artists*/
	while(insertArtists(artistsAndSongs, *numOfArtistsPtr) != 0 ){
		insertSongs(artistsAndSongs, *numOfArtistsPtr);
		++(*numOfArtistsPtr);
		if(*numOfArtistsPtr == 4)
			break;
	}
	/***************************************************
	*				SORTING 					   	   *
	***************************************************/
    /*The function call will sort the artists alphabetically *
    * it will swap the songs respective to each artist when  *
    * a swap is needed between 2 artists					 */
	sortArtists(artistsAndSongs, *numOfArtistsPtr);
	/*At this stage, the artists are sorted but not the songs*
	* This function will sort the songs artist by artist */
	sortSongs(artistsAndSongs);
	/***************************************************
	*				PRINTING SORTED INPUT			   *
	***************************************************/
	puts("Sorted list of songs:");
	/* This function will print all the elements of the     *
	* sorted data including artists and songs as long  as   *
	* there is no empty song. Otherwise, it be will ignored *
	* Output:												*
	* Artist												*
	* 	- Song 1											*
	* 	- Song 2											*/
	*numOfSongsPtr = printSongs(artistsAndSongs, *numOfArtistsPtr);
	/***************************************************
	*		SHUFFLING AND PRINTING THE PLAYLIST 	   *
	***************************************************/
	puts("Shuffled Playlist:");
	/* This function will shuffle and print all the elements            *
	* of the previous sorted data until we get 24 songs. 			    *
	* The index of the sorted artists will be shuffled and stored in a  *
	* 4-indexes array. Then, it will iterate through this array, print  *
	* the corresponding artist within a song corresponding to a random  *
	* index ranging from 1 to 3. If the index is 3, then it prints index*
	* 3, 1 and 2. If the index is 1, it prints 1 and 3                  *
	* This way we can play a sequence of 3 2 or 1 song from the same    *
	* artist.														    */
	shuffle(artistsAndSongs, *numOfSongsPtr);

	return EXIT_SUCCESS;
}

