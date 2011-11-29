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

using BoardGames::Interface::Tile;

/**
 * @namespace BoardGames
 **/
namespace BoardGames {
  /**
   * @namespace BoardGames::Interface
   * @brief     A namespace for holding interface components on a window
   *
   * The interface namespace defines a set of interface components derived from
   * the standard GTKMM library that control the output of the game on the
   * screen
   **/
  namespace Interface {
    /**
     * @class Board
     * @brief The physical game board
     *
     * This is the game board with tiles arranged on it
     **/
    class Board : public Gtk::Table {
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
}

#endif  // _BOARDGAMES_INTERFACE_BOARD_HPP_
