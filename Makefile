CC = gcc

CFLAGS = \
	-std=c17 \
	-g \
	-Wall \
	-Wextra \
	-pedantic

PATHB = bin/
$(shell mkdir -p $(PATHB))

EXEC = \
	hello-world \
	isatty

$(EXEC): clean
	$(CC) $(CFLAGS) src/$@/main.c -o bin/$@

all: $(EXEC)

clean:
	rm -rf bin/*
