#include <iostream>
#include "ChessPieces.h"
#include "King.h"

using namespace std;

/******************************************** King ********************************************/

/* Constructor */
King::King(color color) : ChessPiece(KING, color) {
  pieceIcon = ((color == White) ? "♔" : "♚");
  pieceHasMoved = false;
}

/* Destructor */
King::~King() {}

/* Checks the validity of a particular move for the piece "King" */
bool King::validMovePiece(const int &source_file, const int &source_rank,
			  const int &destination_file, const int &destination_rank,
			  bool captures_piece) {
  
  int rank_move = destination_rank - source_rank;
  int file_move = destination_file - source_file;

  //King moves one square straight
  if ((abs(rank_move) == 1 && file_move == 0) || (rank_move == 0 && abs(file_move) == 1))
    return true;

  //King moves one square diagonally
  if (abs(rank_move) == 1 && abs(file_move) == 1)
    return true;

  return false;
}
