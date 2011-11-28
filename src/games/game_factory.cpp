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

#include "games/game_factory.hpp"

vector<Button*> BoardGames::GameFactory::CreateGameChoices(MainWindow* window) {
  vector<Button*> options;
  for (int i = 0; i < GAMES_AVAILABLE; i++) {
    Button* game_button = new Button(GameTitles[GameTypes[i]]);
    game_button->signal_clicked().connect(
        sigc::bind<GameType>(sigc::mem_fun(*window, &MainWindow::GameSelected),
                             static_cast<GameType>(GameTypes[i])));
    options.push_back(game_button);
  }

  return options;
}
