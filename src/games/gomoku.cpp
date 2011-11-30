/**
 * @file
 * @author Thaddeus Diamond <diamond@cs.yale.edu>
 * @version 0.1
 * @since 26 Nov 2011
 *
 * @section DESCRIPTION
 *
 * This file defines a quick implementation of Gomoku
 **/

#include "games/gomoku.hpp"

void Games::SampleGames::Gomoku::CreateBoard() {
  board_ = new Board(15, 15, 450, 450);
  if (!board_->AttachTileHandlers(this))
    exit(EXIT_FAILURE);     /// @todo Use Die Macro
}

void Games::SampleGames::Gomoku::CreateMenu() {
  Label* filler = new Label();
  filler->set_size_request(300, 25);

  Button* new_game_button = new Button("Start New Game");
  new_game_button->signal_clicked().connect(
      sigc::mem_fun(this, &Game::ClearTheBoard));

  options_ = new Menu();
  options_->pack_start(filler);
  options_->pack_start(new_game_button);
}

void Games::SampleGames::Gomoku::CreateHeader() {
  header_ = new Label();
  header_->set_text(INITIAL_DIRECTIVE);
  header_->set_size_request(300, 50);
}

void Games::SampleGames::Gomoku::OnTileClicked(int row, int col) {
  // Don't do anything if we're resetting the game
  if (game_state_ == RESETTING)
    return;

  Tile* tile_pressed = board_->tile(row, col);
  board_state_[row][col] = player_;

  // Mark the tile and inactivate it
  char turn_number[10];
  snprintf(turn_number, sizeof(turn_number), "%d", turn_number_);
  tile_pressed->set_label(turn_number);
  tile_pressed->set_sensitive(false);

  // Make it a little prettier
  tile_pressed->modify_bg(Gtk::STATE_INSENSITIVE, Color(PLAYER_COLOR[player_]));

  CompleteTurn();
}

void Games::SampleGames::Gomoku::CompleteTurn() {
  /// Check for at least five in a row
  for (int i = 0; i < board_->height(); i++) {
    for (int j = 0; j < board_->width(); j++) {
      set<Tile*>* five_in_a_row = new set<Tile*>[8];
      Player piece = board_state_[i][j];

      for (int k = 0; k < 5; k++) {
        // Left-upper diagonal
        if (i - k >= 0 && j - k >= 0 && board_state_[i - k][j - k] == piece)
          five_in_a_row[0].insert(board_->tile(i - k, j - k));

        // Right-upper diagonal
        if (i - k >= 0 && j + k < board_->width() &&
            board_state_[i - k][j + k] == piece)
          five_in_a_row[1].insert(board_->tile(i - k, j + k));

        // Left-lower diagonal
        if (i + k < board_->height() && j - k >= 0 &&
            board_state_[i + k][j - k] == piece)
          five_in_a_row[2].insert(board_->tile(i + k, j - k));

        // Right-lower diagonal
        if (i + k < board_->height() && j + k < board_->width() &&
            board_state_[i + k][j + k] == piece)
          five_in_a_row[3].insert(board_->tile(i + k, j + k));

        // Vertically above
        if (i - k >= 0 && board_state_[i - k][j] == piece)
          five_in_a_row[4].insert(board_->tile(i - k, j));

        // Vertically below
        if (i - k >= 0 && board_state_[i - k][j] == piece)
          five_in_a_row[5].insert(board_->tile(i - k, j));

        // Horizontally left
        if (j - k >= 0 && board_state_[i][j - k] == piece)
          five_in_a_row[6].insert(board_->tile(i, j - k));

        // Horizontally right
        if (j + k < board_->width() && board_state_[i][j + k] == piece)
          five_in_a_row[7].insert(board_->tile(i, j + k));
      }

      // Check to see if we have a winner
      for (int k = 0; k < 8; k++) {
        if (five_in_a_row[k].size() == 5 && piece != NEITHER) {
          EndGame(five_in_a_row[k]);
          return;
        }
      }
      delete[] five_in_a_row;
    }
  }

  // Draw?
  bool draw = true;
  for (int i = 0; i < board_->height(); i++) {
    for (int j = 0; j < board_->width(); j++) {
      if (board_state_[i][j] == NEITHER)
        draw = false;
    }
  }
  if (draw) {
    header_->set_text(DRAW_DIRECTIVE);
    return;
  }

  // Update the game state
  turn_number_ += player_;
  player_ = (player_ + 1) % NUMBER_OF_PLAYERS;
  game_state_ = (game_state_ + 1) % NUMBER_OF_PLAYERS;
  header_->set_text(PLAYER_NAME[player_] + PLAYER_DIRECTIVE[game_state_]);
}

void Games::SampleGames::Gomoku::EndGame(set<Tile*> winning_tiles) {
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
  header_->set_text(PLAYER_NAME[player_] + PLAYER_DIRECTIVE[game_state_]);
}

void Games::SampleGames::Gomoku::ClearTheBoard() {
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

  turn_number_ = 0;
  game_state_ = PLAYER_ONE_TURN;
  header_->set_text(INITIAL_DIRECTIVE);
}
