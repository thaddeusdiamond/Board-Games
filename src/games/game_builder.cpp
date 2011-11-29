/**
 * @file
 * @author Thaddeus Diamond <diamond@cs.yale.edu>
 * @version 0.1
 * @since 26 Nov 2011
 *
 * @section DESCRIPTION
 *
 * Implementation for the GameBuilder's DP
 **/

#include "games/game_builder.hpp"

GameWindow* Games::GameBuilder::BuildWindowFromGameType(
    GameType game_type) {
  Game* game;
  switch (game_type) {
    // The following lines are responsible for creating the Gomoku game
    // board and initializing the set of rules it is responsible for.
    // See http://en.wikipedia.org/wiki/Gomoku for an explanation of the game
    case GOMOKU:
      game = new Gomoku();
      break;

    // The following lines are responsible for creating the Tic-Tac-Toe game
    // board and initializing the set of rules it is responsible for.
    // See http://en.wikipedia.org/wiki/Tic-Tac-Toe for an explanation of game
    case TIC_TAC_TOE:
      game = new TicTacToe();
      break;

    default:
      return NULL;
  }

  return new GameWindow(GameTitles[game_type], game);
}
