#ifndef _OPERATIONS_H_
#define _OPERATIONS_H_

#include <stdio.h>
#include <stdbool.h>
#include <input.h>

#include "animal.h"
#include "animal_repository.h"
#include "menu.h"

void anmlinfoinput(char* name, size_t namesize, char* species, size_t speciessize, int* age);
bool register_animal();
bool update_animal();
bool show_animals();

#endif