CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=main.cpp vector_points.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=RT

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@


