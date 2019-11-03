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
char getLetter(int index){
  return index+96;
}

void add_song(struct song_node* library[27],char artist[100], char music[100]){
  char firstChar = artist[0];
  library[getIndex(firstChar)]=insert_alphabetical(library[getIndex(firstChar)],artist,music);
}

void printLibrary(struct song_node **library){
  int i;
  for(i=0;i<27;i++){
    printf("%c: ",getLetter(i));
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
  printf("%c: ", letter);
  print_list(library[index]);
}

void shuffle(struct song_node* library[27], int numSongs){
  int i;
  struct song_node *songs=NULL;
  for(i=0;i<27;i++){
    struct song_node* newSong = library[i];
    while(newSong){
      songs=insert_front(songs,newSong->name,newSong->song);
      newSong=newSong->next;
    }
  }
  i=0;
  for(i=0;i<numSongs;i++){
    struct song_node *myRandSong=random_song(songs);
    printf("%s by %s, ", myRandSong->song,myRandSong->name);
    songs = remove_node(songs,myRandSong->name,myRandSong->song);
    if(!songs && i<numSongs-1){
      printf("\n Sorry, those are all your songs, you didn't have enough to make a playlist that big\n");
      break;
    }
  }
  printf("\n");

}

void delete_library(struct song_node* library[27]){
  int i;
  for (i = 0; i < 27; i++){
    clear_library(library[i]);
  }
  printf("Music library cleared!");
}

void delete_song(struct song_node* library[27], char artist[100], char music[100]){
  char firstChar = artist[0];
  int index = getIndex(firstChar);
  remove_node(library[index], artist, music);
}
