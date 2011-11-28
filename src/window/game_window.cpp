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

BoardGames::GameWindow::GameWindow(string game_title, Label* header,
                                   Board* board, Menu* options)
    : layout_(new VBox()), header_(header), board_(board), options_(options) {
  // Every game needs a board, otherwise exit
  if (board_ == NULL)
    return;

  // Initialize the position of the elements
  if (header_ != NULL)
    layout_->pack_start(*header_);
  layout_->pack_start(*board_);
  if (options_ != NULL)
    layout_->pack_start(*options_);

  set_title(game_title);
  set_border_width(WINDOW_PADDING);

  add(*layout_);
  show_all_children();
}

BoardGames::GameWindow::~GameWindow() {
  delete board_;
  delete layout_;
  delete header_;
  delete options_;
}
