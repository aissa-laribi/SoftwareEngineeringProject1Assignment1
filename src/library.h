#define MAX_ARTISTS 4
#define MAX_SONGS 4
#define MAX_LENGTH 80


/*All the functions declarations in order of calls*/

int insertArtists(char data[MAX_ARTISTS][MAX_SONGS][MAX_LENGTH], unsigned short numOfArtists);

void insertSongs(char data[MAX_ARTISTS][MAX_SONGS][MAX_LENGTH], unsigned short numOfArtists);

void sortArtists(char data[MAX_ARTISTS][MAX_SONGS][MAX_LENGTH], unsigned short numOfArtists);

void sortSongs(char data[MAX_ARTISTS][MAX_SONGS][MAX_LENGTH]);

void printSongs(char data[MAX_ARTISTS][MAX_SONGS][MAX_LENGTH], unsigned short numOfArtists);

void shuffle(char data[MAX_ARTISTS][MAX_SONGS][MAX_LENGTH]);
