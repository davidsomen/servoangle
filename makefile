# Compiler 
CC=gcc

# Compiler options
CFLAGS=-c

all: sweepd servoangle

sweepd: servoanglelib.o sweepd.o
	$(CC) sweepd.o servoanglelib.o -o sweepd

servoangle: servoanglelib.o servoangle.o
	$(CC) servoangle.o servoanglelib.o -o servoangle

servoanglelib.o:
	$(CC) $(CFLAGS) servoanglelib.c -o servoanglelib.o

sweepd.o:
	$(CC) $(CFLAGS) -std:gnu99  sweepd.c -o sweepd.o

servoangle.o:
	$(CC) $(CFLAGS) servoangle.c -o servoangle.o
