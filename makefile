CC=gcc
CFLAGS=-fopenmp -o
p1=p1

.PHONY: p1

p1:
	$(CC) $(CFLAGS) $(p1) $(p1).c

