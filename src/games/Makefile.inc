# Modify global directives in global namespace
OBJDIRS += games
TESTS += games-test

# relative to $(TOP), i.e. $(LOWERC_DIR)/*.cc
# We keep this as a wildcard so that anyone can add a game implementation
GAMES_SRCS := games/*.cpp
GAMES_EXECUTABLES :=

# Set makefile template specific vars
UPPERC_DIR := GAMES
LOWERC_DIR := games

TEST_OBJS :=
EXECUTABLE_OBJS :=

include $(MAKEFILE_TEMPLATE)

# Directive to make the test case
games-test: $(GAMES_TESTS)
	@for a in $(GAMES_TESTS); do \
		echo == $$a ==; \
		$(LDLIBPATH) $$a 2>$(LOGDIR)$${a#$(BINDIR)}; \
	done
