/**
 * @file
 * @author Thaddeus Diamond <diamond@cs.yale.edu>
 * @version 0.1
 * @since 26 Nov 2011
 *
 * @section DESCRIPTION
 *
 * We create a special board game class so we can decorate a traditional
 * GTK window and provide convenient modifier methods.
 **/

#ifndef _BOARDGAMES_WINDOW_WINDOW_HPP_
#define _BOARDGAMES_WINDOW_WINDOW_HPP_

#include <gtkmm/window.h>

/**
 * @namespace BoardGames
 **/
namespace BoardGames {
  /**
   * @class Window
   * @brief An inherited version of the GTK Window
   *
   * We create an extended version of a GTK window to allow for game-dependent
   * decoration and runtime dispatching of user events via the Bridge DP
   **/
  class Window : public Gtk::Window {
   public:
    explicit Window() {}

    /**
     * The Window destructor is responsible for freeing all memory it allocated
     * during its lifecycle
     **/
    virtual ~Window() {}
  };
}

#endif  // _BOARDGAMES_WINDOW_WINDOW_HPP_
