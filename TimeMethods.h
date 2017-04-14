#ifndef METHODS_H
#define METHODS_H

#include <cstdlib>
#include <iostream>
#include "Fila.h"
using namespace std;

float backTime(Fila *f){
  float auxTime;
  Node *aux = f->begin;

  while(aux != NULL){
    auxTime += aux->processTime;
    aux = aux->next;
  }
  return auxTime/f->sizeFila;
}

float waitTime(Fila *f){
  float auxTime = 0;
  Node *aux = f->begin;

  while(aux != NULL){
    auxTime -= aux->startTime;
    auxTime += aux->processTime;
    aux = aux->next;
  }
  return auxTime/f->sizeFila;
}

#endif
