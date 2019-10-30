struct song_node* insert_front(struct song_node* node, char artist[100], char music[100]);

struct song_node* insert_alphabetical(struct song_node* front, char artist[100], char music[100]);

void print_list(struct song_node* front);

struct song_node* search(struct song_node* front, char artist[100], char music[100]);

struct song_node* search_artist(struct song_node* front, char artist[100]);

struct song_node* remove_node(struct song_node* front, char artist[100], char music[100]);

struct song_node* clear_library(struct song_node* front);

struct song_node* random_song(struct song_node* front);
