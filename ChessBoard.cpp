#include <iostream>
#include <cstring>
#include "ChessBoard.h"
#include "ChessPieces.h"
#include "King.h"
#include "Castle.h"
#include "Bishop.h"
#include "Queen.h"
#include "Knight.h"
#include "Pawn.h"

using namespace std;

/****************************************** ChessBoard ******************************************/

/* ChessBoard constructor populating a board with black and white pieces on initial positions */
ChessBoard::ChessBoard() : pieces() { //pieces() makes all pointers point to null
  populate(Black);
  populate(White);
  GameOver = false;
  isTurn = White;
  cout << "A new chess game is started!\n";
}

/* ChessBoard destructor removing remaining chess piece objects from the heap */
ChessBoard::~ChessBoard() {
  removePieces();
}

/* Creates chess piece objects and sets them into intital position */
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
  
  for (int file = 0; file < MAX_FILE_SIZE; file++) {
    pieces[rankPawn][file] = new Pawn(pieces_color);
  }
}

/* Deletes chess pieces and makes pointers point to null */
void ChessBoard::removePieces() {
  for (int rank = 0; rank < MAX_RANK_SIZE; rank++) {
    for (int file = 0; file < MAX_FILE_SIZE; file++) {
      delete pieces[rank][file];
      pieces[rank][file] = NULL;
    }
  }
}

/* Destroys all pieces and repopulates board with new pieces  */
void ChessBoard::resetBoard() {
  removePieces();

  populate(Black);
  populate(White);
  GameOver = false;
  isTurn = White;
  cout << "A new chess game is started!\n";
}

/* Prints ChessBoard with icons of pieces to show where pieces are moving */
void ChessBoard::printBoard() {
  cout << "    ";
  for (int file = 0; file < MAX_FILE_SIZE; file++)
    cout << " " << (char) ('A' + file) << "    ";

  cout << '\n';
  for (int rank = 0; rank < MAX_RANK_SIZE; rank++) {
    cout << "  +-----+-----+-----+-----+-----+-----+-----+-----+\n";
    printRank(rank);
  }
  cout << "  +-----+-----+-----+-----+-----+-----+-----+-----+\n\n";
}

/* Helper function for printBoard to print the ranks/rows one by one */
void ChessBoard::printRank(const int &rank_num) {
  cout << (char) ('8' - rank_num) << " ";
  for (int file = 0; file < MAX_FILE_SIZE; file++) {
    cout << '|' << "  ";
    cout << ((pieces[rank_num][file] == NULL) ? " " : pieces[rank_num][file]->get_icon()) << "  ";
  }
  cout << "|\n";
  } 

// Overrides ostream operator to cout enum values
std::ostream& operator << (std::ostream& out_stream, color piece_color) {
  switch(piece_color)   //uses switch to assign colors to enum values
    {
      case Black: out_stream << "Black"; break;
      case White: out_stream << "White"; break;
    }
  return out_stream;  
}

/* Overrides ostream operator to cout pieceType strings */
std::ostream& operator << (std::ostream& out_stream, type piece_type) {
  switch(piece_type)   //uses switch to assign colors to enum values
    {
      case PAWN: out_stream << "Pawn"; break;
      case CASTLE: out_stream << "Castle"; break;
      case KNIGHT: out_stream << "Knight"; break;
      case BISHOP: out_stream << "Bishop"; break;
      case QUEEN: out_stream << "Queen"; break;
      case KING: out_stream << "King"; break;
    }
  return out_stream;  
}

/* Checks whether a move is valid */
bool ChessBoard::validInput(const char source_square[2], const char destination_square[2]) {

  //Converts input positions into board parameters (0-7)
  int source_file = source_square[0] - 'A', source_rank = -(source_square[1] - '8');
  int destination_file = destination_square[0] - 'A', destination_rank = -(destination_square[1] - '8');
  
  //Checks if the source square format is inputed correctly (A-H/8-1)
  if (strlen(source_square) != 2) {
    cout << source_square << " is an invalid position (columns A-H/ rows 1-8)!\n";
    return false;
  }

  //Checks if the destination square format is inputed correctly (A-H/8-1)
  if (strlen(destination_square) != 2) {
      cout << destination_square << " is an invalid position (columns A-H/ rows 1-8)!\n";
    return false;
  }
  
  //Checks if source square is out of range
  if (source_file < 0 || source_file > 7 || source_rank < 0 || source_rank > 7) {
    cout << source_square << " is an invalid position (columns A-H/ rows 1-8)!\n";
    return false;
  }

  //Checks if destination square is out of range
  if (destination_file < 0 || destination_file > 7 || destination_rank < 0 || destination_rank > 7) {
    cout << destination_square << " is an invalid position (columns A-H/ rows 1-8)!\n";
    return false;
  }

  //Checks if there is a piece on the source square
  if (pieces[source_rank][source_file] == NULL) {
    cout << "There is no piece at " << source_square << "!\n";
    return false;
  }

  //Checks if the right color is moving
  if (pieces[source_rank][source_file]->get_color() != isTurn) {
    cout << "It is not " << pieces[source_rank][source_file]->get_color()
         << "'s turn to move!\n";
    return false;
  }

  //checks if source and destination squares are equal
  if (source_square == destination_square) {
    cout << "You cannot move from " << source_square << " to " << destination_square << "!\n";
    return false;
  }
  
  return true;
}

/* Checks wether the particular piece can do the move and whether the move is blocked */
bool ChessBoard::validMove(const int &source_file, const int &source_rank, const int &destination_file, const int &destination_rank) { 

  //Boolean variable needed to assess validity of a Pawns' move 
  bool piece_captured = opponentHit(source_file, source_rank, destination_file, destination_rank);

  if (!(pieces[source_rank][source_file]->validMovePiece(source_file, source_rank, destination_file, destination_rank, piece_captured))) {
    return false;
  }

  if (isBlocked(source_file, source_rank, destination_file, destination_rank)) {
    return false;
  }

  return true;
    
}

/* Checks if a piece of the opponent is captured with the move */
bool ChessBoard::opponentHit(const int &source_file, const int &source_rank, const int &destination_file, const int &destination_rank) {

  if (pieces[destination_rank][destination_file] != NULL &&
      pieces[destination_rank][destination_file]->get_color() != pieces[source_rank][source_file]->get_color()) {
      return true;
  }
  
  return false;
}

/* Checks whether the move of a piece is blocked by another piece */
bool ChessBoard::isBlocked(const int &source_file, const int &source_rank, const int &destination_file, const int &destination_rank) {
  
  if (pieces[destination_rank][destination_file] != NULL &&
      pieces[destination_rank][destination_file]->get_color() == pieces[source_rank][source_file]->get_color()) {
    return true;
  }

  //Knights are excluded since they jump over pieces
  if (pieces[source_rank][source_file]->get_type() == KNIGHT) 
    return false;
 
  int rank_move = destination_rank - source_rank;
  int file_move = destination_file - source_file;

  //Factor variables define direction of path
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

  //Loops through every square on the path to check if it is blocked
  for (int count = 1; count < max(abs(rank_move), abs(file_move)); count++) {
    if (pieces[source_rank + rank_factor * count][source_file + file_factor * count] != NULL) { 
      return true;
    }
  }
  
  return false;
}

/* Makes a move by reassigning corresponding pointers */
void ChessBoard::makeMove(const int &source_file, const int &source_rank, const int &destination_file, const int &destination_rank) {
  
  pieces[destination_rank][destination_file] = pieces[source_rank][source_file];
  pieces[source_rank][source_file] = NULL;
  
}

/* Reverses a move by assigning pointers back */
void ChessBoard::reverseMove(const int &source_file, const int &source_rank, const int &destination_file, const int &destination_rank, ChessPiece* ptr_moved) {

  pieces[source_rank][source_file] = pieces[destination_rank][destination_file]; 
  pieces[destination_rank][destination_file] = ptr_moved;
  
}


/* Checks if the given color is in check */
bool ChessBoard::isCheck(color thisColor) {

  int king_rank(-1), king_file(-1);

  //Finds King rank and file position
  for (int rank = 0; rank < MAX_RANK_SIZE && king_rank < 0; rank++) {
    for (int file = 0; file < MAX_FILE_SIZE && king_file < 0; file++) {
      if (pieces[rank][file] != NULL) {
	if (pieces[rank][file]->get_type() == KING && pieces[rank][file]->get_color() == thisColor) {
	  king_rank = rank;
	  king_file = file;
	}
      }
    }
  }

  //Assesses if any opponent piece has a valid move on the king 
  for (int rank = 0; rank < MAX_RANK_SIZE; rank++) {
    for (int file = 0; file < MAX_FILE_SIZE; file++) {
      if (pieces[rank][file] != NULL && pieces[rank][file]->get_color() != thisColor) {
	if (validMove(file, rank, king_file, king_rank)) {
	  return true;
	}
      }
    }
  }

  return false;
}


/* Checks if the given color is in checkmate */
bool ChessBoard::hasLegalMove(color waiting_color) {
  
  ChessPiece* ptr_moved = nullptr;

  //Checks if any piece of the given color has a move that would not leave the color in check
  for (int source_rank = 0; source_rank < MAX_RANK_SIZE; source_rank++) {
    for (int source_file = 0; source_file < MAX_FILE_SIZE; source_file++) {
      if (pieces[source_rank][source_file] != NULL && pieces[source_rank][source_file]->get_color() == waiting_color) {
	for (int destination_rank = 0; destination_rank < MAX_RANK_SIZE; destination_rank++) {
	  for (int destination_file = 0; destination_file < MAX_FILE_SIZE; destination_file++) {
	    if (validMove(source_file, source_rank, destination_file, destination_rank)) {
	      ptr_moved = pieces[destination_rank][destination_file];
	      makeMove(source_file, source_rank, destination_file, destination_rank);
	      if (!isCheck(waiting_color)) {
		reverseMove(source_file, source_rank, destination_file, destination_rank, ptr_moved);
		return true;
	      }
	      if (isCheck(waiting_color)) {
		reverseMove(source_file, source_rank, destination_file, destination_rank, ptr_moved);
	      }
	    }
	  }
	}
      }
    }
  }

  return false;
}
 
/* Validates and conducts or rejects a submitted move */
bool ChessBoard::submitMove(const char source_square[2], const char destination_square[2]) {

  if (GameOver) {
    cout << "Game is over\n";
    return false;
  }
  
  //Captures color of moving party and color of opponent in variables for couts and function calls
  color moving_color = isTurn;
  color waiting_color = (moving_color == White ? Black : White); 

  int source_file = source_square[0] - 'A', source_rank = -(source_square[1] - '8');
  int destination_file = destination_square[0] - 'A', destination_rank = -(destination_square[1] - '8');
  
  if (!validInput(source_square, destination_square)) {
    return false;
  }
  
  if (!validMove(source_file, source_rank, destination_file, destination_rank)) {
    cout << moving_color << "'s " << pieces[source_rank][source_file]->get_type()
	 << " cannot move to " << destination_square << "!\n";
    return false;
  }

  //Creates temp pointer to destination square (useful for when a piece is captures to reverse the move)
  ChessPiece* ptr_moved = pieces[destination_rank][destination_file];
    
  makeMove(source_file, source_rank, destination_file, destination_rank);

  if (isCheck(moving_color)) {
    cout << "This move would set " << moving_color << "' king in check. Move reversed.\n";
    reverseMove(source_file, source_rank, destination_file, destination_rank, ptr_moved);
    return false;
  }

  pieces[destination_rank][destination_file]->set_pieceHasMoved();
  
  //Print move
  if (ptr_moved == NULL) {
    cout << moving_color << "'s " << pieces[destination_rank][destination_file]->get_type()
	 << " moves from " << source_square << " to " << destination_square << endl;
  }
  else if (ptr_moved != NULL) {
    cout << moving_color << "'s " << pieces[destination_rank][destination_file]->get_type()
	 << " moves from " << source_square << " to " << destination_square << " taking "
	 << waiting_color << "'s " << ptr_moved->get_type() << endl;
    delete ptr_moved;
  }

  //Check state of game
  if (isCheck(waiting_color)) {
    if (hasLegalMove(waiting_color)) {
      cout << waiting_color << " is in check\n";
    }
    else if (!hasLegalMove(waiting_color)) {
      cout << waiting_color << " is in checkmate\n";
      GameOver = true;
    }
  }
  else if (!hasLegalMove(waiting_color)) {
    cout << waiting_color << " is in stalemate\n";
    GameOver = true;
  }
  
  isTurn = (isTurn == White ? Black : White);
  return true;
}
