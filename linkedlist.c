#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct song_node{
  char name[100];
  char song[100];
  struct song_node* next;
};


struct song_node* insert_front(struct song_node* node, char artist[100], char music[100]){
  struct song_node* ptr = malloc(sizeof(struct song_node));
  strcpy(ptr->name,artist);
  strcpy(ptr->song,music);
  ptr->next=node;
  return ptr;
}

struct song_node* insert_alphabetical(struct song_node* front, char artist[100], char music[100]){
  if (!front){
    return insert_front(front, artist, music);
  }
  if(strcmp(artist, front->name) < 0){
    return insert_front(front, artist, music);
  }
  struct song_node* searcher = front;
  //printf("We want this artist %s with this music %s",artist,music);
  while(searcher->next && strcmp(artist, searcher->next->name) > 0){
    searcher = searcher->next;
  }
  if (strcmp(artist, searcher->name) == 0){
    while(searcher->next && strcmp(music, searcher->next->song) > 0){
      if (searcher->next == NULL) break;
      searcher = searcher->next;
    }
    struct song_node* ptr = malloc(sizeof(struct song_node));
    strcpy(ptr->name,artist);
    strcpy(ptr->song,music);
    ptr->next=searcher->next;
    searcher->next=ptr;
    return front;
  }
  struct song_node* ptr = malloc(sizeof(struct song_node));
  strcpy(ptr->name,artist);
  strcpy(ptr->song,music);
  ptr->next=searcher->next;
  searcher->next=ptr;
  return front;
}

void print_list(struct song_node* front){
  if(front){
    printf("%s: %s |",(*front).name,(*front).song);
    if((*front).next){
      print_list((*front).next);
    }
    else{
      printf("\n");
    }
  }
  else{
    printf("No songs yet\n");
  }
}

struct song_node* search(struct song_node* front, char artist[100], char music[100]){
  struct song_node* searcher = front;
  while (strcmp(searcher->name, artist) != 0 && strcmp(searcher->song, music) != 0){
    searcher = searcher->next;
  }
  return searcher;
}

struct song_node* search_artist(struct song_node* front, char artist[100]){
  struct song_node* searcher = front;
  while (strcmp(searcher->name, artist) != 0){
    searcher = searcher->next;
  }
  return searcher;
}

struct song_node* remove_node(struct song_node* front, char artist[100], char music[100]){
  if (strcmp(artist, front->name) == 0 && strcmp(music, front->song) == 0){
    struct song_node* ptr = front;
    front = front->next;
    free(ptr);
    return front;
  }
  struct song_node* leader = front->next;
  struct song_node* trailer = front;
  while (leader->next != NULL){
    if (strcmp(leader->name, artist) == 0 && strcmp(leader->song, music) == 0){
      trailer->next = leader->next;
      free(leader);
      return front;
    }
    trailer = leader;
    leader = leader->next;
  }
  return front;
}

struct song_node* clear_library(struct song_node* front){
  if (front == NULL) return front;
  struct song_node* ptr = front->next;
  while(ptr != NULL){
    ptr = front->next;
    free(front);
    front = ptr;
  }
  return ptr;
}

struct song_node* random_song(struct song_node* front){
  int length = 0;
  struct song_node* ph = front;
  while (ph != NULL){
    ph = ph->next;
    length++;
  }
  int index = rand() % length;
  int i;
  for(int i = 0; i < index; i++){
    front = front->next;
  }
  return front;
}
