#ifndef _MENU_H_
#define _MENU_H_

#define CLEAR_SCREEN "clear"
#define WELCOME_MSG "Welcome to the vet Cstem!"

#include <stdio.h>
#include <stdlib.h>

#include "utils.h"
#include "animal.h"

void print_centered(const char* str, int width);
void printmenu(const char* title, const char* options[], size_t size);
void print_animal(Animal* animal);
void print_animals(Animal* list, int size);
void print_update_field_opts();

#endif