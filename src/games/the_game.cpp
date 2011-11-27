/**
 * @file
 * @author Thaddeus Diamond <diamond@cs.yale.edu>
 * @version 0.1
 * @since 26 Nov 2011
 *
 * @section DESCRIPTION
 *
 * This is a sample program that can run an interchangeable group of board
 * games using the GTKMM framework and board game software we have implemented.
 **/

#include <gtkmm/main.h>
#include "application/application.hpp"

using BoardGames::Application;

int main(int argc, char* argv[]) {
  Gtk::Main kit(argc, argv);

  // TheGame allows the user to play any game
  Application* application = Application::GetApplicationInstance();
  application->InitializeApplication(BoardGames::Configuration::ALL_GAMES);

  Gtk::Main::run(*application->window(0));

  return 0;
}
