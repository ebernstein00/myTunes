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

int main(){

  //struct song_node *tail;
  //struct song_node *head=tail;
  struct song_node* front=NULL;
  front = insert_front(front, "pink floyd","the wall");
  //print_list(front);
  front = insert_front(front, "pink floyd","time");
  front = insert_front(front, "jimi hendricks","purple haze");
  front = insert_alphabetical(front, "katy perry","whatever");
  print_list(front);
  return 0;
}
