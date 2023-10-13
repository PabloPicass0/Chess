#ifndef QUEEN_H
#define QUEEN_H

#include "ChessPieces.h"

/******************************************** Queen ********************************************/

class Queen : public ChessPiece {
  
public:

  Queen(color color);
  /* Constructor */

  ~Queen() override;
  /* Destructor */

  bool validMovePiece(const int &source_file, const int &source_rank, const int &destination_file,
		      const int &destination_rank, bool captures_piece) override;
  /* Checks the validity of a particular move for the piece "Queen" */
};

#endif
