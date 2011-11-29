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

#ifndef _BOARDGAMES_WINDOW_MAIN_WINDOW_HPP_
#define _BOARDGAMES_WINDOW_MAIN_WINDOW_HPP_

#include <gtkmm/button.h>
#include <gtkmm/box.h>
#include <gtkmm/label.h>
#include <vector>

#include "common/types.hpp"
#include "window/window.hpp"

using std::vector;
using Gtk::Button;
using Gtk::VBox;
using Gtk::Label;

using BoardGames::Types::GameType;

/**
 * @namespace BoardGames
 **/
namespace BoardGames {
  /**
   * @namespace BoardGames::Window
   **/
  namespace Window {
    /**
     * @class MainWindow
     * @brief The main board game window
     *
     * This is the main screen that allows us to choose which game to play
     **/
    class MainWindow : public BoardGames::Window::Window {
      /** @todo    Add testing to MainWindow class **/
     public:
      /**
       * A constructor for a MainWindow initializes the buttons relevant to
       * that game
       **/
      explicit MainWindow();

      /**
       * The MainWindow destructor is responsible for freeing all widgets it
       * allocated during its lifecycle
       **/
      virtual ~MainWindow();

      /**
       * When a specified button is clicked, handle the event
       *
       * @param   selected_game   Which button was selected/what game to launch
       **/
      virtual void GameSelected(GameType selected_game);

     private:
      /**
       * The MainWindow keeps a vertical box layout to position buttons
       **/
      VBox* vertical_layout_;

      /**
       * The MainWindow keeps a label describing the games available
       **/
      Label* header_label_;

      /**
       * The MainWindow keeps track of a set of buttons available to be clicked
       * that will launch a specified game
       **/
      vector<Button*> buttons_;
    };
  }
}

#endif  // _BOARDGAMES_WINDOW_MAIN_WINDOW_HPP_
