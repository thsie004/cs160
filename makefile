CC=gcc
CFLAGS=-fopenmp -std=c99 -o
p1=p1
p2=p2
p3=p3

.PHONY: p1, p2, p3

p1:
	$(CC) $(CFLAGS) $(p1) $(p1).c

p2:
	$(CC) $(CFLAGS) $(p2) $(p2).c

p3:
	$(CC) $(CFLAGS) $(p3) $(p3).c

