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

using BoardGames::Application;

Application* Application::application_instance_ = NULL;

Application* Application::GetApplicationInstance() {
  if (application_instance_ == NULL)
    application_instance_ = new Application();

  return application_instance_;
}

Application::Application() {
  active_windows_ = new Window*[MAXIMUM_WINDOWS];
}

Application::~Application() {
  delete[] active_windows_;
}

Window* Application::window(int index) {
  if (index > MAXIMUM_WINDOWS)
    return NULL;

  return active_windows_[index];
}

bool Application::InitializeApplication(GameType game) {
  active_windows_[0] = new MainWindow(game);
  for (int i = 1; i < MAXIMUM_WINDOWS; i++)
    active_windows_[i] = NULL;

  // Invalid game was specified
  return false;
}
