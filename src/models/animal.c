#include "animal.h"

Animal* createanimal(const char* name, const char* species, int age) {
  static int nextid = 1;

  if(!name || !species || age < 0)
    return NULL;
    
  Animal* animal = malloc(sizeof(Animal));
  if(!animal)
    return NULL;
  
  animal->id = nextid++;
  strcpy(animal->name, name);
  strcpy(animal->species, species);
  animal->age = age;

  return animal;
}

AnimalDto* createanimaldto(Animal* animal) {
  if(!animal)
    return NULL;
  
  AnimalDto* animaldto = malloc(sizeof(AnimalDto));
  if(!animaldto)
    return NULL;
  
  updateanimaldto(animaldto, animal);

  return animaldto;
}

bool updateanimal(Animal* _Destination, AnimalDto* _Source) {
  if(!_Destination || !_Source)
    return false;

  strcpy(_Destination->name, _Source->name);
  strcpy(_Destination->species, _Source->species);
  _Destination->age = _Source->age;

  return true;
}

bool updateanimaldto(AnimalDto* _Destination, Animal* _Source) {
  if(!_Destination || !_Source)
    return false;

  strcpy(_Destination->name, _Source->name);
  strcpy(_Destination->species, _Source->species);
  _Destination->age = _Source->age;
  
  return true;
}