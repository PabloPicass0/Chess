#include <iostream>
#include "ChessPieces.h"
#include "ChessBoard.h"
#include <string>

using namespace std;

/**************************************** ChessPiece ************************************/

ChessPiece::ChessPiece(type type, color color) : pieceType(type), pieceColor(color) {
  pieceIcon = "undefined";
  pieceHasMoved = false;
}

color ChessPiece::get_color() {
  return pieceColor;
}

/* string ChessPiece::get_name() {
  return pieceName;
  } */

std::string ChessPiece::get_icon() {
  return pieceIcon;
}


type ChessPiece::get_type() {
  return pieceType;
}

/* string ChessPiece::get_initials() {
  return pieceName.substr(0, 2);
  } */

void ChessPiece::set_pieceHasMoved() {
  pieceHasMoved = true;
}

/**************************************** King *****************************************/

King::King(color color) : ChessPiece(KING, color) {
  pieceIcon = ((color == White) ? "♔" : "♚");
  pieceHasMoved = false;
}

King::~King() {}

bool King::validMovePiece(const int &source_file, const int &source_rank, const int &destination_file, const int &destination_rank, bool captures_piece) {
  
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

Castle::Castle(color color) : ChessPiece(CASTLE, color) {
  pieceIcon = ((color == White) ? "♖" : "♜");
  pieceHasMoved = false;
}

Castle::~Castle() {}

bool Castle::validMovePiece(const int &source_file, const int &source_rank, const int &destination_file, const int &destination_rank, bool captures_piece) {

  int rank_move = destination_rank - source_rank;
  int file_move = destination_file - source_file;

  //Castle moves straight
  return ((abs(rank_move) >= 1 && file_move == 0) || (rank_move == 0 && abs(file_move) >= 1));
}

/**************************************** Bishop ***************************************/

Bishop::Bishop(color color) : ChessPiece(BISHOP, color) {
  pieceIcon = ((color == White) ? "♗" : "♝");
  pieceHasMoved = false;
}

Bishop::~Bishop() {}

bool Bishop::validMovePiece(const int &source_file, const int &source_rank, const int &destination_file, const int &destination_rank, bool captures_piece) {

  int rank_move = destination_rank - source_rank;
  int file_move = destination_file - source_file;

  //Bishop moves diagonally
  return (abs(rank_move) == abs(file_move));
}


/**************************************** Queen ****************************************/

Queen::Queen(color color) : ChessPiece(QUEEN, color) {
  pieceIcon = ((color == White) ? "♕" : "♛");
  pieceHasMoved = false;
}

Queen::~Queen() {}

bool Queen::validMovePiece(const int &source_file, const int &source_rank, const int &destination_file, const int &destination_rank, bool captures_piece) {

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

Knight::Knight(color color) : ChessPiece(KNIGHT, color) {
  pieceIcon = ((color == White) ? "♘" : "♞");
  pieceHasMoved = false;
}

Knight::~Knight() {}

bool Knight::validMovePiece(const int &source_file, const int &source_rank, const int &destination_file, const int &destination_rank, bool captures_piece) {

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
Pawn::Pawn(color color) : ChessPiece(PAWN, color) {
  pieceIcon = ((color == White) ? "♙" : "♟");
  pieceHasMoved = false;
}

Pawn::~Pawn() {}

//Pawn makeMove validator
bool Pawn::validMovePiece(const int &source_file, const int &source_rank, const int &destination_file, const int &destination_rank, bool piece_captured) {

  int move_direction = 1; //black pawns can only move up
  if (pieceColor == White)
    move_direction = (-1);  //white pawns move down

  int rank_move = (destination_rank - source_rank) * move_direction;
  int file_move = destination_file - source_file;

  //pawn moves one forward
  if (rank_move == 1 && file_move == 0 && !piece_captured)
    return true;

  //pawn moves two forward
  if (rank_move == 2 && file_move == 0 && !piece_captured && !pieceHasMoved)
    return true;

  //pawn captures piece
  if (rank_move == 1 && abs(file_move) == 1 && piece_captured)
    return true;

  return false;
}
