bstree: binarySearchTree.o test.o
	g++ -o bstree binarySearchTree.o test.o
binarySearchTree.o: binarySearchTree.cpp binarySearchTree.h
	g++ -g -c binarySearchTree.cpp
test.o: test.cpp binarySearchTree.h
	g++ -g -c test.cpp
clean: 
	rm bstree *.o 
