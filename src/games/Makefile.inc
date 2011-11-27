# Modify global directives in global namespace
OBJDIRS += games
TESTS += games-test

# relative to $(TOP), i.e. $(LOWERC_DIR)/*.cc
WINDOW_LEARNER_SRCS :=

# Set makefile template specific vars
UPPERC_DIR := GAMES
LOWERC_DIR := games

EXTRA_TEST_OBJS :=

EXECUTABLE := TheGame
EXECUTABLE_SRCS := games/the_game.cpp
EXECUTABLE_OBJS := $(APPLICATION_OBJS) $(WINDOW_OBJS)

include $(MAKEFILE_TEMPLATE)

# Directive to make the test case
games-test: $(GAMES_TESTS)
	@for a in $(GAMES_TESTS); do \
		echo == $$a ==; \
		$(LDLIBPATH) $$a 2>$(LOGDIR)$${a#$(BINDIR)}; \
	done
