/**
 * @file
 * @author Thaddeus Diamond <diamond@cs.yale.edu>
 * @version 0.1
 * @since 26 Nov 2011
 *
 * @section DESCRIPTION
 *
 * We create a framework for defining a simple application.  This implements
 * the singleton design pattern because we only ever want one application
 * context.  This is similar to a mobile phone application design,
 * which has only one context at a given time.
 **/

#ifndef _BOARDGAMES_APPLICATION_APPLICATION_HPP_
#define _BOARDGAMES_APPLICATION_APPLICATION_HPP_

#include <gtkmm/main.h>
#include <vector>
#include <algorithm>

#include "common/types.hpp"
#include "window/window.hpp"
#include "window/window_factory.hpp"

using std::vector;
using BoardGames::Window::Window;
using BoardGames::Window::WindowFactory;
using BoardGames::Types::GameType;

/**
 * @namespace BoardGames
 * @brief     The software framework for different board games
 *
 * The BoardGames namespace defines a framework for creating an arbitrary
 * board game application.  It is the focus of this term project.
 **/
namespace BoardGames {
  /**
   * @namespace BoardGames::Application
   * @brief     Application root context
   *
   * The application namespace contains the root application singleton and
   * methodologies for accessing the global application context from anywhere
   * in a program's runtime.
   **/
  namespace Application {
    /**
     * We define the maximum number of windows an application has as a const
     **/
    static const int MAXIMUM_WINDOWS = 10;

    /**
     * @class Application
     * @brief The sole application context
     *
     * The Application class utilizes the Singleton design pattern to create
     * a sole application instance (and therefore context) for initializing
     * game-dependent windows
     **/
    /** @todo    Add testing to Application class **/
    class Application {
     public:
      /**
       * The GetApplicationContext() method is statically defined to return the
       * single application context.  This prevents multiple windows opening.
       **/
      static Application* GetApplicationInstance();

      /**
       * The InitializeApplication() method is called after the application
       * instance is retrieved.  It is responsible for creating the game we want
       * the user to play based on the enumerated options above.
       *
       * @param     game      Which game we are initializing the application to
       *                      play (enum'd in Configuration::)
       *
       * @returns   True if the game was successfully initialized, false o/w
       **/
      bool InitializeApplication(GameType game);

      /**
       * Accessor method for private window variables.
       *
       * @param     index     The index of the window to be returned.
       *
       * @returns   A pointer to the window at that index or NULL if no window
       *            exists at that window.
       **/
      Window::Window* window(int index);

      /**
       * Adder method for private window variables.
       *
       * @param     window    The window that should be added
       **/
      void add_window(Window::Window* window);

      /**
       * Delete method for private window variables.
       *
       * @param     index     The index of the window to be removed
       * @param     event     Standard GTKMM event
       *
       * @returns   False always.  This is used in signal propagation (called
       *            when window is exited out of)
       **/
      bool remove_window(int index, GdkEventAny* event);

     private:
      /**
       * In the Singleton design pattern we make the constructor private so only
       * one instance can ever exist.
       **/
      explicit Application();

      /**
       * In the Singleton design pattern we make destructor private so no one
       * has access to destroying the application context except the application
       * itself.  The destructor must free all memory the application object has
       * created.
       **/
      ~Application();

      /**
       * We define the application instance statically to provide a mechanism
       * to implement the Singleton DP
       **/
      static Application* application_instance_;

      /**
       * We define a dynamic array of windows that the application can use
       **/
      Window::Window** active_windows_;
    };
  }
}

#endif  // _BOARDGAMES_APPLICATION_APPLICATION_HPP_
