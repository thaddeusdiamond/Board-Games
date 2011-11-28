/**
 * @file
 * @author Thaddeus Diamond <diamond@cs.yale.edu>
 * @version 0.1
 * @since 26 Nov 2011
 *
 * @section DESCRIPTION
 *
 * Create a menu with in-game options
 **/

#ifndef _BOARDGAMES_INTERFACE_MENU_HPP_
#define _BOARDGAMES_INTERFACE_MENU_HPP_

#include <gtkmm/box.h>

using Gtk::VBox;

/**
 * @namespace BoardGames
 **/
namespace BoardGames {
  /**
   * @class Menu
   * @brief A set of in-game options
   *
   * This class represents the in-game options listed below the main game
   * board
   **/
  class Menu : public VBox {
    /** @todo    Add testing to Menu class **/
   public:
    /**
     * The Menu constructor initializes a null tile
     **/
    explicit Menu();

    /**
     * The Menu destructor is responsible for freeing all memory it initialized
     **/
    ~Menu();
  };
}

#endif  // _BOARDGAMES_INTERFACE_MENU_HPP_
