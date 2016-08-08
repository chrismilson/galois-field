CC=g++
SOURCE=Galois.cpp
OBJECT=object/Galois.o

all: objects

objects: $(SOURCE)
	mkdir -p object
	$(CC) $^ -c -o $(OBJECT)

clean:
	rm -rf ./object/

test:
	$(CC) $(SOURCE) test.cpp -o test
	./test
	rm -f test
	rm -f object/test.o
