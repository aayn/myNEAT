CC=g++
CFLAGS=-c -Wall -Werror -g
LDFLAGS=
SOURCES=gene.cpp helper.cpp xor_ann.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=xor

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJECTS) $(EXECUTABLE)
