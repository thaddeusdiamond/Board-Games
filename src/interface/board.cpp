/**
 * @file
 * @author Thaddeus Diamond <diamond@cs.yale.edu>
 * @version 0.1
 * @since 26 Nov 2011
 *
 * @section DESCRIPTION
 *
 * Implement the game board
 **/

#include "interface/board.hpp"

BoardGames::Interface::Board::Board(int rows, int cols, int height, int width)
    : rows_(rows), cols_(cols) {
  tiles_ = new Tile**[rows_];
  for (int i = 0; i < rows_; i++) {
    tiles_[i] = new Tile*[cols_];
    for (int j = 0; j < cols_; j++) {
      tiles_[i][j] = new Tile();
      attach(*tiles_[i][j], i, i + 1, j, j + 1);
      tiles_[i][j]->set_size_request(width / cols, height / rows);
    }
  }
}

BoardGames::Interface::Board::~Board() {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++)
      delete tiles_[i][j];
    delete[] tiles_[i];
  }

  delete[] tiles_;
}

Tile* BoardGames::Interface::Board::tile(int row, int col) {
  if (row >= rows_ || col >= cols_)
    return NULL;

  return tiles_[row][col];
}
