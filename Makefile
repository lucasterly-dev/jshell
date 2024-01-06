# Makefile
CC = gcc
CFLAGS = -Wall -Wextra

all: jshell

jshell: main.o libx/call.o libx/ll.o libx/jd.o
	$(CC) $(CFLAGS) -o jshell main.o libx/call.o libx/ll.o libx/jd.o

main.o: main.c libx/ll.h libx/jd.h libx/call.h
	$(CC) $(CFLAGS) -c main.c -o main.o

libx/call.o: libx/call.c libx/call.h
	$(CC) $(CFLAGS) -c libx/call.c -o libx/call.o

libx/ll.o: libx/ll.c libx/ll.h
	$(CC) $(CFLAGS) -c libx/ll.c -o libx/ll.o

libx/jd.o: libx/jd.c libx/jd.h
	$(CC) $(CFLAGS) -c libx/jd.c -o libx/jd.o

clean:
	rm -f jshell main.o libx/call.o libx/ll.o libx/jd.o
