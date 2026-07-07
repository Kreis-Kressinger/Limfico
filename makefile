CC = gcc
CFLAGS = -O2 -Wall
SRCS = ./src/main.c ./src/encrypt.c
HEADERS = ./include
TARGET = Limfico

all: $(TARGET)

$(TARGET): $(SRCS) $(HEADERS)
	$(CC) -o $(TARGET) $(CFLAGS) $(SRCS) -I $(HEADERS) 

clean:
	rm -f $(TARGET).exe $(TARGET)
