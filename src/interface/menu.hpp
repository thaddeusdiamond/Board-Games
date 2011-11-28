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
#include <vector>

using std::vector;

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
  /// @todo   Dude, you gotta implement a version of this from the GameBuilder
  class Menu : public Gtk::VBox {
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

    /**
     * pack_start() behaves exactly as the VBox's version does, with the
     * caveat that it aggregates the widget into a container so that it can
     * be freed in the destructor.  For our purposes we ignore the options
     * and padding that are specified in the superclass method.
     *
     * @param     child       The child widget to be added to the menu
     **/
    void pack_start(Widget* child);

   private:
    /**
     * In order to properly free the memory when destructed, the menu
     * aggregates all of it's widgets (buttons, etc.)
     **/
    vector<Widget*> widgets_;
  };
}

#endif  // _BOARDGAMES_INTERFACE_MENU_HPP_
