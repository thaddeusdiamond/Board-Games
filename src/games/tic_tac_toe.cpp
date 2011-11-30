/**
 * @file
 * @author Thaddeus Diamond <diamond@cs.yale.edu>
 * @version 0.1
 * @since 26 Nov 2011
 *
 * @section DESCRIPTION
 *
 * This file defines a quick implementation of TicTacToe
 **/

#include "games/tic_tac_toe.hpp"

void Games::SampleGames::TicTacToe::CreateBoard() {
  board_ = new Board(3, 3, 270, 270);
  if (!board_->AttachTileHandlers(this))
    exit(EXIT_FAILURE);     /// @todo Use Die Macro
}

void Games::SampleGames::TicTacToe::CreateMenu() {
  Label* filler = new Label();
  filler->set_size_request(300, 25);

  Button* new_game_button = new Button("Start New Game");
  new_game_button->signal_clicked().connect(
      sigc::mem_fun(this, &Game::ClearTheBoard));

  options_ = new Menu();
  options_->pack_start(filler);
  options_->pack_start(new_game_button);
}

void Games::SampleGames::TicTacToe::CreateHeader() {
  header_ = new Label();
  header_->set_text(INITIAL_DIRECTIVE);
  header_->set_size_request(300, 50);
}

void Games::SampleGames::TicTacToe::OnTileClicked(int row, int col) {
  // Don't do anything if we're resetting the game
  if (game_state_ == RESETTING)
    return;

  Tile* tile_pressed = board_->tile(row, col);
  board_state_[row][col] = player_;

  // Mark the tile and inactivate it
  tile_pressed->set_label(PLAYER_MARK[player_]);
  tile_pressed->set_sensitive(false);

  // Make it a little prettier
  tile_pressed->modify_bg(Gtk::STATE_INSENSITIVE, Color(PLAYER_COLOR[player_]));

  CompleteTurn();
}

void Games::SampleGames::TicTacToe::CompleteTurn() {
  // Row-wise check
  for (int i = 0; i < board_->height(); i++) {
    Player initial_player = board_state_[i][0];

    set<Tile*> winning_tiles;
    winning_tiles.insert(board_->tile(i, 0));

    int j;
    for (j = 1; j < board_->width(); j++) {
      if (board_state_[i][j] != initial_player)
        break;
      else
        winning_tiles.insert(board_->tile(i, j));
    }

    if (initial_player != NEITHER && j == board_->width())
      EndGame(winning_tiles);
  }

  // Column-wise check
  for (int i = 0; i < board_->width(); i++) {
    Player initial_player = board_state_[0][i];

    set<Tile*> winning_tiles;
    winning_tiles.insert(board_->tile(0, i));

    int j;
    for (j = 1; j < board_->height(); j++) {
      if (board_state_[j][i] != initial_player)
        break;
      else
        winning_tiles.insert(board_->tile(j, i));
    }

    if (initial_player != NEITHER && j == board_->height())
      EndGame(winning_tiles);
  }

  // Diagonal-check (R to L)
  int i;
  Player initial_player = board_state_[0][0];
  set<Tile*> winning_tiles;
  winning_tiles.insert(board_->tile(0, 0));

  for (i = 1; i < board_->width(); i++) {
    if (board_state_[i][i] != initial_player)
      break;
    else
      winning_tiles.insert(board_->tile(i, i));
  }
  if (initial_player != NEITHER && i == board_->height())
    EndGame(winning_tiles);

  // Diagonal-check (L to R)
  initial_player = board_state_[board_->width() - 1][0];
  winning_tiles.clear();
  winning_tiles.insert(board_->tile(board_->width() - 1, 0));

  for (i = 1; i < board_->width(); i++) {
    if (board_state_[board_->width() - i - 1][i] != initial_player)
      break;
    else
      winning_tiles.insert(board_->tile(board_->width() - i - 1, i));
  }
  if (initial_player != NEITHER && i == board_->height())
    EndGame(winning_tiles);

  // Update the game state
  if (game_state_ != GAME_OVER) {
    player_ = (player_ + 1) % NUMBER_OF_PLAYERS;
    game_state_ = (game_state_ + 1) % NUMBER_OF_PLAYERS;
  }

  // Draw?
  bool draw = true;
  for (int i = 0; i < board_->height(); i++) {
    for (int j = 0; j < board_->width(); j++) {
      if (board_state_[i][j] == NEITHER)
        draw = false;
    }
  }

  if (game_state_ != GAME_OVER && draw)
    header_->set_text(DRAW_DIRECTIVE);
  else
    header_->set_text(PLAYER_NAME[player_] + PLAYER_DIRECTIVE[game_state_]);
}

void Games::SampleGames::TicTacToe::EndGame(set<Tile*> winning_tiles) {
  // White out any tiles selected, but not on the winning path
  for (int i = 0; i < board_->height(); i++) {
    for (int j = 0; j < board_->width(); j++) {
      if (board_state_[i][j] != NEITHER &&
          winning_tiles.find(board_->tile(i, j)) == winning_tiles.end())
        board_->tile(i, j)->modify_bg(Gtk::STATE_INSENSITIVE, Color("gray"));
    }
  }

  // Game's over, no more moves allowed
  for (int i = 0; i < board_->height(); i++) {
    for (int j = 0; j < board_->width(); j++)
      board_->tile(i, j)->set_sensitive(false);
  }

  game_state_ = GAME_OVER;
}

void Games::SampleGames::TicTacToe::ClearTheBoard() {
  game_state_ = RESETTING;
  header_->set_text(PLAYER_DIRECTIVE[game_state_]);

  // Reset the tile characteristics and abstract board state
  player_ = PLAYER_ONE;
  for (int i = 0; i < board_->height(); i++) {
    for (int j = 0; j < board_->width(); j++) {
      board_->tile(i, j)->set_active(false);
      board_->tile(i, j)->set_sensitive(true);
      board_->tile(i, j)->set_label("");
      board_->tile(i, j)->modify_bg(Gtk::STATE_INSENSITIVE, Color(NULL));
      board_state_[i][j] = NEITHER;
    }
  }

  game_state_ = PLAYER_ONE_TURN;
  header_->set_text(INITIAL_DIRECTIVE);
}
