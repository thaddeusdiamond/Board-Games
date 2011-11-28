/**
 * @file
 * @author Thaddeus Diamond <diamond@cs.yale.edu>
 * @version 0.1
 * @since 26 Nov 2011
 *
 * @section DESCRIPTION
 *
 * This header file defines a set of typedefs that can be used to give greater
 * clarity to the use of primitive types throughout the game framework
 **/

#ifndef _BOARDGAMES_COMMON_TYPES_HPP_
#define _BOARDGAMES_COMMON_TYPES_HPP_

/**
 * @namespace BoardGames
 **/
namespace BoardGames {
  /**
   * @namespace BoardGames::Types
   * @brief     A set of clarifying typedefs
   *
   * Creating a set of typedefs with more descriptive names gives clarity to
   * code that is created later.  It also separates out the need to use
   * the configuration file (which should only be used by factories and main
   * programs)
   **/
  namespace Types {
    /**
     * A GameType is a simple enumerable int.  The actual game types are defined
     * in the configuration
     **/
    typedef int GameType;
  }
}

#endif  // _BOARDGAMES_COMMON_TYPES_HPP_
