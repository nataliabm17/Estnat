OBJS = principal2.cpp base.o pila.o cola.o cola2.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG) --pedantic
LFLAGS = -Wall $(DEBUG) --pedantic
TARGET = principal2

$(TARGET) : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(TARGET)
	
pila.o : base.h pila.h pila.cpp
	$(CC) $(CFLAGS) pila.cpp

cola.o : base.h cola.h cola.cpp
	$(CC) $(CFLAGS) cola.cpp

cola2.o : base.h cola2.h cola2.cpp
	$(CC) $(CFLAGS) cola2.cpp	

base.o : base.h base.cpp
	$(CC) $(CFLAGS) base.cpp
	
clean:
	\rm *.o $(TARGET)