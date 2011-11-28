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

#include "application/application.hpp"
#include "window/main_window.hpp"
#include "games/game_factory.hpp"
#include "window/window_factory.hpp"

using BoardGames::GameFactory;
using BoardGames::WindowFactory;

BoardGames::MainWindow::MainWindow() {
  // Set the basics up
  set_title("Board Game Demo");
  set_border_width(WINDOW_PADDING);

  // Retrieve the total games from the generic GameFactory
  buttons_ = GameFactory::CreateGameChoices(this);

  vertical_layout_ = new VBox();
  vertical_layout_->set_size_request(300, (buttons_.size() + 1) * 50);

  // Set the program header
  header_label_ = new Label("Please Select A Game...");
  vertical_layout_->pack_start(*header_label_);

  // Add the buttons to select the correct games
  vector<Button*>::iterator it;
  for (it = buttons_.begin(); it < buttons_.end(); it++) {
    vertical_layout_->pack_start(**it);
    (*it)->show();
  }

  add(*vertical_layout_);
  show_all_children();
}

BoardGames::MainWindow::~MainWindow() {
  delete vertical_layout_;
  delete header_label_;
  vector<Button*>::iterator it;
  for (it = buttons_.begin(); it < buttons_.end(); it++)
    delete (*it);
}

void BoardGames::MainWindow::GameSelected(GameType selected_game) {
  BoardGames::Application::GetApplicationInstance()->add_window(
    WindowFactory::CreateFromGameType(selected_game));
}
