CC = gcc
CFLAGS = -Wall -Wextra -std=gnu11

TARGET = timer
SRC = timer.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

run: $(TARGET)
	./$(TARGET) 5 # Example: run the timer for 5 seconds

clean:
	rm -f $(TARGET)