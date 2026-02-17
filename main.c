#include "main.h"

const char* options[] = {
  "Add animal",
  "Update animal",
  "Show registered animals",
  "Exit"
};
size_t optsize = 4;

int main() {
  int opt;
  if(db_connect()) {
    sleep(3);
    return false;
  }
  while(true) {
    printmenu(WELCOME_MSG, options, optsize);
    opt = readint();
  
    switch(opt) {
      case 1:
        register_animal();
        break;
      case 2:
        update_animal();
        break;
      case 3:
        show_animals();
        getchar();
        break;
      case 4:
        printf("Bye bye! ;3\n");
        return 0;
    }
  }
  db_disconnect();
  return 0;
}