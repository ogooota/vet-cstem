#ifndef _PERSISTENCE_H_
#define _PERSISTENCE_H_

#define INSERT_ANIMAL "INSERT INTO animals(name, species, age) values ('%s', '%s', %d)"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

#include "animal.h"

typedef enum {
  OK = 0,
  ERR_MYSQL_INIT,
  ERR_CONN,
  ERR_INSERT,
  ERR_SELECT,
  ERR_QUERY,
  ERR_AN_NOT_FOUND,
  ERR_AN_UPDATE,
  BAD_REQUEST
} ErrCode;

int db_connect();
void db_disconnect();

int db_insert_animal(const Animal* animal);
int db_update_animal(int toupdate_id, AnimalDto* info);

Animal* find_animal_by_id(int id);
Animal* find_all_animals(int* count);

#endif