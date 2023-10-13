#ifndef KNIGHT_H
#define KNIGHT_H

#include "ChessPieces.h"

/******************************************* Knight *******************************************/

class Knight : public ChessPiece {
  
public:

  Knight(color color);
  /* Constructor */

  ~Knight() override;
  /* Destructor */

  bool validMovePiece(const int &source_file, const int &source_rank, const int &destination_file,
		      const int &destination_rank, bool captures_piece) override;
  /* Checks the validity of a particular move for the piece "Knight" */
};

#endif
