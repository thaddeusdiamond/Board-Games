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

#include "configuration/configuration.hpp"
#include "window/main_window.hpp"

using BoardGames::Window;
using BoardGames::MainWindow;

using BoardGames::Configuration::GameType;
using BoardGames::Configuration::MAXIMUM_WINDOWS;

/**
 * @namespace BoardGames
 * @brief     The software framework for different board games
 *
 * The BoardGames namespace defines a framework for creating an arbitrary
 * board game application.  It is the focus of this term project.
 **/
namespace BoardGames {
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
     * single application context.  This prevents multiple windows from opening.
     **/
    static Application* GetApplicationInstance();

    /**
     * The InitializeApplication() method is called after the application
     * instance is retrieved.  It is responsible for creating the game we want
     * the user to play based on the enumerated options above.
     *
     * @param     game      Which game we are initializing the application to
     *                      play (enumerated in @ref Configuration::GameType)
     *
     * @returns   True if the game was successfully initialized, false otherwise
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
    Window* window(int index);

   private:
    /**
     * In the Singleton design pattern we make the constructor private so only
     * one instance can ever exist.
     **/
    explicit Application();

    /**
     * In the Singleton design pattern we make the destructor private so no one
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
     * We define a dynamic array of windows that the application can use (up
     * to a predefined maximum).
     **/
    Window** active_windows_;
  };
}

#endif  // _BOARDGAMES_APPLICATION_APPLICATION_HPP_
