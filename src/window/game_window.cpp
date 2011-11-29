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

#include "window/game_window.hpp"

BoardGames::Window::GameWindow::GameWindow(string game_title, Game* game)
    : layout_(new VBox()), game_(game) {
  // Every game needs a board, otherwise exit
  if (game->board() == NULL)
    return;

  // Initialize the position of the elements
  if (game->header() != NULL)
    layout_->pack_start(*game->header());
  layout_->pack_start(*game->board());
  if (game->options() != NULL)
    layout_->pack_start(*game->options());

  set_title(game_title);
  set_border_width(WINDOW_PADDING);

  add(*layout_);
  show_all_children();
}

BoardGames::Window::GameWindow::~GameWindow() {
  delete layout_;
  delete game_;
}
