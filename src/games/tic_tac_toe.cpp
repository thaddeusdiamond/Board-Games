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

void Games::SampleGames::TicTacToe::OnTileClicked(int row, int col) {
  Tile* tile_pressed = board_->tile(row, col);
  board_state_[row][col] = player_;

  // Mark the tile and inactivate it
  tile_pressed->set_label(PLAYER_MARK[player_]);
  tile_pressed->set_sensitive(false);

  // Make it a little prettier
  Gdk::Color* color = new Gdk::Color(PLAYER_COLOR[player_]);
  tile_pressed->modify_bg(Gtk::STATE_INSENSITIVE, *color);

  CompleteTurn();
}

void Games::SampleGames::TicTacToe::CompleteTurn() {
  // Row-wise check
  for (int i = 0; i < board_->height(); i++) {
    Player initial_player = board_state_[0][i];
    
    int j;
    for (j = 1; j < board_->width(); j++) {
      if (board_state_[j][i] != initial_player)
        break;
    }

    if (initial_player != NEITHER && j == board_->width())
      EndGame();
  }

  // Column-wise check
  for (int i = 0; i < board_->width(); i++) {
    Player initial_player = board_state_[i][0];
    
    int j;
    for (j = 1; j < board_->height(); j++) {
      if (board_state_[i][j] != initial_player)
        break;
    }

    if (initial_player != NEITHER && j == board_->height())
      EndGame();
  }

  // Diagonal-check (R to L)
  int i;
  Player initial_player = board_state_[0][0];
  for (i = 1; i < board_->width(); i++) {
    if (board_state_[i][i] != initial_player)
      break;
  }
  if (initial_player != NEITHER && i == board_->height())
    EndGame();  

  // Diagonal-check (L to R)
  initial_player = board_state_[board_->width() - 1][0];
  for (i = 1; i < board_->width(); i++) {
    if (board_state_[board_->width() - i - 1][i] != initial_player)
      break;
  }
  if (initial_player != NEITHER && i == board_->height())
    EndGame();

  if (game_state_ != GAME_OVER) {
    player_ = (player_ + 1) % NUMBER_OF_PLAYERS;
    game_state_ = (game_state_ + 1) % NUMBER_OF_PLAYERS;
  }
  
  directive_->set_text(PLAYER_NAME[player_] + PLAYER_DIRECTIVE[game_state_]);
}

void Games::SampleGames::TicTacToe::EndGame() {
  for (int i = 0; i < board_->height(); i++) {
    for (int j = 0; j < board_->width(); j++)
      board_->tile(i, j)->set_sensitive(false);
  }

  game_state_ = GAME_OVER;
}
