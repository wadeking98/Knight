CC=gcc
CFLAGS=-I.
DEPS= point.h stack.h main.h
OBJ= main.o point.o stack.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

knight: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

