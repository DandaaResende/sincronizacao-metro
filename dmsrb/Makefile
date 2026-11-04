CC = gcc
CFLAGS = -Wall -Wextra -pthread -g

TARGET = sync_car
SOURCE = sync_car.c

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) $(SOURCE) -o $(TARGET)

clean:
	rm -f $(TARGET) *.o