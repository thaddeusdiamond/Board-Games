# Modify global directives in global namespace
OBJDIRS += deploy
TESTS += deploy-test

# relative to $(TOP), i.e. $(LOWERC_DIR)/*.cc
DEPLOY_SRCS :=

# Set makefile template specific vars
UPPERC_DIR := DEPLOY
LOWERC_DIR := deploy

EXTRA_TEST_OBJS :=

EXECUTABLE := TheGame
EXECUTABLE_SRCS := deploy/the_game.cpp
EXECUTABLE_OBJS := $(APPLICATION_OBJS) $(WINDOW_OBJS) \
                   $(GAMES_OBJS) $(INTERFACE_OBJS)

include $(MAKEFILE_TEMPLATE)

# Directive to make the test case
deploy-test: $(DEPLOY_TESTS)
	@for a in $(DEPLOY_TESTS); do \
		echo == $$a ==; \
		$(LDLIBPATH) $$a 2>$(LOGDIR)$${a#$(BINDIR)}; \
	done

