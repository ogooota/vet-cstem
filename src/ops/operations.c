#include "operations.h"

void anmlinfoinput(char* name, size_t namesize, 
                   char* species, size_t speciessize,
                   int* age) {
  system(CLEAR_SCREEN);
  
  printf("Name: ");
  readstr(name, namesize);

  printf("\nSpecies: ");
  readstr(species, speciessize);

  printf("\nAge: ");
  *age = readint();
}

bool show_animals() {
  system(CLEAR_SCREEN);
  if(!find_animals())
    return false;
  return true;
}

bool update_animal() {
  int amt;
  Animal* list = find_all_animals(&amt);

  system(CLEAR_SCREEN);
  print_animals(list, amt);
  printf("ID for update: ");
  int id = readint();

  Animal* toupdate = find_animal_by_id(id);
  if(!toupdate)
    return false;
  
  system(CLEAR_SCREEN);
  print_animal(toupdate);
  printf("Is this the animal you want to update? [y/n] ");
  char yn = readyn();
  if(yn != 'y' && yn != 'Y')
    return false;

  print_update_field_opts();
  printf("Which field do you want to update? ");
  int field = readint();
  
  printf("New field: ");
  char str_field[50];
  readstr(str_field, sizeof(str_field));

  update_animal_field(toupdate, str_field, field);

  return true;
}

bool register_animal() {
  char name[50];
  char species[30];
  int age;

  anmlinfoinput(name, sizeof(name), 
                species, sizeof(species), 
                &age  );
  Animal* anml = createanimal(name, species, age);

  printf("Do you want to save the animal %s? [y/n] ", name);

  char choice = readyn();

  if(choice == 'n')
    return false;
  
  if(!save_animal(anml)) {
    printf("An error ocurred. %s not saved", name);
    return false;
  }
  return true;
}
