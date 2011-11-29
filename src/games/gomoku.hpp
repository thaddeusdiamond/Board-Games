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

#ifndef _BOARDGAMES_GAMES_GOMOKU_HPP_
#define _BOARDGAMES_GAMES_GOMOKU_HPP_

#include <gtkmm/style.h>
#include <gtkmm/label.h>

#include <string>

#include "common/types.hpp"
#include "games/game.hpp"
#include "interface/board.hpp"

using Gtk::Style;
using Gtk::Label;

using std::string;

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
   * @brief     A set of sample games for use in GameBoard framework
   *
   * The SampleGames namespace defines a set of samples (TicTacToe and Gomoku)
   * that show how an application developer might make a desired game.
   **/
  namespace SampleGames {
    /**
     * @class Gomoku
     * @brief Simple implementation of the Gomoku game
     **/
    class Gomoku : public Games::Game {
     public:
      /**
       * A Gomoku constructor takes a board object and a label to update
       * with instructions, and then initializes the state of the board
       **/
      explicit Gomoku()
        : board_(new Board(15, 15, 360, 360)), header_(new Label()),
          options_(NULL) {}

      /**
       * The Gomoku destructor must free all memory it has aggregated.
       **/
      virtual ~Gomoku() {
        delete board_;
        delete header_;
        delete options_;
      }

      virtual void OnTileClicked(int row, int col) {}
      virtual void CompleteTurn() {}
      virtual void ClearTheBoard() {}
      virtual Label* header()   { return header_;  }
      virtual Board* board()    { return board_;   }
      virtual Menu*  options()  { return options_; }

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
      Menu* options_;
    };
  }
}

#endif  // _BOARDGAMES_GAMES_GOMOKU_HPP_
