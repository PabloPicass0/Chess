#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <iostream>
#include "ChessPieces.h"

const int MAX_RANK_SIZE = 8;
const int MAX_FILE_SIZE = 8;
/* size of rows (ranks) and columns (files) */

std::ostream& operator << (std::ostream& out_stream, color piece_color);
std::ostream& operator << (std::ostream& out_stream, type piece_type);
/* overloaded ostream operator to print color and piece type which has been defined as enum */


/****************************************** ChessBoard ******************************************/

class ChessBoard {
  
 public:
  
  ChessBoard();
  /* Chessboard constructor that sets up a chess board:
     - Creates a two-dimensional array of chess piece pointers, initially pointing to NULL
     - Calls function "populate" that creates chess piece objects and assigns pointers 
     - Sets the boolean variable "GameOver" (private attribute) to false to start a game 
     - Sets the color variable "isTurn" (private attribute) to "White" - White moves first
     - Prints: "A new chess game is started!" */
  
  void resetBoard();
  /* Removes all remaining objects and repopulates the board with new pieces 
     - Calls function "removePieces" to delete all remaining objects 
     - Calls function "populate" to create new chess piece objects and reassign pointers  
     - Sets the boolean variable "GameOver" (private attribute) to false to restart a game 
     - Sets the color variable "isTurn" (private attribute) to "White" - White moves first
     - Prints: "A new chess game is started!" */
  
  void printBoard();
  /* Prints the board to display what each board pointer is pointing to (used for debugging only)
     - Calls function "printRank" to print row by row */

  bool submitMove(const char source_square[2], const char destination_square[2]);
  /* Submits, validates, and conducts a move, if permissible
     @param source_square: initial position of a piece, as char array (columns A-H/rows 8-1) 
     @param destinaion_square: destination position of a piece, as char array (columns A-H/rows 8-1) 
     @return: true if a move is valid and has been conducted; false otherwise
     - Sets "isTurn" after every move and deletes all remaining pieces when a game is over */

 private:
  
  ChessPiece* pieces[MAX_RANK_SIZE][MAX_FILE_SIZE];
  /* Board of pointers pointing either to a piece or to NULL */
  
  color isTurn;
  /* Keeps track of whose turn it is by being set to either "White" or "Black"; defined as enum */
  
  bool GameOver;
  /* True if a move ends a game, false while the game is ongoing */

  void populate(color pieces_color);
  /* Creates new piece ojects on the heap and allocates pointers to have pieces in starting position 
     @param pieces_color: populates board with either white or black pieces, depending on passed variable */

  void removePieces();
  /* Deletes all objects on the board (freeing memory) and makes pointers point to NULL (ready to be repopulated) */

  void printRank(const int &rank_num);
  /* Helper function of printBoard: prints rows of the board including pieces the corresponding pointers might be pointing to
     @param rank_num: the row number to be printed  */

  bool validInput(const char source_square[2], const char destination_square[2]);
  /* Helper function of submitMove: checks whether board positions of a submitted move are valid
     @params: the source and the destination position of a move passed as char array  
     @return: true if move positions are valid (within range, correct format, right color moving, piece on source positon) */

  bool validMove(const int &source_file, const int &source_rank, const int &destination_file, const int &destination_rank);
  /* Helper function of submitMove: checks whether a move is valid for particular piece and if the move is blocked
     @params: the source and the destination position of a move passed as row and column numbers  
     @return: true if move is valid, that is the piece can conduct the move and is not blocked by another piece */

  bool isBlocked(const int &source_file, const int &source_rank, const int &destination_file, const int &destination_rank);
  /* Helper function of validMove: checks if the move of the moving piece is blocked 
     @params: the source and the destination position of a move passed as row and column numbers 
     @return: true if the move of the moving piece is blocked (move not permissible) */

  bool opponentHit(const int &source_file, const int &source_rank, const int &destination_file, const int &destination_rank);
  /* Helper function of validMove: checks if a piece captures another piece with a particular move
     @params: the source and the destination position of a move passed as row and column numbers
     @return: true if an opponent piece is captured, false otherwise */

  void makeMove(const int &source_file, const int &source_rank, const int &destination_file, const int &destination_rank);
  /* Helper function of submitMove: makes a move by making receiving pointer point to moving object, and source pointer point to NULL 
     @params: the source and the destination position of a move passed as row and column numbers */

  void reverseMove(const int &source_file, const int &source_rank, const int &destination_file,
		   const int &destination_rank, ChessPiece* ptr_moved);
  /* Helper function of submitMove: reverses a move if the move sets the own king in check 
     @params ints: the source and the destination position of a move passed as row and column numbers 
     @param ptr_moved: a pointer pointing to the destination square; used to not loose a captures piece */

  bool isCheck(color thisColor);
  /* Helper function of submitMove: checks if a given color is in check
     @param thisColor: the color for which the "isCheck" assessment is conducted 
     @return: true if the king of the given color is in check */

  bool hasLegalMove(color waiting_color);
  /* Helper function of submitMove: checks if a given color has a legal move left
     @param thisColor: the color for which the "hasLegalMove" assessment is conducted 
     @return: true if any piece of the color in question has a valid move 
     - if false, the game is set to "GameOver"; no more moves can be sumitted */
		  
};

#endif
