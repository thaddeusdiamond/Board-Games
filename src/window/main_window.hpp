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
#include <gtkmm/drawingarea.h>
#include <vector>
#include <cstdio>

#include "configuration/configuration.hpp"
#include "window/window.hpp"

using std::vector;
using Gtk::Button;

using BoardGames::Configuration::GameTitles;
using BoardGames::Configuration::GameType;
using BoardGames::Configuration::ALL_GAMES;

/**
 * @namespace BoardGames
 **/
namespace BoardGames {
  /**
   * @class MainWindow
   * @brief The main board game window
   *
   * This is the main screen that allows us to choose which game to play
   **/
  class MainWindow : public BoardGames::Window {
    /** @todo    Add testing to MainWindow class **/
   public:
    /**
     * A constructor for a MainWindow initializes the buttons relevant to
     * that game
     **/
    explicit MainWindow(GameType application_game);

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
    void GameSelected(GameType selected_game);

   private:
    /**
     * The MainWindow keeps track of the drawing area it is painted on
     **/
    Gtk::DrawingArea canvas_;

    /**
     * The MainWindow keeps track of a set of buttons available to be clicked
     * that will launch a specified game
     **/
    vector<Button*> buttons_;
  };
}

#endif  // _BOARDGAMES_WINDOW_MAIN_WINDOW_HPP_