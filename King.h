#ifndef KING_H
#define KING_H

#include "ChessPieces.h"

/******************************************** King ********************************************/

class King : public ChessPiece {
  
public:

  /* Constructor */
  King(color color);

  /* Destructor */
  ~King() override;

  /* Checks the validity of a particular move for the piece "King" */
  bool validMovePiece(const int &source_file, const int &source_rank, const int &destination_file,
		      const int &destination_rank, bool captures_piece) override;
};

#endif