CC = g++

CFLAGS = -Wall -g 

TARGET = mydb

all: $(TARGET)

$(TARGET): simpleParser.o saver.o BPlusTreewhy.o
	$(CC) $(CFLAGS) -o $(TARGET) simpleParser.o saver.o

simpleParser.o: ./Parser/simpleParser.cpp ./Save/saver.h ./Index/BPlusTreewhy.h
	$(CC) $(CFLAGS) -c ./Parser/simpleParser.cpp

saver.o: ./Save/saver.cpp ./Save/saver.h
	$(CC) $(CFLAGS) -c ./Save/saver.cpp

BPlusTreewhy.o: ./Index/BPlusTreewhy.cpp ./Index/BPlusTreewhy.h
	$(CC) $(CFLAGS) -c ./Index/BPlusTreewhy.cpp

clean:
	rm -f *.o $(TARGET)