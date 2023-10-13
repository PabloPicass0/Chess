#ifndef PAWN_H
#define PAWN_H

#include "ChessPieces.h"

/******************************************** Pawn ********************************************/

class Pawn : public ChessPiece {
  
public:

  Pawn(color color);
  /* Constructor */

  ~Pawn() override;
  /* Destructor */

  bool validMovePiece(const int &source_file, const int &source_rank, const int &destination_file,
		      const int &destination_rank, bool captures_piece) override;
  /* Checks the validity of a particular move for the piece "Pawn" */
};

#endif
