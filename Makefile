
CC = gcc
CFLAGS = -Wall -Wextra -std=c11

TARGET = address_book
SOURCES = main.c contact.c file.c validation.c
OBJECTS = $(SOURCES:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET) a.out

