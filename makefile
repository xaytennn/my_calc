CC = gcc
CFLAGS = -Wall
TARGET = calc
LIBS = -lm
OBJS = calc.o calc_defs.o

all: $(TARGET) main math_generator

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LIBS)

calc.o: calc.c calc_defs.h
	$(CC) $(CFLAGS) -c calc.c -o calc.o
	
main.o: calc_defs.h main.c
	$(CC) $(CFLAGS) -c main.c -o main.o

main: main.o
	$(CC) $(CFLAGS) -o main main.o

math_generator.o: calc_defs.h math_generator.c
	$(CC) $(CFLAGS) -c math_generator.c -o math_generator.o

math_generator: math_generator.o
	$(CC) $(CFLAGS) -o math_generator math_generator.o calc_defs.o $(LIBS)

calc_defs.o: calc_defs.c calc_defs.h
	$(CC) $(CFLAGS) -c calc_defs.c -o calc_defs.o	

clean:
	rm -f $(TARGET) main math_generator *.o

.PHONY: all clean 
