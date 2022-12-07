#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "color.h"
#include "ChessPieces.h"

/* forward declaration: claims existence of class ChessPiece */
class ChessPiece;

const int MAX_RANK_SIZE = 8;
const int MAX_FILE_SIZE = 8;

std::ostream& operator << (std::ostream& out_stream, color piece_color);

class ChessBoard {
 public:
  
  ChessBoard();
  /* Chessboard default constructor that sets up chess board */
  
  void resetBoard();
  
  void printBoard();

  bool submitMove(const char source_square[2], const char destination_square[2]);
  /* submits a move on the board; returns true if move has been set; false if move is invalid */

 private:

  ChessPiece* pieces[MAX_RANK_SIZE][MAX_FILE_SIZE];        //pieces ptr_array
  color isTurn;
  bool GameOver;

  void populate(color pieces_color);

  void removePieces();

  void printRank(const int &rank_num);

  bool opponentHit(const int &source_file, const int &source_rank, const int &destination_file, const int &destination_rank);
  /* helper function that checks if an opponent piece is captured */

  bool isCheck(color thisColor);
  /* helper function that helps determine if a party is in check */

  bool hasLegalMove(color waiting_color);
  /* checks if a color still has a next valid move */

  void makeMove(const int &source_file, const int &source_rank, const int &destination_file, const int &destination_rank);
  /* conducts move by setting pointers */

  void reverseMove(const int &source_file, const int &source_rank, const int &destination_file, const int &destination_rank, ChessPiece* ptr_moved);
  /* reverses move if it would have set own king in check */

  bool validInput(const char source_square[2], const char destination_square[2]);
  /* helper function for submitMove to validate if move is ok */

  bool validMove(const int &source_file, const int &source_rank, const int &destination_file, const int &destination_rank);
  /* validates move for particular piece considering if it is blocked and if it captures opponents */
		  
  bool isBlocked(const int &source_file, const int &source_rank, const int &destination_file, const int &destination_rank);
  /* helper function that checks if the move of the piece is blocked */
};

#endif
