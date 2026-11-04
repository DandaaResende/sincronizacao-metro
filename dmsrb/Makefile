CC = gcc
CFLAGS = -Wall -Wextra -pthread -g

TARGET = sync_car
SOURCES = sync_car.c test_sync_car.c

all: $(TARGET)

$(TARGET): $(SOURCES) sync_car.h
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

clean:
	rm -f $(TARGET) *.o