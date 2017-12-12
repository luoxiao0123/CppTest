word: main.o words.o
	g++ -Wall -g main.o words.o -o word

main.o: main.cpp words.h
	g++ -Wall -g -c main.cpp

words.h: words.cpp words.h
	g++ -Wall -g -c words.cpp

clean:
	rm -f *.o word
