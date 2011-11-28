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

GameWindow* BoardGames::GameBuilder::BuildWindowFromGameType(GameType game) {
  /// @todo Improve the game's construction
  /// @todo Put in actual gameplay via modularized Strategy DP
  Label *header,
        *filler = new Label();
  Board* board;
  Button *new_game_button, *restart_button;
  VBox* options;

  switch (game) {
    case SUDOKU:
      header = new Label("Select Square to Guess...");   // Initial board header
      board = new Board(9, 9, 360, 360);                 // 3x3 (360px by 360px)
      options = new VBox();
      options->pack_start(*filler);

      /// @bug This is going to leak the button memory, we should create a
      ///      wrapper for the VBox and call it "Menu" or something
      restart_button = new Button("Restart This Game");
      options->pack_start(*restart_button);

      new_game_button = new Button("Start New Game");
      options->pack_start(*new_game_button);

      break;

    case TIC_TAC_TOE:
      header = new Label("Player 1 Make Your Move...");  // Initial board header
      board = new Board(3, 3, 270, 270);                 // 3x3 (360px by 360px)
      options = new VBox();
      options->pack_start(*filler);

      new_game_button = new Button("Start New Game");
      options->pack_start(*new_game_button);

      break;

    default:
      return NULL;
  }

  header->set_size_request(300, 50);
  filler->set_size_request(300, 25);

  return new GameWindow(GameTitles[game], header, board, options);
}
