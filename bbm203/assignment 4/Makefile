output: Huffman.o IO.o Main.o Node2Freq.o
	g++ -std=c++11 Huffman.o IO.o Main.o Node2Freq.o -o output

Huffman.o: Huffman.cpp
	g++ -std=c++11 -c Huffman.cpp

IO.o: IO.cpp
	g++ -std=c++11 -c IO.cpp

Main.o: Main.cpp 
	g++ -std=c++11 -c Main.cpp

Node2Freq.o: Node2Freq.cpp
	g++ -std=c++11 -c Node2Freq.cpp

clean:
	rm *.o output