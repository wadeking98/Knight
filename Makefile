CC=gcc
CFLAGS=-I.
DEPS= libs/header/point.h libs/header/stack.h libs/header/main.h
OBJ= libs/src/main.o libs/src/point.o libs/src/stack.o

%.o: libs/src/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

knight: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	make clean

clean:
	rm -f $(OBJ)
