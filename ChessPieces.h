#ifndef CHESSPIECES_H
#define CHESSPIECES_H

#include "color.h"
#include "pieceType.h"


/**************************************** ChessPiece ************************************/

class ChessPiece {
  
 protected:

  ChessPiece(type type, color color);
  /* Chess Piece constructor 
     @param type: the kind of piece it is (e.g. King) defined as enum
     @param color: the color (e.g. Black) 
     - ChessPiece is an abstract class */

  type pieceType;
  color pieceColor;
  std::string pieceIcon;
  /* Piece icon as string (only used to print the board) */
  bool pieceHasMoved;
  /* Used to assess certain moves (e.g. first move of Pawn) */
  
 public:

  virtual ~ChessPiece() {};
  /* Virtual destructor, overriden by each child class to destruct pieces */

  virtual color get_color();
  virtual type get_type();
  virtual std::string get_icon();
  /* Getter functions */

  virtual void set_pieceHasMoved();
  /* Setter function; called by the board once a piece has moved */
  virtual bool validMovePiece(const int &source_file, const int &source_rank,
			      const int &destination_file,
			      const int &destination_rank, bool captures_piece) = 0;
  /* Virtual move function, overriden by each child class to define the move of each piece 
     @params files/ranks: the source and the destination position of a move passed as row and column numbers
     @param captures_piece: boolean passed to assess the validity of the Pawns' move */ 
};

#endif
