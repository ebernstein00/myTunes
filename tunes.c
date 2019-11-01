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

struct song_node** add_song(struct song_node* library[27],char artist[100], char music[100]){
  char firstChar = artist[0];
  if(firstChar<97 && firstChar>122){
    library[0]=insert_alphabetical(library[0],artist,music);
    return library;
  }
  library[firstChar-96]=insert_alphabetical(library[firstChar-96],artist,music);
  return library;
}

void printLibrary(struct song_node* library[27]){
  int i;
  for(i=0;i<27;i++){
    print_list(library[i]);
  }
}
