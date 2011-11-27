/**
 * @file
 * @author Thaddeus Diamond <diamond@cs.yale.edu>
 * @version 0.1
 * @since 26 Nov 2011
 *
 * @section DESCRIPTION
 *
 * Implementation of a game's main window
 **/

#include "window/main_window.hpp"

using BoardGames::MainWindow;

MainWindow::MainWindow(GameType game) {
  // Set basic trimmings (height, width, border, yada yada...)
  set_title(BoardGames::Configuration::GameTitles[game]);
  set_border_width(10);
  /** @todo Deal with canvas next and set size:
   *     m_canvas.set_size_request(game == ALL_GAMES ? 300 : 100, 400);
   **/

  // Add the buttons to select the correct games
  if (game == ALL_GAMES)
    buttons_.insert(new Button("Hello, World"));

  set<Button*>::iterator it;
  for (it = buttons_.begin(); it != buttons_.end(); it++) {
    add(**it);
    (*it)->show();
  }
}

MainWindow::~MainWindow() {
  set<Button*>::iterator it;
  for (it = buttons_.begin(); it != buttons_.end(); it++)
    delete *it;
}
