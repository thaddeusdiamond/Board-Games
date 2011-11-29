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
     * The EndGame() method describes clean-up to be performed when the game is
     * over
     **/
    virtual void EndGame() = 0;
  };
}

#endif  // _BOARDGAMES_GAMES_GAME_HPP_
