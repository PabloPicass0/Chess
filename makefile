chess: ChessMain.o ChessBoard.o ChessPieces.o
	g++ ChessMain.o ChessBoard.o ChessPieces.o -o chess

ChessMain.o: ChessMain.cpp ChessBoard.h
	g++ -c -g -Wall ChessMain.cpp

ChessBoard.o: ChessBoard.cpp color.h ChessBoard.h ChessPieces.h
	g++ -c -g -Wall ChessBoard.cpp

ChessPieces.o: ChessPieces.cpp color.h ChessPieces.h ChessBoard.h
	g++ -c -g -Wall ChessPieces.cpp

clean:
	rm -f *.o chess
