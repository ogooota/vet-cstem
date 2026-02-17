#include "animal_repository.h"

bool find_animals() {
  int amt;
  Animal* list = find_all_animals(&amt);
  if(!list)
    return false;

  print_animals(list, amt);
  free(list);
  return true;
}

bool save_animal(Animal* animal) {
  if(db_insert_animal(animal)) {
    sleep(3);
    return false;
  }

  return true;
}

bool update_animal_field(Animal* animal, char* str_field, int field) {
  if(!animal)
    return false;

  AnimalDto* dto = createanimaldto(animal);
  if(!dto)
    return false;

  switch(field) {
    case NAME:
      strcpy(dto->name, str_field);
      break;
    case SPECIES:
      strcpy(dto->species, str_field);
      break;
    case AGE:
      dto->age = atoi(str_field);
      break;
  }
  
  if(db_update_animal(animal->id, dto))
    return false;
  return true;
}