CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=./src/main.cpp \
		./src/point3f.cpp \
		./src/vec3f.cpp \
		./src/ray.cpp \
		./src/camera.cpp \
		./src/color.cpp \
		./src/object.cpp \
		./src/scene.cpp \
		./src/light.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=RT

all: $(SOURCES) $(EXECUTABLE)

clean:
	rm -Rf ./obj/*.o
	rm $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(subst src/,obj/,$(OBJECTS)) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $(subst src/,obj/,$@)
	