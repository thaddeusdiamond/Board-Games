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

#ifndef _BOARDGAMES_GAMES_TIC_TAC_TOE_HPP_
#define _BOARDGAMES_GAMES_TIC_TAC_TOE_HPP_

#include <gtkmm/style.h>
#include <gtkmm/label.h>
#include <gtkmm/button.h>

#include <string>
#include <set>

#include "common/types.hpp"
#include "games/game.hpp"
#include "interface/board.hpp"
#include "interface/menu.hpp"

using Gtk::Style;
using Gtk::Label;
using Gtk::Button;
using Gdk::Color;

using std::string;
using std::set;

using BoardGames::Types::Player;
using BoardGames::Types::GameState;
using BoardGames::Interface::Board;
using BoardGames::Interface::Menu;

/**
 * @namespace Games
 **/
namespace Games {
  /**
   * @namespace Games::SampleGames
   **/
  namespace SampleGames {
    /**
     * @class TicTacToe
     * @brief Simple implementation of the TicTacToe game
     **/
    class TicTacToe : public Games::Game {
     public:
      /**
       * A TicTacToe constructor takes a board object and a label to update
       * with instructions, and then initializes the state of the board
       **/
      explicit TicTacToe() :
          game_state_(PLAYER_ONE_TURN), player_(PLAYER_ONE) {
        // Game specific data
        INITIAL_DIRECTIVE = "Player 1 Make Your Move...";
        DRAW_DIRECTIVE = "It's A Tie! Neither Player Wins";
        PLAYER_NAME[PLAYER_ONE] = "Player 1";
        PLAYER_NAME[PLAYER_TWO] = "Player 2";
        PLAYER_MARK[PLAYER_ONE] = "X";
        PLAYER_MARK[PLAYER_TWO] = "O";
        PLAYER_COLOR[PLAYER_ONE] = "#4671D5";
        PLAYER_COLOR[PLAYER_TWO] = "#FFBF40";
        PLAYER_DIRECTIVE[PLAYER_ONE_TURN] =
          PLAYER_DIRECTIVE[PLAYER_TWO_TURN] = " Take Your Turn";
        PLAYER_DIRECTIVE[GAME_OVER] = " Won the Game!";
        PLAYER_DIRECTIVE[RESETTING] = "Resetting the Board...";

        // Initialize game components
        CreateHeader();
        CreateBoard();
        CreateMenu();

        // Initialize game board and state
        board_state_ = new Player*[board_->height()];
        for (int i = 0; i < board_->height(); i++) {
          board_state_[i] = new Player[board_->width()];
          for (int j = 0; j < board_->width(); j++)
            board_state_[i][j] = NEITHER;
        }
      }

      /**
       * The TicTacToe destructor must free all memory it has aggregated.
       **/
      virtual ~TicTacToe() {
        delete board_;
        delete header_;
        delete options_;
      }

      virtual void OnTileClicked(int row, int col);
      virtual void CompleteTurn();
      virtual void ClearTheBoard();
      virtual Label* header()   { return header_;  }
      virtual Board* board()    { return board_;   }
      virtual Menu*  options()  { return options_; }

      /**
       * The EndGame() method describes clean-up to be performed when the game is
       * over
       **/
      void EndGame(set<Tile*> winning_tiles);

      void CreateBoard();
      void CreateMenu();
      void CreateHeader();

     private:
      /**
       * The game must keep a copy of the board so that it is aware of the
       * game state at any point in time.
       **/
      Board* board_;

      /**
       * The game keeps track of the header where it can output directives
       * to
       **/
      Label* header_;

      /**
       * The game keeps track of a set of in-game options
       **/
      Menu*  options_;

      /**
       * We need to know whether the game is over or still in progress
       **/
      GameState game_state_;

      /**
       * We enumerate the possible game states for convenience in notification
       **/
      enum {
        PLAYER_ONE_TURN = 0,
        PLAYER_TWO_TURN = 1,
        GAME_OVER       = 2,
        RESETTING       = 3,
      };

      /**
       * Keep track of the total number of game states for Tic-Tac-Toe
       **/
      static const int NUMBER_OF_GAME_STATES = 4;

      /**
       * In Tic-Tac-Toe we want to keep track of whose turn it is
       **/
      Player player_;

      /**
       * Label the players separately so we can know whose distinct turn it is
       **/
      enum {
        PLAYER_ONE = 0,
        PLAYER_TWO = 1,
        NEITHER    = 2,
      };

      /**
       * Keep track of the total number of players for Tic-Tac-Toe
       **/
      static const int NUMBER_OF_PLAYERS = 2;

      /**
       * We maintain the representation in the header by an arbitrary name
       **/
      string PLAYER_NAME[NUMBER_OF_PLAYERS];

      /**
       * We maintain the marking on the board by an arbitrary letter (i.e. X, O)
       **/
      string PLAYER_MARK[NUMBER_OF_PLAYERS];

      /**
       * We maintain some liveliness on the board by giving the players colors
       **/
      string PLAYER_COLOR[NUMBER_OF_PLAYERS];

      /**
       * We maintain the directions that should be displayed in the game header
       **/
      string PLAYER_DIRECTIVE[NUMBER_OF_GAME_STATES];

      /**
       * We also keep a reference to the initial directive...
       **/
      string INITIAL_DIRECTIVE;

      /**
       * ... and the tie directive to reduce the code necessary in GameBuilder
       **/
      string DRAW_DIRECTIVE;

      /**
       * Keep a representation of the board state internally
       **/
      Player** board_state_;
    };
  }
}

#endif  // _BOARDGAMES_GAMES_TIC_TAC_TOE_HPP_
