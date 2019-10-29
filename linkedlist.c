#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct song_node{
  char name[100];
  char song[100];
  struct song_node* next;
};

struct song_node* insert_front(struct song_node* node, char artist[100], char music[100]){
  struct song_node* ptr = malloc(sizeof(struct song_node));
  ptr->name = artist;
  ptr->song = music;
  ptr->next = node;
  return ptr;
}

struct song_node* insert_alphabetical(struct song_node* front, char artist[100], char music[100]){
  struct song_node* searcher = front;
  while(strcmp(artist, searcher->name) > 0){
    searcher = searcher->next;
  }
  if (strcmp(artist, searcher->name) = 0){
    while(strcmp(music, searcher->song) > 0){
      searcher = searcher->next;
    }
    struct song_node* ptr = malloc(sizeof(struct song_node));
    ptr->name = artist;
    ptr->song = music;
    ptr->next = searcher;
    return front;
  }
  struct song_node* ptr = malloc(sizeof(struct song_node));
  ptr->name = artist;
  ptr->song = music;
  ptr->next = searcher;
  return front;
}

void print_list(struct song_node* front){
  printf("|");
  if (front == NULL) printf("  |");
  while(front->next != NULL){
    printf("%s: %s|", front->name, front->song);
  }
  printf("\n");
}
