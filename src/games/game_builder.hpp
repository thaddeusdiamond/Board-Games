/**
 * @file
 * @author Thaddeus Diamond <diamond@cs.yale.edu>
 * @version 0.1
 * @since 26 Nov 2011
 *
 * @section DESCRIPTION
 *
 * We create a special board builder so that we don't have to change the
 * actual GameWindow based on our configuration file.  This builder uses
 * fast switching to create game specific boards and tiles.
 **/

#ifndef _BOARDGAMES_GAMES_GAME_BUILDER_HPP_
#define _BOARDGAMES_GAMES_GAME_BUILDER_HPP_

#include <gtkmm/label.h>
#include <gtkmm/button.h>

#include "common/types.hpp"
#include "common/configuration.hpp"
#include "interface/board.hpp"
#include "interface/menu.hpp"
#include "window/game_window.hpp"

using Gtk::VBox;
using Gtk::Button;
using BoardGames::Board;
using BoardGames::Menu;

using BoardGames::GameWindow;
using BoardGames::Configuration::GameTitles;
using BoardGames::Configuration::TIC_TAC_TOE;
using BoardGames::Configuration::SUDOKU;

/**
 * @namespace BoardGames
 **/
namespace BoardGames {
  /**
   * @class GameBuilder
   * @brief Game window builder
   *
   * We use the Builder DP to modularize our ability to create a simple game.
   * Since this is the only aspect of the building process that uses
   * the configuration file, we don't need to put the configuration file
   * into the window or board classes.
   **/
  class GameBuilder {
   public:
    /**
     * The BuildWindowFromGameType() method takes a game type enumerated in
     * Configuration:: and generates the proper parts for
     * the game window
     *
     * @param     game    The game type to be initialized
     *
     * @returns   The fully initialized GameWindow object
     **/
    static GameWindow* BuildWindowFromGameType(GameType game);

   private:
    /**
     * The GameBuilder constructor is hidden to comply with the Builder DP
     **/
    explicit GameBuilder() {}

    /**
     * The GameBuilder destructor is hidden because it is simply a Builder
     **/
    ~GameBuilder() {}
  };
}

#endif  // _BOARDGAMES_GAMES_GAME_BUILDER_HPP_
