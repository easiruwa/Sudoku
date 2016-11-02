sudoku: sudoku.o sudokuboard.o stack.o
	g++ -o sudoku sudoku.o sudokuboard.o stack.o

sudoku.o: sudoku.cc 
	g++ -c sudoku.cc

sudokuboard.o: sudokuboard.cc sudokuboard.h
	g++ -c sudokuboard.cc 

stack.o: stack.cc stack.h
	g++ -c stack.cc 

clean:
	rm -rf sudokuboard.o sudoku.o stack.o