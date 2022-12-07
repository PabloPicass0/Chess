#ifndef CHESSPIECES_H
#define CHESSPIECES_H

#include "color.h"
#include "pieceType.h"


/**************************************** ChessPiece ************************************/

class ChessPiece {
  
 protected:

  /* Constructor */
  ChessPiece(type type, color color);

  /* Piece attributes */
  type pieceType;
  color pieceColor;
  std::string pieceIcon;
  bool pieceHasMoved;
  
 public:

  /* Destructor */
  virtual ~ChessPiece() {};

  /* Getter functions */
  virtual color get_color();
  virtual type get_type();
  virtual std::string get_icon();

  /* Move functions */
  virtual void set_pieceHasMoved();
  virtual bool validMovePiece(const int &source_file, const int &source_rank,
			      const int &destination_file,
			      const int &destination_rank, bool captures_piece) = 0;
};

#endif
