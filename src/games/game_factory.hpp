/**
 * @file
 * @author Thaddeus Diamond <diamond@cs.yale.edu>
 * @version 0.1
 * @since 26 Nov 2011
 *
 * @section DESCRIPTION
 *
 * We use the Factory design pattern to achieve modularity in our application
 * design.  The application no longer has to be aware of the configuration of
 * the available games.  It merely calls the game factory and receives the
 * appropriate window decorations.
 **/

#ifndef _BOARDGAMES_GAMES_GAME_FACTORY_HPP_
#define _BOARDGAMES_GAMES_GAME_FACTORY_HPP_

#include <gtkmm/button.h>
#include <vector>

#include "common/types.hpp"
#include "common/configuration.hpp"
#include "window/main_window.hpp"

using std::vector;
using Gtk::Button;
using BoardGames::MainWindow;
using BoardGames::Types::GameType;

using BoardGames::Configuration::GameTypes;
using BoardGames::Configuration::GameTitles;
using BoardGames::Configuration::GAMES_AVAILABLE;

/**
 * @namespace BoardGames
 **/
namespace BoardGames {
  /**
   * @class GameFactory
   * @brief A factory for abstractly creating game resources
   *
   * Based on what games are supported (as specified in
   * common/configuration.hpp), various game resources will be returned to the
   * window at runtime.
   **/
  class GameFactory {
   public:
    /**
     * The CreateGameChoices() creates a set of vectors describing the game
     * choices available to the MainWindow object.
     **/
    static vector<Button*> CreateGameChoices(MainWindow* window);

   private:
    /**
     * The GameFactory constructor is hidden to comply with the Factory DP
     **/
    explicit GameFactory() {}

    /**
     * The GameFactory destructor is hidden because it is simply a Factory
     **/
    ~GameFactory() {}
  };
}

#endif  // _BOARDGAMES_GAMES_GAME_FACTORY_HPP_
