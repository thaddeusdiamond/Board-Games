/**
 * @file
 * @author Thaddeus Diamond <diamond@cs.yale.edu>
 * @version 0.1
 * @since 26 Nov 2011
 *
 * @section DESCRIPTION
 *
 * This file defines an interface to a game.  This is what the application
 * developer is responsible for.
 **/

#ifndef _BOARDGAMES_GAMES_GAME_HPP_
#define _BOARDGAMES_GAMES_GAME_HPP_

#include <gtkmm/label.h>
#include <gtkmm/table.h>
#include <gtkmm/box.h>

using Gtk::Label;
using Gtk::Table;
using Gtk::VBox;

/**
 * @namespace Games
 **/
namespace Games {
  /**
   * @class Game
   * @brief Abstract class representing a game
   *
   * We use the Strategy DP to represent one game as the ultimate superclass
   * and then have all subclasses use virtual methods to create a runtime
   * dispatchable selection of which game we'd like to play.
   **/
  class Game {
   public:
    /**
     * The Game destructor must free all memory it has aggregated.
     **/
    virtual ~Game() {}

    /**
     * The OnTileClicked() method is responsible for handling tile feedback
     * and dispatching it to update the game state.
     *
     * @param       row     The row of the tile pressed
     * @param       col     The column of the tile pressed
     **/
    virtual void OnTileClicked(int row, int col) = 0;

    /**
     * The CompleteTurn() method signals the end of the current player's turn
     * and allows the game to notify all necessary components of that end
     **/
    virtual void CompleteTurn() = 0;

    /**
     * Every game must implement a ClearTheBoard() method so that the user can
     * restart the game without having to reset the whole set of options
     * Although it can't strictly be enforced that one of the options actually
     * link to this, it is a recommended practice that you do this.
     **/
    virtual void ClearTheBoard() = 0;

    /**
     * Accessor method for the game's header (can be NULL)
     **/
    virtual Label* header() = 0;

    /**
     * Accessor method for the game's board (can NOT be NULL)
     **/
    virtual Table* board() = 0;

    /**
     * Accessor method for the game's options menu (can be NULL)
     **/
    virtual VBox* options() = 0;
  };
}

#endif  // _BOARDGAMES_GAMES_GAME_HPP_
