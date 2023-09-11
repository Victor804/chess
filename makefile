piece.o : piece.cpp piece.hpp
	g++ -c piece.cpp

board.o : board.cpp board.hpp
	g++ -c board.cpp

player.o : player.cpp player.hpp
	g++ -c player.cpp


main.o : main.cpp piece.hpp board.hpp player.hpp
	g++ -c main.cpp

main : main.o piece.o board.o player.o
	g++ main.o piece.o board.o player.o -o main