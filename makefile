CC = gcc
CFLAGS = -O2 -Wall -std=c99

LIMFICO_SRCS = ./src/Limfico.c ./src/encrypt.c
LIMKEY_SRCS = ./src/Limkey.c
HEADERS = ./include/Limfico

LIMFICO_TARGET = Limfico
LIMKEY_TARGET = Limkey

# Add Windows-specific libraries
ifeq ($(OS),Windows_NT)
    LDLIBS = -lbcrypt
else
    LDLIBS =
endif

all: $(LIMFICO_TARGET) $(LIMKEY_TARGET)

$(LIMFICO_TARGET): $(LIMFICO_SRCS)
	$(CC) -o $@ $(CFLAGS) $(LIMFICO_SRCS) -I $(HEADERS)

$(LIMKEY_TARGET): $(LIMKEY_SRCS)
	$(CC) -o $@ $(CFLAGS) $(LIMKEY_SRCS) -I $(HEADERS) $(LDLIBS)

clean:
	rm -f $(LIMFICO_TARGET).exe $(LIMFICO_TARGET)
	rm -f $(LIMKEY_TARGET).exe $(LIMKEY_TARGET)
