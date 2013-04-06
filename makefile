# Compiler 
CC=gcc

# Compiler options
CFLAGS=-c

all: servoangle

servoangle: servoanglelib.o servoangle.o
	$(CC) servoangle.o servoanglelib.o -o servoangle

servoanglelib.o:
	$(CC) $(CFLAGS) servoanglelib.c -o servoanglelib.o

servoangle.o:
	$(CC) $(CFLAGS) servoangle.c -o servoangle.o