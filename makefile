CC = gcc
CFLAGS = -O2 -Wall
SRCS = .\src\main.c
HEADER = .\include
TARGET = Limfico

Limfico: 
	$(CC) -o $(TARGET) $(SRCS) -I $(HEADER) $(CFLAGS)

clean:
	rm $(TARGET).exe
