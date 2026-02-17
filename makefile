CC = gcc
OBJS = main.c src/models/animal.c src/ops/operations.c src/utils.c src/repositories/animal_repository.c src/front/menu.c src/persistence/persistence.c
FLAGS = -Iheaders -Wall -Wextra
TARGET = main -linput -lmysqlclient

all:
	$(CC) $(FLAGS) $(OBJS) -o $(TARGET)

run:
	./$(TARGET)