/**
 * @file
 * @author Thaddeus Diamond <diamond@cs.yale.edu>
 * @version 0.1
 * @since 26 Nov 2011
 *
 * @section DESCRIPTION
 *
 * We create a special board game class so we can decorate a traditional
 * GTK window and provide convenient modifier methods.
 **/

#ifndef _BOARDGAMES_WINDOW_GAME_WINDOW_HPP_
#define _BOARDGAMES_WINDOW_GAME_WINDOW_HPP_

#include <gtkmm/box.h>
#include <gtkmm/label.h>
#include <string>

#include "window/window.hpp"
#include "games/game.hpp"

using std::string;
using Gtk::Label;
using Gtk::VBox;
using Games::Game;

/**
 * @namespace BoardGames
 **/
namespace BoardGames {
  /**
   * @namespace BoardGames::Window
   **/
  namespace Window {
    /**
     * @class GameWindow
     * @brief An actual game window
     *
     * This is the game board that allows us to actually play a game
     **/
    class GameWindow : public BoardGames::Window::Window {
      /** @todo    Add testing to GameWindow class **/
     public:
      /**
       * A constructor for a GameWindow initializes the objects relevant to
       * that game
       **/
      GameWindow(string game_title, Game* game);

      /**
       * The MainWindow destructor is responsible for freeing all widgets it
       * allocated during its lifecycle
       **/
      virtual ~GameWindow();

     private:
      /**
       * The game's layout is represented as a vertical box layout
       **/
      VBox* layout_;

      /**
       * Every game window must include the actual game object
       **/
      Game* game_;
    };
  }
}

#endif  // _BOARDGAMES_WINDOW_GAME_WINDOW_HPP_
