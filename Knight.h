#ifndef KNIGHT_H
#define KNIGHT_H

#include "ChessPieces.h"

/******************************************* Knight *******************************************/

class Knight : public ChessPiece {
  
public:

  /* Constructor */
  Knight(color color);

  /* Destructor */
  ~Knight() override;

  /* Checks the validity of a particular move for the piece "Knight" */
  bool validMovePiece(const int &source_file, const int &source_rank, const int &destination_file,
		      const int &destination_rank, bool captures_piece) override;
};

#endif
