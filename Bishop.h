#ifndef BISHOP_H
#define BISHOP_H

#include "ChessPieces.h"

/****************************************** Bishop *******************************************/

class Bishop : public ChessPiece {
  
public:

  /* Constructor */
  Bishop(color color);

  /* Destructor */
  ~Bishop() override;

  /* Checks the validity of a particular move for the piece "Bishop" */
  bool validMovePiece(const int &source_file, const int &source_rank, const int &destination_file,
		      const int &destination_rank, bool captures_piece) override;
};

#endif
