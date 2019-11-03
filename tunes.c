#include "listfunctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct song_node{
  char name[100];
  char song[100];
  struct song_node* next;
};

int getIndex(char firstChar){
  if(firstChar<97 && firstChar>122){
    return 0;
  }
  else{
    return firstChar-96;
  }
}

struct song_node** add_song(struct song_node* library[27],char artist[100], char music[100]){
  char firstChar = artist[0];
  if(firstChar<97 && firstChar>122){
    //library[0]=insert_alphabetical(library[0],artist,music);
    insert_alphabetical(library[0],artist,music);
    return library;
  }
  //library[firstChar-96]=insert_alphabetical(library[firstChar-96],artist,music);
  insert_alphabetical(library[firstChar-96],artist,music);
  return library;
}

void printLibrary(struct song_node **library){
  int i;
  for(i=0;i<27;i++){
    print_list(library[i]);
  }
}

struct song_node* search_for_song(struct song_node* library[27], char artist[100], char music[100]){
  char firstChar = artist[0];
  int index = getIndex(firstChar);
  return search(library[index],artist,music);
}

struct song_node* search_for_artist(struct song_node* library[27], char artist[100]){
  char firstChar = artist[0];
  int index = getIndex(firstChar);
  return search_artist(library[index],artist);
}

void print_letter(struct song_node** library, char letter){
  int index = getIndex(letter);
  print_list(library[index]);
}

void shuffle(struct song_node* library[27], int numSongs){
  int i;
  for(i=0;i<numSongs;i++){
    struct song_node* newSong = random_song(library[rand()%27]);
    printf("%s by %s", newSong->song, newSong->name);
  }
}
