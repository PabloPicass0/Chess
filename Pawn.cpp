#include <iostream>
#include "ChessPieces.h"
#include "Pawn.h"

using namespace std;

/******************************************** Pawn ********************************************/

/* Constructor */
Pawn::Pawn(color color) : ChessPiece(PAWN, color) {
  pieceIcon = ((color == White) ? "♙" : "♟");
  pieceHasMoved = false;
}

/* Destructor */
Pawn::~Pawn() {}

/* Checks the validity of a particular move for the piece "Pawn" */
bool Pawn::validMovePiece(const int &source_file, const int &source_rank,
			  const int &destination_file, const int &destination_rank,
			  bool piece_captured) {

  int move_direction = 1; //Black pawns can only move up
  if (pieceColor == White)
    move_direction = (-1);  //White pawns moves down

  int rank_move = (destination_rank - source_rank) * move_direction;
  int file_move = destination_file - source_file;

  //Pawn moves one forward
  if (rank_move == 1 && file_move == 0 && !piece_captured)
    return true;

  //Pawn moves two forward
  if (rank_move == 2 && file_move == 0 && !piece_captured && !pieceHasMoved)
    return true;

  //Pawn captures piece and moves diagonally
  if (rank_move == 1 && abs(file_move) == 1 && piece_captured)
    return true;

  return false;
}
