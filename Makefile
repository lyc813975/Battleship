boardTest.out: test.o Board.o AnsiPrint.o Ship.o Point.o
	g++ -o boardTest.out Board.o AnsiPrint.o test.o Point.o Ship.o

test.o: test.cc Board.h Point.h Ship.h
	g++ -c test.cc

Ship.o: Ship.cc Ship.h Point.h
	g++ -c Ship.cc

Board.o: Board.cc Board.h AnsiPrint.h Ship.h Point.h
	g++ -c Board.cc

AnsiPrint.o: AnsiPrint.cc AnsiPrint.h
	g++ -c AnsiPrint.cc
Point.o: Point.cc Point.h
	g++ -c Point.cc

clean:
	rm -f *.o *.out

