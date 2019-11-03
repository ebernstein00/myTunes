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
  //printf("made it \n");
  add_song(library,"pink floyd","time");
  //printf("made it \n");
  add_song(library,"pink floyd","money");
  //printf("made it \n");
  add_song(library,"paul mcartney","too many people");
  add_song(library,"paul simon","american tune");
  add_song(library,"adele","hello");
  add_song(library,"katy perry","whatever");
  add_song(library,"jimi hendricks","purple haze");
  add_song(library,"beyonce","crazy in love");
  printLibrary(library);
  print_letter(library,'p');
  print_letter(library,'a');
  print_letter(library,'b');
  print_letter(library,'c');
  printf("adding cher into the mix...\n");
  add_song(library,"cher","believe");
  print_letter(library,'c');
  printf("life was better w/o cher...\n");
  delete_song(library,"cher","believe");
  print_letter(library,'c');
  printf("Random playlist???\nFirst, just 2 songs\n");
  shuffle(library,2);
  printf("Second, a (hopefully) different 2 songs\n");
  shuffle(library,2);
  printf("Random playlist???. Third, 5 songs\n");
  shuffle(library,5);
  printLibrary(library);
  printf("I'm tired of this library, let's kill it\n");
  delete_library(library);
  printLibrary(library);
  return 0;
}
