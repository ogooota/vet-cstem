#ifndef __ANIMAL_JSON_H__
#define __ANIMAL_JSON_H__

#include <stdio.h>
#include <cjson/cJSON.h>

#include "animal.h"

cJSON* tojson(Animal* animal);
Animal toanimal(cJSON* jsonanimal);

#endif
