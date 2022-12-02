#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include "ChessBoard.h"
#include "ChessPieces.h"

using namespace std;

/* ChessBoard constructor populating a board with black and white pieces on initial positions */
ChessBoard::ChessBoard() : pieces() { //create empty board --> calling just pieces() makes all pointers point to null
  /*
   for (int rank = 0; rank < MAX_RANK_SIZE; rank++)
    for (int file = 0; file < MAX_FILE_SIZE; file++)
      {
	pieces[rank][file] = NULL;
      }
  */
  populate(Black);
  populate(White);
  isTurn = White;
  cout << "A new chess game is started!\n";
}

/* makes ChessBoard pointers point to pieces in initial positions */
void ChessBoard::populate(color pieces_color) {
  int rankCourt = (pieces_color == Black ? 0 : 7);
  int rankPawn = (pieces_color == Black ? 1 : 6);
  
  pieces[rankCourt][0] = new Castle(pieces_color);   
  pieces[rankCourt][1] = new Knight(pieces_color);
  pieces[rankCourt][2] = new Bishop(pieces_color);
  pieces[rankCourt][3] = new Queen(pieces_color);
  pieces[rankCourt][4] = new King(pieces_color);
  pieces[rankCourt][5] = new Bishop(pieces_color);
  pieces[rankCourt][6] = new Knight(pieces_color);
  pieces[rankCourt][7] = new Castle(pieces_color);
  
  for (int file = 0; file < MAX_FILE_SIZE; file++)
    pieces[rankPawn][file] = new Pawn(pieces_color);
} 

/* prints ChessBoard with initials of pieces to show where pieces are moving */
void ChessBoard::printBoard() {
  cout << "    ";
  for (int file = 0; file < MAX_FILE_SIZE; file++)
    cout << (char) ('A' + file) << "    ";

  cout << '\n';
  for (int rank = 0; rank < MAX_RANK_SIZE; rank++) {
    cout << "  +----+----+----+----+----+----+----+----+\n";
    printRank(rank);
  }
  cout << "  +----+----+----+----+----+----+----+----+\n\n";
}

/* Helper function for printBoard function to print the ranks one by one */
void ChessBoard::printRank(int rank_num) {
  cout << (char) ('8' - rank_num) << " ";
  for (int file = 0; file < MAX_FILE_SIZE; file++) {
    cout << '|' << " ";
    cout << ((pieces[rank_num][file] == NULL) ? "  " : pieces[rank_num][file]->get_initials()) << " ";
  }
  cout << "|\n";
}

/*getter function retrieving pointer to a board position 
ChessPiece* ChessBoard::boardSquare(int rank, int file) {
  return pieces[rank][file];
  } */

//overrides ostream operator to cout enum values
std::ostream& operator << (std::ostream& out_stream, color piece_color) {
  switch(piece_color)   //uses switch to assign colors to enum values
    {
      case Black: out_stream << "Black"; break;
      case White: out_stream << "White"; break;
    }
  return out_stream;  
}

/* Checks whether a move is valid */
bool ChessBoard::preMove(const char source_square[2], const char destination_square[2]) {

  //converts input positions into board parameters (0-7)
  int source_file = source_square[0] - 'A', source_rank = -(source_square[1] - '8');
  int destination_file = destination_square[0] - 'A', destination_rank = -(destination_square[1] - '8');
  
  //checks if the source square or destination square format is inputed correctly (A-H/8-1)
  if (strlen(source_square) != 2 || strlen(destination_square) != 2) {
    cout << "Please input only valid positions (columns A-H/ rows 1-8)!\n";
    return false;
  }
  
  //checks if source square is out of range
  if (source_file < 0 || source_file > 7 || source_rank < 0 || source_rank > 7) {
    cout << source_square << " is out of range!\n";
    return false;
  }

  //checks if destination square is out of range
  if (destination_file < 0 || destination_file > 7 || destination_rank < 0 || destination_rank > 7) {
    cout << destination_square << " is out of range!\n";
    return false;
  }


  //checks if there is a piece on the source square
  if (pieces[source_rank][source_file] == NULL) {
    cout << "There is no piece at " << source_square << "!\n";
    return false;
  }

  
  //Check if the right color is moving
  if (pieces[source_rank][source_file]->get_color() != isTurn) {
    cout << "It is not " << pieces[source_rank][source_file]->get_color()
         << "'s turn to move!\n";
    return false;
  }

  //checks if source and destination squares are equal
  if (source_square == destination_square) {
    cout << "You cannot set the destination to the source square!\n";
    return false;
  }
  
  return true;
}

//Checks wether the particular piece can actually conduct this move
bool ChessBoard::actualMove(const int source_file, const int source_rank, const int destination_file, const int destination_rank) {

  if (isBlocked(source_file, source_rank, destination_file, destination_rank)) {
    return false;
  }

  bool piece_captured = opponentHit(source_file, source_rank, destination_file, destination_rank);

  if (!(pieces[source_rank][source_file]->validMove(source_file, source_rank, destination_file, destination_rank, piece_captured))) {
    return false;
  }

  return true;
    
}

//Checks whether the move of a piece is blocked by another piece
bool ChessBoard::isBlocked(const int source_file, const int source_rank, const int destination_file, const int destination_rank) {
  
  if (pieces[source_rank][source_file]->get_name() == "Knight")  //knights can jump
    return false;
 
  int rank_move = destination_rank - source_rank;
  int file_move = destination_file - source_file;
  
  int rank_factor, file_factor;

  if (rank_move == 0)
    rank_factor = 0;
  else if (rank_move < 0)
    rank_factor = (-1);
  else if (rank_move > 0)
    rank_factor = 1;

  if (file_move == 0)
    file_factor = 0;
  else if (file_move < 0)
    file_factor = (-1);
  else if (file_move > 0)
    file_factor = 1;

  for (int count = 1; count < max(abs(rank_move), abs(file_move)); count++) {
    if (pieces[source_rank + rank_factor * count][source_file + file_factor * count] != NULL) { 
      /*
      cout << "The move of " << isTurn << "' " << pieces[source_rank][source_file]->get_name() << " is blocked by "
	   << pieces[source_rank + rank_factor * count][source_file + file_factor * count]->get_color() << "' "
	   << pieces[source_rank + rank_factor * count][source_file + file_factor * count]->get_name() << "!\n";
      */
      return true;
    }
  }

  if (pieces[destination_rank][destination_file] != NULL) {
    if (pieces[destination_rank][destination_file]->get_color() == pieces[source_rank][source_file]->get_color()) {
    return true;
    }
  }
  
  return false;
}

//checks if a pice of the opponent is captured with the move
bool ChessBoard::opponentHit(const int source_file, const int source_rank, const int destination_file, const int destination_rank) {

  if (pieces[destination_rank][destination_file] != NULL) {
    if (pieces[destination_rank][destination_file]->get_color() != pieces[source_rank][source_file]->get_color()) {
      return true;
    }
  }
  return false;
}

//checks if one of both parties is in check
bool ChessBoard::isCheck(color thisColor) {

  int king_rank, king_file;

  //find King rank and file position;
  for (int rank = 0; rank < MAX_RANK_SIZE; rank++) {
    for (int file = 0; file < MAX_FILE_SIZE; file++) {
      if (pieces[rank][file] != NULL) {
	if (pieces[rank][file]->get_name() == "King" && pieces[rank][file]->get_color() == thisColor) {
	  king_rank = rank;
	  king_file = file;
	}
      }//------------------------------------------------------> way to exit nested loop early?
    }
  }

  //assess if king is in check by checking if other pieces have a valid move on king
  for (int rank = 0; rank < MAX_RANK_SIZE; rank++) {
    for (int file = 0; file < MAX_FILE_SIZE; file++) {
      if (pieces[rank][file] != NULL) {
	if (pieces[rank][file]->get_color() != thisColor) {
	  if (actualMove(file, rank, king_file, king_rank)) {
	    return true;
	  }
	}
      }
    }
  }

  return false;
}

void ChessBoard::makeMove(const int source_file, const int source_rank, const int destination_file, const int destination_rank) {
  
  pieces[destination_rank][destination_file] = pieces[source_rank][source_file];
  pieces[source_rank][source_file] = NULL;
  
}

void ChessBoard::reverseMove(const int source_file, const int source_rank, const int destination_file, const int destination_rank, ChessPiece* ptr_moved) {

  pieces[source_rank][source_file] = pieces[destination_rank][destination_file]; 
  pieces[destination_rank][destination_file] = ptr_moved;
  
}

//validates and conducts or rejects submitted move
bool ChessBoard::submitMove(const char source_square[2], const char destination_square[2]) {

  //captures color of moving party and color of opponent in variables for couts and function calls
  color moving_color = isTurn;
  color waiting_color = (moving_color == White ? Black : White); 

  //converts input positions into board parameters (0-7)
  int source_file = source_square[0] - 'A', source_rank = -(source_square[1] - '8');
  int destination_file = destination_square[0] - 'A', destination_rank = -(destination_square[1] - '8');
  
  //conducts pre-move check (is position out of range, whose turn is it etc.)
  if (!preMove(source_square, destination_square)) {
    return false;
  }
  
  //checks if move is valid for particular piece considering if it would be blocked and if it captures opponent
  if (!actualMove(source_file, source_rank, destination_file, destination_rank)) {
    cout << moving_color << "'s " << pieces[source_rank][source_file]->get_name() << " cannot move to " << destination_square << "!\n";
    return false;
  }

  //creates temp pointer to destination square
  ChessPiece* ptr_moved = pieces[destination_rank][destination_file];
    
  //make move and set pieceHasMoved
  makeMove(source_file, source_rank, destination_file, destination_rank);

  if (isCheck(moving_color)) {
    cout << "This move would set " << moving_color << "' king in check. Move reversed.\n";
    reverseMove(source_file, source_rank, destination_file, destination_rank, ptr_moved);
    return false;
  }
  
  //print move
  if (ptr_moved == NULL) {
    cout << isTurn << "'s " << pieces[destination_rank][destination_file]->get_name()
	 << " moves from " << source_square << " to " << destination_square << endl;
  }
  else if (ptr_moved != NULL) {
    cout << isTurn << "'s " << pieces[destination_rank][destination_file]->get_name()
	 << " moves from " << source_square << " to " << destination_square << " taking "
	 << ptr_moved->get_color() << "'s " << ptr_moved->get_name() << endl;
  }

  if (isCheck(waiting_color)) {
    cout << waiting_color << " is in check\n";
  }

//**********post move check structure 
  //checks if move brought own king in check and reverses move

  /*
  if (isCheck(IsTurn->King)) {
    reverseMove();
    cout << "Your king is in check, try again\n";
    return false;
    }
  
  //checks if move brings opponent in check and if game is over
  if (isCheck(!isTurn->King)) {
    if (hasLegalMove())
      cout << "!isTurn is in check\n";
    else if (!hasLegalMove())
      cout << "!isTurn is checkmate";
  }

  if (!isCheck(!isTurn->King) && !hasLegalMove())
    cout << "Stalemate";
  */
//**********post move
  
  pieces[destination_rank][destination_file]->set_pieceHasMoved();
  isTurn = (isTurn == White ? Black : White);
  return true;
}


//***********************************************Notes************************************************


  /* To do`s */
  //make opponentHit return a pointer to hit opponent to substitute capture_piece variable

/* 
hasLegalMove(Color, bool)
-go through every of the opponents pieces
-for every opponent piece, go through board and check if there is a legal move (validMove, isBlocched, isCheck(owncolor)
-if not: checkmate
*/
