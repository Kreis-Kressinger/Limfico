CC = gcc
SRCS = .\src\main.c
HEADER = .\include
TARGET = Limfico

Limfico: 
	$(CC) -o $(TARGET) $(SRCS) -I $(HEADER)

clean:
	rm $(TARGET).exe
