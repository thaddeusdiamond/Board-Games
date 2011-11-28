/**
 * @file
 * @author Thaddeus Diamond <diamond@cs.yale.edu>
 * @version 0.1
 * @since 26 Nov 2011
 *
 * @section DESCRIPTION
 *
 * Define a game board as an arbitrary m x n set of tiles.
 **/

#ifndef _BOARDGAMES_INTERFACE_BOARD_HPP_
#define _BOARDGAMES_INTERFACE_BOARD_HPP_

#include <gtkmm/table.h>
#include "interface/tile.hpp"

using Gtk::Table;
using BoardGames::Tile;

/**
 * @namespace BoardGames
 **/
namespace BoardGames {
  /**
   * @class Board
   * @brief The physical game board
   *
   * This is the game board with tiles arranged on it
   **/
  /// @todo If there's time, should we make one more level for namespaces?
  ///       It would be based on the folder...
  class Board : public Table {
    /** @todo    Add testing to Board class **/
   public:
    /**
     * The board constructor initializes a set of WxH widgets arranged
     * in a grid of width and height specified
     **/
    explicit Board(int rows, int cols, int height, int width);

    /**
     * The board destructor is responsible for freeing all tiles it created
     **/
    ~Board();

    /**
     * Accessor method for tiles on a board
     *
     * @param   row     Row location of the tile
     * @param   col     Column location of the tile
     *
     * @returns A pointer to the tile if it exists, NULL otherwise
     **/
    Tile* tile(int row, int col);

   private:
    /**
     * We represent the Tiles as a 2-D array of Tile pointers
     **/
    Tile*** tiles_;

    /**
     * Maintain how many tiles high this board is
     **/
    int rows_;

    /**
     * Maintain how many tiles wide this board is
     **/
    int cols_;
  };
}

#endif  // _BOARDGAMES_INTERFACE_BOARD_HPP_
