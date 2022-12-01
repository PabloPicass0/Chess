#ifndef CHESSPIECES_H
#define CHESSPIECES_H

#include "color.h"
#include "ChessBoard.h"
#include <string>

/* forward declaration: claims existence of class ChessBoard */
class ChessBoard;

class ChessPiece {
 protected:
  ChessPiece(std::string name, color color);
  std::string pieceName;
  color pieceColor;
  bool pieceHasMoved;
  
 public:
  virtual color get_color();
  virtual std::string get_name();
  virtual std::string get_initials();
  virtual bool validMove(int source_file, int source_rank, int destination_file, int destination_rank, bool captures_piece) = 0;
};

class King : public ChessPiece {
public:
  King(color color);

  bool validMove(const int source_file, const int source_rank, const int destination_file, const int destination_rank, bool captures_piece) override;
};


class Castle : public ChessPiece {
public:
  Castle(color color);
  
  bool validMove(const int source_file, const int source_rank, const int destination_file, const int destination_rank, bool captures_piece) override;
};


class Bishop : public ChessPiece {
public:
  Bishop(color color);

  bool validMove(const int source_file, const int source_rank, const int destination_file, const int destination_rank, bool captures_piece) override;
};


class Queen : public ChessPiece {
public:
  Queen(color color);
  
  bool validMove(const int source_file, const int source_rank, const int destination_file, const int destination_rank, bool captures_piece) override;
};


class Knight : public ChessPiece {
public:
  Knight(color color);
  
  bool validMove(const int source_file, const int source_rank, const int destination_file, const int destination_rank, bool captures_piece) override;
};


class Pawn : public ChessPiece {
public:
  Pawn(color color);
  
  bool validMove(const int source_file, const int source_rank, const int destination_file, const int destination_rank, bool captures_piece) override;
};

#endif
