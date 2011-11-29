/**
 * @file
 * @author Thaddeus Diamond <diamond@cs.yale.edu>
 * @version 0.1
 * @since 26 Nov 2011
 *
 * @section DESCRIPTION
 *
 * We use the Factory design pattern to achieve modularity in our application
 * design.  The application no longer has to be aware what the game type is
 * or make any context switches.  The factory is responsible for that. 
 **/

#ifndef _BOARDGAMES_WINDOW_WINDOW_FACTORY_HPP_
#define _BOARDGAMES_WINDOW_WINDOW_FACTORY_HPP_

#include "common/types.hpp"
#include "interface/menu.hpp"
#include "window/main_window.hpp"

#include "games/configuration.hpp"
#include "games/game_builder.hpp"

using BoardGames::Types::GameType;
using BoardGames::Interface::Menu;
using BoardGames::Window::Window;
using BoardGames::Window::MainWindow;

using Games::GameBuilder;
using Games::Configuration::ALL_GAMES;
using Games::Configuration::GAMES_AVAILABLE;
using Games::Configuration::GameTypes;

/**
 * @namespace BoardGames
 **/
namespace BoardGames {
  /**
   * @namespace BoardGames::Window
   **/
  namespace Window {
    /**
     * @class WindowFactory
     * @brief A factory for abstractly creating an arbitrary window
     *
     * Based on whether this is the main menu, the game itself, or something
     * else entirely we want the WindowFactory to create the window without
     * the application having to be aware.
     **/
    class WindowFactory {
     public:
      /**
       * The CreateFromGameType() method takes an enumerated
       * @ref Types::GameType and returns which Window should be
       * created based on it.
       *
       * @returns   A pointer to a Window to launch
       **/
      static Window* CreateFromGameType(GameType game);

      /**
       * The CreateGameChoices() creates a set of vectors describing the game
       * choices available to the MainWindow object.  This is not for use
       * with a GameWindow and as such does not accept a GameWindow object
       *
       * @returns   A pointer to a menu to add
       **/
      static Menu* CreateGameChoicesMenu(MainWindow* window);

     private:
      /**
       * The WindowFactory constructor is hidden to comply with the Factory DP
       **/
      explicit WindowFactory() {}

      /**
       * The WindowFactory destructor is hidden because it is simply a Factory
       **/
      ~WindowFactory() {}
    };
  }
}

#endif  // _BOARDGAMES_WINDOW_WINDOW_FACTORY_HPP_
