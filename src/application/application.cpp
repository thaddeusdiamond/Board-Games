/**
 * @file
 * @author Thaddeus Diamond <diamond@cs.yale.edu>
 * @version 0.1
 * @since 26 Nov 2011
 *
 * @section DESCRIPTION
 *
 * This is the implementation for a simple GTK application using singleton DP.
 **/

#include "application/application.hpp"

BoardGames::Application* BoardGames::Application::application_instance_ = NULL;

BoardGames::Application* BoardGames::Application::GetApplicationInstance() {
  if (application_instance_ == NULL)
    application_instance_ = new Application();

  return application_instance_;
}

BoardGames::Application::Application() {
  active_windows_ = new Window*[MAXIMUM_WINDOWS];
  for (int i = 0; i < MAXIMUM_WINDOWS; i++)
    active_windows_[i] = NULL;
}

BoardGames::Application::~Application() {
  for (int i = 0; i < MAXIMUM_WINDOWS; i++)
    delete active_windows_[i];
}

Window* BoardGames::Application::window(int index) {
  if (index > MAXIMUM_WINDOWS)
    return NULL;

  return active_windows_[index];
}

void BoardGames::Application::add_window(Window* window) {
  for (int i = 0; i < MAXIMUM_WINDOWS; i++) {
    if (active_windows_[i] == NULL) {
      active_windows_[i] = window;
      window->show();
      window->signal_delete_event().connect(
          sigc::bind<0>(sigc::mem_fun(*this, &Application::remove_window), i));
      break;
    }
  }
}

bool BoardGames::Application::remove_window(int index, GdkEventAny* event) {
  if (index > MAXIMUM_WINDOWS)
    return true;

  if (active_windows_[index] != NULL)
    delete active_windows_[index];
  active_windows_[index] = NULL;

  // Check if the last window was closed, if so exit
  for (int i = 0; i < MAXIMUM_WINDOWS; i++) {
    if (active_windows_[i] != NULL)
      return false;
  }

  Gtk::Main::quit();
  return false;
}

bool BoardGames::Application::InitializeApplication(GameType game) {
  add_window(WindowFactory::CreateFromGameType(game));
  return true;
}
