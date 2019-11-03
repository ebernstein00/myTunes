#include "listfunctions.h"
#include "tunes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
struct song_node{
  char name[100];
  char song[100];
  struct song_node* next;
};

int main(){
  srand(time(NULL));
  //struct song_node *tail;
  //struct song_node *head=tail;
  struct song_node* front=NULL;
  front = insert_front(front, "pink floyd","the wall");
  //print_list(front);
  front = insert_front(front, "pink floyd","time");
  front = insert_front(front, "jimi hendricks","purple haze");
  front = insert_alphabetical(front, "katy perry","whatever");
  front = insert_alphabetical(front, "adele","hello");
  print_list(front);
  struct song_node* myRandSong = random_song(front);
  printf("Your random song is %s by %s \n",myRandSong->song,myRandSong->name);


  print_list(search_artist(front,"pink floyd"));
  front = remove_node(front,"adele","hello");
  print_list(front);
  front = remove_node(front,"pink floyd","time");
  print_list(front);
  front = clear_library(front);
  print_list(front);
  printf("\n\nFinished Linked List Testing, proceeding to test tunes.c \n\n");

  struct song_node *library[27];
  int i;
  for(i=0;i<27;i++){
    library[i]=NULL;
  }
  add_song(library,"pink floyd","the wall");
  print_list(library[9]);
  print_list(library[16]);
  char p = 'p';
  printf("made it here \n");
  print_letter(library,p);
  printf("made it here as well\n");
  printLibrary(library);
  return 0;
}
