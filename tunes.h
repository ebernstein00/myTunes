int getIndex(char firstChar);

void add_song(struct song_node** library,char artist[100], char music[100]);

void printLibrary(struct song_node** library);

struct song_node* search_for_song(struct song_node* library[27], char artist[100], char music[100]);

struct song_node* search_for_artist(struct song_node* library[27], char artist[100]);

void print_letter(struct song_node** library, char letter);

void shuffle(struct song_node** library, int numSongs);
