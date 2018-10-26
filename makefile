sudoku: main.o helper.o sudoku.o
	g++ main.o helper.o sudoku.o -o sudoku

main.o: main.cpp sudoku.h
	g++ -Wall -g -c main.cpp

helper.o: helper.cpp helper.h
	g++ -Wall -g -c helper.cpp 

sudoku.o: sudoku.cpp sudoku.h helper.h
	g++ -Wall -g -c sudoku.cpp 

clean:
	rm -f *.o sudoku

.PHONY: clean