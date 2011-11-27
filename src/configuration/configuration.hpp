/**
 * @file
 * @author Thaddeus Diamond <diamond@cs.yale.edu>
 * @version 0.1
 * @since 26 Nov 2011
 *
 * @section DESCRIPTION
 *
 * This header file defines the given configuration of the system based
 * on what has been coded (which games, etc.)
 **/

#ifndef _BOARDGAMES_CONFIGURATION_CONFIGURATION_HPP_
#define _BOARDGAMES_CONFIGURATION_CONFIGURATION_HPP_

#include <string>

using std::string;

/**
 * @namespace BoardGames
 **/
namespace BoardGames {
  /**
   * @namespace BoardGames::Configuration
   * @brief     The current configuration in regards to which games supported
   *
   * Creating a configuration namespace nested inside of the BoardGames
   * framework allows us to create dynamic support for new games and rules
   * without having to rework any existing code.
   **/
  namespace Configuration {
    /**
     * @enum GameType
     *
     * We define the available games by an enum that can be easily added to.
     * Runtime switches on pre-defined array stores will determine how windows
     * are initialized.  These will define the choices in those switches.
     **/
    enum GameType {
      TIC_TAC_TOE = 0,
      SUDOKU      = 1,
      ALL_GAMES   = 2,
    };

    /** @todo Here we should also enumerate the game types in an iterable
     *        container so that we can make buttons, etc. **/

    /**
     * We define a static list of window titles based on what option was
     * selected for fast switching
     **/
    static const string GameTitles[] = {
      "Tic-Tac-Toe",
      "Sudoku",
      "All Sorts of Games!",
    };

    /**
     * The maximum number of windows we want to be open at any given time.
     **/
    static const int MAXIMUM_WINDOWS = 10;

    /**
     * Declare the maximum number of buttons any Window can have as a final (10)
     **/
    /// @todo REMOVE THIS -- static const int MAXIMUM_BUTTONS = 10;
  }
}

#endif  // _BOARDGAMES_CONFIGURATION_CONFIGURATION_HPP_
