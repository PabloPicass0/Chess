#include <iostream>
#include "ChessPieces.h"
#include "Queen.h"

using namespace std;

/******************************************** Queen ********************************************/

/* Constructor */
Queen::Queen(color color) : ChessPiece(QUEEN, color) {
  pieceIcon = ((color == White) ? "♕" : "♛");
  pieceHasMoved = false;
}

/* Destructor */
Queen::~Queen() {}

 /* Checks the validity of a particular move for the piece "Queen" */
bool Queen::validMovePiece(const int &source_file, const int &source_rank,
			   const int &destination_file, const int &destination_rank,
			   bool captures_piece) {

  int rank_move = destination_rank - source_rank;
  int file_move = destination_file - source_file;

  //Queen moves straight
  if ((abs(rank_move) >= 1 && file_move == 0) || (rank_move == 0 && abs(file_move) >= 1))
    return true;

  //Queem moves diagonally
  if (abs(rank_move) == abs(file_move))
    return true;

  return false;
}
