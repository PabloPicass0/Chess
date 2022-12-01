#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "color.h"
#include "ChessPieces.h"
/* claims existence of class ChessPiece */
class ChessPiece;

const int MAX_RANK_SIZE = 8;
const int MAX_FILE_SIZE = 8;

class ChessBoard {
 public:
  
  ChessBoard();
  /* Chessboard default constructor that sets up chess board */

  void printBoard();

  bool submitMove(const char source_square[2], const char destination_square[2]);
  /* submits a move on the board; returns true if move has been set; false if move is invalid */

  bool preMove(const char source_square[2], const char destination_square[2]);
  /* helper function for submitMove to validate if move is ok */

  bool isBlocked(const int source_file, const int source_rank, const int destination_file, const int destination_rank);
  /* helper function that checks if the move of the piece is blocked */

  bool opponentHit(const int source_file, const int source_rank, const int destination_file, const int destination_rank);
  /* helper function that checks if an opponent piece is captured */

 private:

  ChessPiece* pieces[MAX_RANK_SIZE][MAX_FILE_SIZE];//pieces ptr_array

  color isTurn;

  void populate(color pieces_color);

  void printRank(int rank_num);
};

#endif
