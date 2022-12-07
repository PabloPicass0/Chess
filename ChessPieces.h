#ifndef CHESSPIECES_H
#define CHESSPIECES_H

#include "color.h"
#include "pieceType.h"
#include "ChessBoard.h"
#include <string>

/* forward declaration: claims existence of class ChessBoard */
class ChessBoard;

/**************************************** ChessPiece ************************************/

class ChessPiece {
 protected:
  ChessPiece(type type, color color);
  //std::string pieceName;
  type pieceType;
  color pieceColor;
  std::string pieceIcon;
  bool pieceHasMoved;
  
 public:
  virtual ~ChessPiece() {};
  virtual color get_color();
  //virtual std::string get_name();
  virtual std::string get_icon();
  virtual type get_type();
  //virtual std::string get_initials();
  virtual void set_pieceHasMoved();
  virtual bool validMovePiece(const int &source_file, const int &source_rank, const int &destination_file, const int &destination_rank, bool captures_piece) = 0;
};

/**************************************** King *****************************************/

class King : public ChessPiece {
public:
  King(color color);
  ~King() override;

  bool validMovePiece(const int &source_file, const int &source_rank, const int &destination_file, const int &destination_rank, bool captures_piece) override;
};


/**************************************** Castle ***************************************/

class Castle : public ChessPiece {
public:
  Castle(color color);
  ~Castle() override;
  
  bool validMovePiece(const int &source_file, const int &source_rank, const int &destination_file, const int &destination_rank, bool captures_piece) override;
};

/**************************************** Bishop ***************************************/

class Bishop : public ChessPiece {
public:
  Bishop(color color);
  ~Bishop() override;

  bool validMovePiece(const int &source_file, const int &source_rank, const int &destination_file, const int &destination_rank, bool captures_piece) override;
};

/**************************************** Queen ****************************************/

class Queen : public ChessPiece {
public:
  Queen(color color);
  ~Queen() override;
  
  bool validMovePiece(const int &source_file, const int &source_rank, const int &destination_file, const int &destination_rank, bool captures_piece) override;
};

/**************************************** Knight ***************************************/

class Knight : public ChessPiece {
public:
  Knight(color color);
  ~Knight() override;
  
  bool validMovePiece(const int &source_file, const int &source_rank, const int &destination_file, const int &destination_rank, bool captures_piece) override;
};

/**************************************** Pawn ****************************************/

class Pawn : public ChessPiece {
public:
  Pawn(color color);
  ~Pawn() override;
  
  bool validMovePiece(const int &source_file, const int &source_rank, const int &destination_file, const int &destination_rank, bool captures_piece) override;
};

#endif
