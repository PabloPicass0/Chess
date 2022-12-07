#include <iostream>
#include "ChessPieces.h"
#include "Knight.h"

using namespace std;

/******************************************* Knight *******************************************/

/* Constructor */
Knight::Knight(color color) : ChessPiece(KNIGHT, color) {
  pieceIcon = ((color == White) ? "♘" : "♞");
  pieceHasMoved = false;
}

/* Destructor */
Knight::~Knight() {}

/* Checks the validity of a particular move for the piece "Knight" */
bool Knight::validMovePiece(const int &source_file, const int &source_rank,
			    const int &destination_file, const int &destination_rank,
			    bool captures_piece) {

  int rank_move = destination_rank - source_rank;
  int file_move = destination_file - source_file;

  //knight moves L-shape: two rows and one column 
  if (abs(rank_move) == 2 && abs(file_move) == 1)
    return true;

  //knight moves L-shape: two columns and one row
  if (abs(rank_move) == 1 && abs(file_move) == 2)
    return true;

  return false;
}
