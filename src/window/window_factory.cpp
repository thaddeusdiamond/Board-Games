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

#include "common/configuration.hpp"
#include "games/game_builder.hpp"
#include "window/main_window.hpp"
#include "window/window_factory.hpp"

using BoardGames::Window::Window;
using BoardGames::Window::MainWindow;

using Games::GameBuilder;
using Games::Configuration::ALL_GAMES;

Window* BoardGames::Window::WindowFactory::CreateFromGameType(GameType game) {
  switch (game) {
    case ALL_GAMES:
      return new MainWindow();

    default:
      return GameBuilder::BuildWindowFromGameType(game);
  }
}
