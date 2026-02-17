#include "persistence.h"

static MYSQL* conn = NULL;

int db_connect() {
  conn = mysql_init(NULL);
  if(!conn) {
    fprintf(stderr, "mysql_init() failed\n");
    return ERR_MYSQL_INIT;
  }

  if(!mysql_real_connect(conn, "localhost", "root", "capp", 
                         "vetdb", 0, NULL, 0)) 
  {
    fprintf(stderr, "mysql_real_connect() failed: %s\n", mysql_error(conn));
    return ERR_CONN;
  }
  return OK;
}

void db_disconnect() {
  if(conn) {
    mysql_close(conn);
    conn = NULL;
  }
}

int db_insert_animal(const Animal* animal) {
  
  char query[BUFSIZ];

  snprintf(query, BUFSIZ, INSERT_ANIMAL,
    animal->name,
    animal->species,
    animal->age
  );

  if(mysql_query(conn, query)) {
    fprintf(stderr, "INSERT failed: %s\n", mysql_error(conn));
    return ERR_INSERT;
  }
  return OK;
}

Animal* find_animal_by_id(int id) {
  if(id < 0)
    return NULL;
  
  char query[BUFSIZ];
  snprintf(query, sizeof(query), "SELECT * FROM animals WHERE id = %d", id);

  if(mysql_query(conn, query)) {
    fprintf(stderr, "INSERT failed: %s\n", mysql_error(conn));
    return NULL;
  }

  MYSQL_RES* result = mysql_store_result(conn);
  if(!result) {
    fprintf(stderr, "mysql_store_result() failed: %s\n", mysql_error(conn));
    return NULL;
  }
  
  MYSQL_ROW row = mysql_fetch_row(result);
  if(!row) {
    mysql_free_result(result);
    return NULL;
  }

  Animal* animal = malloc(sizeof(Animal));
  if(!animal) {
    mysql_free_result(result);
    return NULL;
  }

  animal->id = atoi(row[0]);
  
  strncpy(animal->name, row[1], sizeof(animal->name) - 1);
  animal->name[sizeof(animal->name) - 1] = '\0';
  
  strncpy(animal->species, row[2], sizeof(animal->species) - 1);
  animal->species[sizeof(animal->species) - 1] = '\0';

  animal->age = atoi(row[3]);

  mysql_free_result(result);

  return animal;
}

Animal* find_all_animals(int* count) {
  char query[BUFSIZ];
  snprintf(query, sizeof(query), "SELECT * FROM animals");

  if(mysql_query(conn, query)) {
    fprintf(stderr, "SELECT failed: %s\n", mysql_error(conn));
    return NULL;
  }

  MYSQL_RES* result = mysql_store_result(conn);
  if(!result) {
    fprintf(stderr, "mysql_store_result() failed: %s\n", mysql_error(conn));
    return NULL;
  }

  int rows = mysql_num_rows(result);
  if(rows == 0) {
    mysql_free_result(result);
    return NULL;
  }

  Animal* animals = malloc(sizeof(Animal) * rows);
  if(!animals) {
    mysql_free_result(result);
    return NULL;
  }

  MYSQL_ROW row;
  int i = 0;  
  while((row = mysql_fetch_row(result))) {
    animals[i].id = atoi(row[0]);
    
    strncpy(animals[i].name, row[1], sizeof(animals[i].name) - 1);
    animals[i].name[sizeof(animals[i].name) - 1] = '\0';

    strncpy(animals[i].species, row[2], sizeof(animals[i].species) - 1);
    animals[i].species[sizeof(animals[i].species) - 1] = '\0';

    animals[i].age = atoi(row[3]);

    i++;
  }

  *count = rows;

  mysql_free_result(result);

  return animals;
}

int db_update_animal(int toupdate_id, AnimalDto* info) {
  if(info == NULL || toupdate_id < 0)
    return BAD_REQUEST;

  char query[BUFSIZ];

  snprintf(query, BUFSIZ, "UPDATE animals SET name='%s', species='%s', age=%d WHERE id=%d",
           info->name,
           info->species,
           info->age,
           toupdate_id
  );
  
  if(mysql_query(conn, query)) {
    fprintf(stderr, "UPDATE failed: %s\n", mysql_error(conn));
    return ERR_AN_UPDATE;
  }

  if(mysql_affected_rows(conn) == 0)
    return ERR_AN_NOT_FOUND;
  return OK;
}