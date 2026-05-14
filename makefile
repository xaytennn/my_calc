CC = gcc
CFLAGS = -Wall
TARGET = calc
OBJS = calc.o calc_defs.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

calc.o: calc.c calc_defs.h
	$(CC) $(CFLAGS) -c calc.c -o calc.o

calc_defs.o: calc_defs.c calc_defs.h
	$(CC) $(CFLAGS) -c calc_defs.c -o calc_defs.o	

clean:
	rm -f $(TARGET) *.o

.PHONY: all clean 
