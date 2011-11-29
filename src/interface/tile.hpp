/**
 * @file
 * @author Thaddeus Diamond <diamond@cs.yale.edu>
 * @version 0.1
 * @since 26 Nov 2011
 *
 * @section DESCRIPTION
 *
 * Create an individual tile
 **/

#ifndef _BOARDGAMES_INTERFACE_TILE_HPP_
#define _BOARDGAMES_INTERFACE_TILE_HPP_

#include <gtkmm/togglebutton.h>

/**
 * @namespace BoardGames
 **/
namespace BoardGames {
  /**
   * @namespace BoardGames::Interface
   **/
  namespace Interface {
    /**
     * @class Tile
     * @brief The individual game tile
     *
     * This class represents a single tile on the game board (inherited from
     * a standard ToggleButton)
     **/
    class Tile : public Gtk::ToggleButton {
      /** @todo    Add testing to Tile class **/
     public:
      /**
       * The Tile constructor initializes a null tile
       **/
      explicit Tile();

      /**
       * The Tile destructor is responsible for freeing all memory it initialized
       **/
      ~Tile();
    };
  }
}

#endif  // _BOARDGAMES_INTERFACE_TILE_HPP_
