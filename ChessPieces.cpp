#include <iostream>
#include "ChessPieces.h"
#include <string>

using namespace std;

ChessPiece::ChessPiece(string name, color color) : pieceName(name), pieceColor(color) {
  pieceHasMoved = false;
}

color ChessPiece::get_color() {
  return pieceColor;
}

string ChessPiece::get_name() {
  return pieceName;
}

string ChessPiece::get_initials() {
  return pieceName.substr(0, 2);
}
 
/**************************************** King ***************************************/

King::King(color color) : ChessPiece("King", color) {
  pieceHasMoved = false;
}

bool King::validMove(const int source_file, const int source_rank, const int destination_file, const int destination_rank, bool captures_piece) {
  
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

/**************************************** Castle ***************************************/

Castle::Castle(color color) : ChessPiece("Castle", color) {
  pieceHasMoved = false;
}

bool Castle::validMove(const int source_file, const int source_rank, const int destination_file, const int destination_rank, bool captures_piece) {

  int rank_move = destination_rank - source_rank;
  int file_move = destination_file - source_file;

  //Castle moves straight
  return ((abs(rank_move) >= 1 && file_move == 0) || (rank_move == 0 && abs(file_move) >= 1));
}

/**************************************** Bishop ***************************************/

Bishop::Bishop(color color) : ChessPiece("Bishop", color) {
  pieceHasMoved = false;
}

bool Bishop::validMove(const int source_file, const int source_rank, const int destination_file, const int destination_rank, bool captures_piece) {

  int rank_move = destination_rank - source_rank;
  int file_move = destination_file - source_file;

  //Bishop moves diagonally
  return (abs(rank_move) == abs(file_move));
}


/**************************************** Queen ****************************************/

Queen::Queen(color color) : ChessPiece("Queen", color) {
  pieceHasMoved = false;
}

bool Queen::validMove(const int source_file, const int source_rank, const int destination_file, const int destination_rank, bool captures_piece) {

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

/**************************************** Knight ***************************************/

Knight::Knight(color color) : ChessPiece("Knight", color) {
  pieceHasMoved = false;
}

bool Knight::validMove(const int source_file, const int source_rank, const int destination_file, const int destination_rank, bool captures_piece) {

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

/**************************************** Pawn ****************************************/

//Pawn constructor
Pawn::Pawn(color color) : ChessPiece("Pawn", color) {
  pieceHasMoved = false;
}

//Pawn makeMove validator
bool Pawn::validMove(const int source_file, const int source_rank, const int destination_file, const int destination_rank, bool captures_piece) {

  int move_direction = 1; //black pawns can only move up
  if (pieceColor == White)
    move_direction = (-1);  //white pawns move down

  int rank_move = (destination_rank - source_rank) * move_direction;
  int file_move = destination_file - source_file;

  //pawn moves one forward
  if (rank_move == 1 && file_move == 0 && !captures_piece)
    return true;

  //pawn moves two forward
  if (rank_move == 2 && file_move == 0 && !captures_piece)
    return true;

  //pawn captures piece
  if (rank_move == 1 && abs(file_move) == 1 && captures_piece)
    return true;

  return false;
}
