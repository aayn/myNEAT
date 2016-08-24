CC=g++ -std=c++11
CFLAGS=-c -Wall -Werror -g
LDFLAGS=
SOURCES=gene.cpp helper.cpp innovation.cpp genome.cpp organism.cpp crossover_test.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=crossover_test

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJECTS) $(EXECUTABLE)
