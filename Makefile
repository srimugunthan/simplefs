CC=gcc
#CFLAGS=-I.
DEPS = common.h
OBJ = file.o fs.o dir.o inode.o main.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

simfs: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)

