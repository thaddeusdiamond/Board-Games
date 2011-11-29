/**
 * @file
 * @author Thaddeus Diamond <diamond@cs.yale.edu>
 * @version 0.1
 * @since 26 Nov 2011
 *
 * @section DESCRIPTION
 *
 * Implementation of the WindowFactory class using Factory DP
 **/

#include "window/window_factory.hpp"

Window* BoardGames::Window::WindowFactory::CreateFromGameType(GameType game) {
  switch (game) {
    case ALL_GAMES:
      return new MainWindow();

    default:
      return GameBuilder::BuildWindowFromGameType(game);
  }

  return NULL;
}

Menu* BoardGames::Window::WindowFactory::CreateGameChoicesMenu(
    MainWindow* window) {
  Menu* options = new Menu();
  for (int i = 0; i < GAMES_AVAILABLE; i++) {
    Button* game_button = new Button(GameTitles[GameTypes[i]]);
    game_button->signal_clicked().connect(
        sigc::bind<GameType>(sigc::mem_fun(*window, &MainWindow::GameSelected),
                             static_cast<GameType>(GameTypes[i])));
    options->pack_start(game_button);
  }

  return options;
}
