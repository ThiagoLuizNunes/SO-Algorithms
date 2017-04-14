#ifndef FILA_H
#define FILA_H

#include <cstdlib>
#include <iostream>
using namespace std;

struct Node {
  int startTime;
  int processTime;
  struct Node *next;
};
typedef struct Node node;

struct Fila {
  node *begin;
  node *end;
  int sizeFila;
};
typedef struct Fila fila;

void createFile(Fila *f){
  f->begin = NULL;
  f->end = NULL;
  f->sizeFila = 0;
}

int empty(Fila *f){
  if(f->sizeFila == 0){
    return 1;
  }
  else{
    return 0;
  }
}

int insertFila(Fila *f, int start, int process){
  Node *newNode = (node*) malloc(sizeof(node));
  if(newNode == NULL){
    return 0;
  }
  newNode->startTime = start;
  newNode->processTime = process;
  if(empty(f)){
    f->begin = newNode;
    f->end = newNode;
  }
  else{
    (f->end)->next = newNode;
    f->end = newNode;
  }
  f->sizeFila++;

  return 1;
}

int removeFile(Fila *f){
  Node *aux;
  if(f->begin == f->end){
    f->end = NULL;
  }
  aux = f->begin;
  f->begin = aux->next;
  f->sizeFila--;
  free(aux);
  return 1;
}

void printFila(Fila *f){
  Node *aux = f->begin;

  while (aux != NULL) {
    cout << aux->startTime << " " << aux->processTime << endl;
    aux = aux->next;
  }
}

#endif
