CC=g++
CFLAGS=-c -Wall -Werror -g
LDFLAGS=
SOURCES=gene.cpp helper.cpp innovation.cpp genome.cpp genome_test.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=geno_test

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJECTS) $(EXECUTABLE)
