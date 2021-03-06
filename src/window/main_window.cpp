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
#include "application/application.hpp"
#include "window/window_factory.hpp"

using BoardGames::Window::WindowFactory;

BoardGames::Window::MainWindow::MainWindow() {
  // Set the basics up
  set_title("Board Game Demo");
  set_border_width(WINDOW_PADDING);

  // Retrieve the total games from the generic GameFactory
  options_ = WindowFactory::CreateGameChoicesMenu(this);

  vertical_layout_ = new VBox();
  vertical_layout_->set_size_request(300, (options_->length() + 1) * 50);

  // Set the program header
  header_label_ = new Label("Please Select A Game...");
  vertical_layout_->pack_start(*header_label_);
  vertical_layout_->pack_start(*options_);

  add(*vertical_layout_);
  show_all_children();
}

BoardGames::Window::MainWindow::~MainWindow() {
  delete vertical_layout_;
  delete header_label_;
  delete options_;
}

void BoardGames::Window::MainWindow::GameSelected(GameType selected_game) {
  BoardGames::Application::Application::GetApplicationInstance()->add_window(
    WindowFactory::CreateFromGameType(selected_game));
}
