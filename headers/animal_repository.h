#ifndef __ANIMAL_REPO__
#define __ANIMAL_REPO__

#define NAME 1
#define SPECIES 2
#define AGE 3

#include <stdio.h>
#include <stdbool.h>
#include <input.h>
#include <unistd.h>

#include "animal.h"
#include "persistence.h"
#include "menu.h"

void animal_input(char* name, size_t namesize, char* species, size_t spsize, int* age); 
bool save_animal(Animal* animal);
bool update_animal_field(Animal* animal, char* str_field, int field);
bool find_animals();

#endif