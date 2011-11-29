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

#ifndef _BOARDGAMES_GAMES_CONFIGURATION_HPP_
#define _BOARDGAMES_GAMES_CONFIGURATION_HPP_

#include <string>

#include "common/types.hpp"

using BoardGames::Types::GameType;
using std::string;

/**
 * @namespace Games
 **/
namespace Games {
  /**
   * @namespace Games::Configuration
   * @brief     The current configuration in regards to which games supported
   *
   * Creating a configuration namespace nested inside of the BoardGames
   * framework allows us to create dynamic support for new games and rules
   * without having to rework any existing code.
   **/
  namespace Configuration {
    /**
     * Define how many games are currently available in total.
     **/
    static const int GAMES_AVAILABLE = 2;

    /**
     * We define the available games by an enum that can be easily added to.
     * Runtime switches on pre-defined array stores will determine how windows
     * are initialized.  These will define the choices in those switches.
     **/
    enum {
      TIC_TAC_TOE = 0,
      GOMOKU      = 1,
      ALL_GAMES   = 2,
    };

    /** 
     * Here we also enumerate the game types in an iterable
     * container so that we can make buttons, etc.
     **/
    static const GameType GameTypes[] = { TIC_TAC_TOE, GOMOKU, ALL_GAMES };

    /**
     * We define a static list of window titles based on what option was
     * selected for fast switching
     **/
    static const string GameTitles[] = {
      "Tic-Tac-Toe",
      "Gomoku",
      "All Sorts of Games!",
    };
  }
}

#endif  // _BOARDGAMES_GAMES_CONFIGURATION_HPP_
