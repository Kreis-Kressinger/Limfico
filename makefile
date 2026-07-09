CC = gcc
CFLAGS = -O2 -Wall -std=c99
1SRCS = ./src/Limfico.c ./src/encrypt.c
HEADERS = ./include
1TARGET = Limfico
2TARGET = Limkey
2SRCS = ./src/Limkey.c

all: $(1TARGET) $(2TARGET)

$(1TARGET): $(1SRCS) $(1HEADERS)
	$(CC) -o $(1TARGET) $(CFLAGS) $(1SRCS) -I $(HEADERS) 

$(2TARGET):  $(2SRCS) $(2HEADERS)
	$(CC) -o $(2TARGET) $(CFLAGS) $(2SRCS) -I $(HEADERS) 

clean:
	rm -f $(1TARGET).exe $(1TARGET)
	rm -f $(2TARGET).exe $(2TARGET)
