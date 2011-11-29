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
  /// @todo Put in actual gameplay via modularized Strategy DP
  Game* game;
  Label *header, *filler;
  Board* board;
  Button *new_game_button, *restart_button;
  Menu* options;

  switch (game_type) {
    // The following lines are responsible for creating the Gomoku game
    // board and initializing the set of rules it is responsible for.
    // See http://en.wikipedia.org/wiki/Gomoku for an explanation of the game
    case GOMOKU:
      header = new Label("Player 1 Make Your Move...");  // Initial board header
      board = new Board(15, 15, 360, 360);               // 3x3 (360px by 360px)
      options = new Menu();
      game = new Gomoku(board, header);

      filler = new Label();
      options->pack_start(filler);

      restart_button = new Button("Restart This Game");
      options->pack_start(restart_button);

      new_game_button = new Button("Start New Game");
      options->pack_start(new_game_button);

      break;

    // The following lines are responsible for creating the Tic-Tac-Toe game
    // board and initializing the set of rules it is responsible for.
    // See http://en.wikipedia.org/wiki/Tic-Tac-Toe for an explanation of game
    case TIC_TAC_TOE:
      header = new Label("Player 1 Make Your Move...");  // Initial board header
      board = new Board(3, 3, 270, 270);                 // 3x3 (360px by 360px)
      options = new Menu();
      game = new TicTacToe(board, header);

      filler = new Label();
      options->pack_start(filler);

      new_game_button = new Button("Start New Game");
      options->pack_start(new_game_button);

      break;

    default:
      return NULL;
  }

  if (!board->AttachTileHandlers(game))
    return NULL;

  header->set_size_request(300, 50);
  filler->set_size_request(300, 25);

  return new GameWindow(GameTitles[game_type], header, board, options);
}
