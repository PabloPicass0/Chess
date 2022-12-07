#include <iostream>
#include "ChessPieces.h"
#include "Castle.h"

using namespace std;

/******************************************* Castle *******************************************/

/* Constructor */
Castle::Castle(color color) : ChessPiece(CASTLE, color) {
  pieceIcon = ((color == White) ? "♖" : "♜");
  pieceHasMoved = false;
}

/* Destructor */
Castle::~Castle() {}

/* Checks the validity of a particular move for the piece "Castle" */
bool Castle::validMovePiece(const int &source_file, const int &source_rank,
			    const int &destination_file, const int &destination_rank,
			    bool captures_piece) {

  int rank_move = destination_rank - source_rank;
  int file_move = destination_file - source_file;

  //Castle moves straight
  return ((abs(rank_move) >= 1 && file_move == 0) || (rank_move == 0 && abs(file_move) >= 1));
}
