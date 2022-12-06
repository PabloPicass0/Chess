#ifndef CHESSPIECES_H
#define CHESSPIECES_H

#include "color.h"
#include "ChessBoard.h"
#include <string>

/* forward declaration: claims existence of class ChessBoard */
class ChessBoard;

/**************************************** ChessPiece ************************************/

class ChessPiece {
 protected:
  ChessPiece(std::string name, color color);
  std::string pieceName;
  color pieceColor;
  bool pieceHasMoved;
  
 public:
  virtual ~ChessPiece() {};
  virtual color get_color();
  virtual std::string get_name();
  virtual std::string get_initials();
  virtual void set_pieceHasMoved();
  virtual bool validMove(int source_file, int source_rank, int destination_file, int destination_rank, bool captures_piece) = 0;
};

/**************************************** King *****************************************/

class King : public ChessPiece {
public:
  King(color color);
  ~King() override;

  bool validMove(const int source_file, const int source_rank, const int destination_file, const int destination_rank, bool captures_piece) override;
};

/**************************************** Castle ***************************************/

class Castle : public ChessPiece {
public:
  Castle(color color);
  ~Castle() override;
  
  bool validMove(const int source_file, const int source_rank, const int destination_file, const int destination_rank, bool captures_piece) override;
};

/**************************************** Bishop ***************************************/

class Bishop : public ChessPiece {
public:
  Bishop(color color);
  ~Bishop() override;

  bool validMove(const int source_file, const int source_rank, const int destination_file, const int destination_rank, bool captures_piece) override;
};

/**************************************** Queen ****************************************/

class Queen : public ChessPiece {
public:
  Queen(color color);
  ~Queen() override;
  
  bool validMove(const int source_file, const int source_rank, const int destination_file, const int destination_rank, bool captures_piece) override;
};

/**************************************** Knight ***************************************/

class Knight : public ChessPiece {
public:
  Knight(color color);
  ~Knight() override;
  
  bool validMove(const int source_file, const int source_rank, const int destination_file, const int destination_rank, bool captures_piece) override;
};

/**************************************** Pawn ****************************************/

class Pawn : public ChessPiece {
public:
  Pawn(color color);
  ~Pawn() override;
  
  bool validMove(const int source_file, const int source_rank, const int destination_file, const int destination_rank, bool captures_piece) override;
};

#endif
