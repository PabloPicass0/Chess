#include <iostream>
#include "ChessPieces.h"
#include "Bishop.h"

using namespace std;

/****************************************** Bishop *******************************************/

/* Constructor */
Bishop::Bishop(color color) : ChessPiece(BISHOP, color) {
  pieceIcon = ((color == White) ? "♗" : "♝");
  pieceHasMoved = false;
}

/* Destructor */
Bishop::~Bishop() {}

/* Checks the validity of a particular move for the piece "Bishop" */
bool Bishop::validMovePiece(const int &source_file, const int &source_rank,
			    const int &destination_file, const int &destination_rank,
			    bool captures_piece) {

  int rank_move = destination_rank - source_rank;
  int file_move = destination_file - source_file;

  //Bishop moves diagonally
  return (abs(rank_move) == abs(file_move));
}
