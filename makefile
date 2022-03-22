caso2: main quicksort insertsort freetext fileReader
	g++ -o caso2 main.o quicksort.o insertsort.o freetext.o fileReader.o

main:
	g++ -c main.cpp

quicksort:
	g++ -c quicksort.cpp

insertsort:
	g++ -c insertsort.cpp

freetext:
	g++ -c freetext.cpp

fileReader:
	g++ -c fileReader.cpp
