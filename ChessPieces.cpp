#include <iostream>
#include "ChessPieces.h"

using namespace std;

/**************************************** ChessPiece ************************************/

/* Constructor */
ChessPiece::ChessPiece(type type, color color) : pieceType(type), pieceColor(color) {
  pieceIcon = "undefined";
  pieceHasMoved = false;
}

/* Getter and setter functions */
color ChessPiece::get_color() {
  return pieceColor;
}

std::string ChessPiece::get_icon() {
  return pieceIcon;
}

type ChessPiece::get_type() {
  return pieceType;
}

void ChessPiece::set_pieceHasMoved() {
  pieceHasMoved = true;
}

