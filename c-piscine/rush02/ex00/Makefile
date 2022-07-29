CC=gcc
CFLAGS= -wExtra -Werror -Wall
LDFLAGS=
EXEC=a.out

all: $(EXEC)

make: *.c
	$(CC) -o $@ $^ $(LDFLAGS)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(EXEC)

