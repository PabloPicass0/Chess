chess: ChessMain.o ChessBoard.o ChessPieces.o King.o Castle.o Bishop.o Queen.o Knight.o Pawn.o
	g++ ChessMain.o ChessBoard.o ChessPieces.o King.o Castle.o Bishop.o Queen.o Knight.o Pawn.o -o chess

ChessMain.o: ChessMain.cpp ChessBoard.h
	g++ -c -g -Wall ChessMain.cpp

ChessBoard.o: ChessBoard.cpp ChessBoard.h ChessPieces.h King.h Castle.h Bishop.h Queen.h Knight.h Pawn.h
	g++ -c -g -Wall ChessBoard.cpp

ChessPieces.o: ChessPieces.cpp color.h pieceType.h 
	g++ -c -g -Wall ChessPieces.cpp

King.o: King.cpp King.h ChessPieces.h
	g++ -c -g -Wall King.cpp

Castle.o: Castle.cpp Castle.h ChessPieces.h
	g++ -c -g -Wall Castle.cpp

Bishop.o: Bishop.cpp Bishop.h ChessPieces.h
	g++ -c -g -Wall Bishop.cpp

Queen.o: Queen.cpp Queen.h ChessPieces.h
	g++ -c -g -Wall Queen.cpp

Knight.o: Knight.cpp Knight.h ChessPieces.h
	g++ -c -g -Wall Knight.cpp

Pawn.o: Pawn.cpp Pawn.h ChessPieces.h
	g++ -c -g -Wall Pawn.cpp

clean:
	rm -f *.o chess
