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

MainWindow::MainWindow(GameType application_game) : canvas_() {
  // Set basic trimmings (height, width, border, yada yada...)
  set_title(BoardGames::Configuration::GameTitles[application_game]);
  set_border_width(10);
//  canvas_.set_size_request(application_game == ALL_GAMES ? 300 : 100, 400);

  // Add the buttons to select the correct games
  for (int game = 0; game < static_cast<int>(ALL_GAMES); game++) {
    if (game == static_cast<int>(application_game) ||
        application_game == ALL_GAMES) {
      Button* game_button = new Button(GameTitles[game].c_str());
      game_button->signal_clicked().connect(
          sigc::bind<GameType>(sigc::mem_fun(*this, &MainWindow::GameSelected),
                               static_cast<GameType>(game)));

      /** @todo Here we need to use pack_start and a GtkBox **/
      buttons_.push_back(game_button);
      add(*game_button);
    }
  }

  show_all_children();
}

MainWindow::~MainWindow() {}

void MainWindow::GameSelected(GameType selected_game) {
  Window* dead_window = new Window();
  dead_window->set_title(GameTitles[selected_game]);
  dead_window->show();
}
