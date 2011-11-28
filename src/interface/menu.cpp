/**
 * @file
 * @author Thaddeus Diamond <diamond@cs.yale.edu>
 * @version 0.1
 * @since 26 Nov 2011
 *
 * @section DESCRIPTION
 *
 * Implementation of in-game menu
 **/

#include "interface/menu.hpp"

BoardGames::Menu::Menu() {}

BoardGames::Menu::~Menu() {
  vector<Widget*>::iterator it;
  for (it = widgets_.begin(); it < widgets_.end(); it++)
    delete (*it);
}

void BoardGames::Menu::pack_start(Widget* child) {
  widgets_.push_back(child);
  Gtk::VBox::pack_start(*child);
}
