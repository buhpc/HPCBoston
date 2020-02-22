CC=g++
SOURCES= recipe.cpp
OBJECTS=$(SOURCES:.cpp=.o)
FLAGS=-lcnpy -lz --std=c++11
EXCUTABLE=recipe

all: 
	g++ recipe.cpp -o recipe -lcnpy -lz --std=c++11 
# 	$(CC) $(SOURCES) -o $(FLAGS) $(EXECUTABLE)

clean:
	-rm -f $(OBJECTS) $(EXECUTABLE)