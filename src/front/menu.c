#include "menu.h"

void printmenu(const char* title, const char* options[], size_t size) {
  system(CLEAR_SCREEN);

  printf("\n=====================================\n");
  printf(" %s\n", title);
  printf("=====================================\n");

  for (size_t i = 0; i < size; i++) 
    printf(" %ld - %s\n", i + 1, options[i]);
  
  printf("=====================================\n");
  printf(" Option: ");
}

void print_animal(Animal* animal) {
  printf("\n|=====================================|\n");
  printf("|ID      ------------ %-16d|\n", animal->id);
  printf("|NAME    ------------ %-16s|\n", animal->name);
  printf("|SPECIES ------------ %-16s|\n", animal->species);
  printf("|AGE     ------------ %-16d|\n", animal->age);
  printf("|=====================================|\n");
}

void print_update_field_opts() {
  printf("1 - NAME\n");
  printf("2 - SPECIES\n");
  printf("3 - AGE\n");
}

void print_centered(const char* str, int width) {
  int size = strlen(str);
  int start = (width - size) / 2;
  printf("%*s%s", start, "", str);
}

void print_animals(Animal* list, int size) {
  print_centered("REGISTERED ANIMALS", 39);
  for(int i = 0; i < size; i++) 
    print_animal(&list[i]);
}