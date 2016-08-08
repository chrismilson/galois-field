CC=g++
SOURCE=Galois.cpp
OBJECT=object/Galois.o

all: objects

objects: $(SOURCE)
	mkdir -p object
	$(CC) $^ -c -o $(OBJECT)

test: objects
	$(CC) $(OBJECT) test.cpp -o test
	./test
	rm -f test
