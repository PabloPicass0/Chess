# Directories
HEADER_DIR = Header_Files
IMPL_DIR = Implementation_Files

# Compiler and Flags
CXX = g++
CXXFLAGS = -g -Wall -I$(HEADER_DIR)

chess: ChessMain.o ChessBoard.o ChessPieces.o King.o Castle.o Bishop.o Queen.o Knight.o Pawn.o
	$(CXX) ChessMain.o ChessBoard.o ChessPieces.o King.o Castle.o Bishop.o Queen.o Knight.o Pawn.o -o chess

ChessMain.o: $(IMPL_DIR)/ChessMain.cpp $(HEADER_DIR)/ChessBoard.h
	$(CXX) $(CXXFLAGS) -c $(IMPL_DIR)/ChessMain.cpp

ChessBoard.o: $(IMPL_DIR)/ChessBoard.cpp $(HEADER_DIR)/ChessBoard.h $(HEADER_DIR)/ChessPieces.h $(HEADER_DIR)/King.h $(HEADER_DIR)/Castle.h $(HEADER_DIR)/Bishop.h $(HEADER_DIR)/Queen.h $(HEADER_DIR)/Knight.h $(HEADER_DIR)/Pawn.h
	$(CXX) $(CXXFLAGS) -c $(IMPL_DIR)/ChessBoard.cpp

ChessPieces.o: $(IMPL_DIR)/ChessPieces.cpp $(HEADER_DIR)/color.h $(HEADER_DIR)/pieceType.h 
	$(CXX) $(CXXFLAGS) -c $(IMPL_DIR)/ChessPieces.cpp

King.o: $(IMPL_DIR)/King.cpp $(HEADER_DIR)/King.h $(HEADER_DIR)/ChessPieces.h
	$(CXX) $(CXXFLAGS) -c $(IMPL_DIR)/King.cpp

Castle.o: $(IMPL_DIR)/Castle.cpp $(HEADER_DIR)/Castle.h $(HEADER_DIR)/ChessPieces.h
	$(CXX) $(CXXFLAGS) -c $(IMPL_DIR)/Castle.cpp

Bishop.o: $(IMPL_DIR)/Bishop.cpp $(HEADER_DIR)/Bishop.h $(HEADER_DIR)/ChessPieces.h
	$(CXX) $(CXXFLAGS) -c $(IMPL_DIR)/Bishop.cpp

Queen.o: $(IMPL_DIR)/Queen.cpp $(HEADER_DIR)/Queen.h $(HEADER_DIR)/ChessPieces.h
	$(CXX) $(CXXFLAGS) -c $(IMPL_DIR)/Queen.cpp

Knight.o: $(IMPL_DIR)/Knight.cpp $(HEADER_DIR)/Knight.h $(HEADER_DIR)/ChessPieces.h
	$(CXX) $(CXXFLAGS) -c $(IMPL_DIR)/Knight.cpp

Pawn.o: $(IMPL_DIR)/Pawn.cpp $(HEADER_DIR)/Pawn.h $(HEADER_DIR)/ChessPieces.h
	$(CXX) $(CXXFLAGS) -c $(IMPL_DIR)/Pawn.cpp

clean:
	rm -f *.o chess