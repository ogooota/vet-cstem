#ifndef _ANIMAL_H_
#define _ANIMAL_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
  int id;
  char name[50];
  char species[30];
  int age;
} Animal;

typedef struct {
  char name[50];
  char species[30];
  int age;
} AnimalDto;

Animal* createanimal(const char* name, const char* species, int age);
AnimalDto* createanimaldto(Animal* animal);

bool updateanimal(Animal* _Destination, AnimalDto* _Source);
bool updateanimaldto(AnimalDto* _Destination, Animal* _Source);

#endif