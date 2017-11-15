OBJS = main.cpp
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG) -pedantic
LFLAGS = -Wall $(DEBUG) -pedantic
TARGET = principal
$(TARGET) : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS)	-o $(TARGET)

clean:
	\rm -f *.o $(TARGET)
