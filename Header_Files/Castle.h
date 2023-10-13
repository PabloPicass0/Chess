#ifndef CASTLE_H
#define CASTLE_H

#include "ChessPieces.h"

/******************************************* Castle *******************************************/

class Castle : public ChessPiece {
  
public:

  Castle(color color);
  /* Constructor */

  ~Castle() override;
  /* Destructor */

  bool validMovePiece(const int &source_file, const int &source_rank, const int &destination_file,
		      const int &destination_rank, bool captures_piece) override;
  /* Checks the validity of a particular move for the piece "Castle" */
};

#endif
