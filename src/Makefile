# This makefile system follows the structuring conventions
# recommended by Peter Miller in his excellent paper:
#
#       Recursive Make Considered Harmful
#       http://aegis.sourceforge.net/auug97.pdf
#
# It has been adapted and reused through several projects I (Thaddeus Diamond)
# have used, but credit at various levels is due to Shu-Chun Weng and Alexander
# Thomson

# Root directories to be created and cleaned after
OBJDIR    := ../obj
BINDIR    := ../bin
LOGDIR    := ../logs
EXTDIR    := ../ext
DOCDIR    := ../doc

# External programs that are linked and used automatically in the process
GTEST     := $(EXTDIR)/googletest

# Doxygen specific directives
DOCOUT    := ../doc/html ../doc/latex
DOXY_EXE  := doxygen
DOXY_CONF := BoardGames.doxygen

# Directives for where the source files should look to include headers from
TOP       := .

# '$(V)' controls whether the lab makefiles print verbose commands (the
# actual shell commands run by Make), as well as the "overview" commands
# (such as '+ cc lib/readline.c').
#
# For overview commands only, the line should read 'V = @'.
# For overview and verbose commands, the line should read 'V ='.
V = @

# Set std compiler options (linking for google test and pthread), LD_LIB
CXX       := g++
CXXFLAGS  := -g -I$(GTEST)/include -I$(TOP) -Wall -Werror
CXXFLAGS  += `pkg-config --cflags gtkmm-2.4`
MDFLAGS   := -MD
LDFLAGS   := `pkg-config --libs gtkmm-2.4` -lgtest -L$(GTEST)/lib/.libs
LDLIBPATH := LD_LIBRARY_PATH=$(GTEST)/lib/.libs

# Lists that the */Makefile.inc makefile fragments will add to
TESTS :=

# Make sure that 'all' is the first target
all:

# We define a common "Makefrag"-style template so that we can just set dir
# specific variables and include that template
MAKEFILE_TEMPLATE := Makefile.template

# Makefile fragments for library code
include window/Makefile.inc
include application/Makefile.inc
include games/Makefile.inc

test: $(TESTS)

clean:
	rm -rf $(OBJDIR) $(LOGDIR) $(BINDIR) $(DOCOUT)

#If they specify the use of doxy, then we make doxy first
with-doxy:
	@echo +doc $(DOXY_EXE) $(DOCDIR)/$(DOXY_CONF) \> $(DOCOUT)
	@cd $(DOCDIR); $(DOXY_EXE) $(DOXY_CONF)
	
	
# This magic automatically generates makefile dependencies
# for header files included from C source files we compile,
# and keeps those dependencies up-to-date every time we recompile.
# See 'mergedep.pl' for more information.
$(OBJDIR)/.deps: $(foreach dir, $(OBJDIRS), $(wildcard $(OBJDIR)/$(dir)/*.d))
	@mkdir -p $(@D)
	@cat $^ /dev/null > $@
-include $(OBJDIR)/.deps

always:
	@:

# Eliminate default suffix rules
.SUFFIXES:

# make it so that no intermediate .o files are ever deleted
.PRECIOUS: $(foreach dir, $(OBJDIRS), $(OBJDIR)/$(dir)/%.o) \
           $(foreach dir, $(OBJDIRS), $(OBJDIR)/$(dir)/%unit_test.o)

.PHONY: all always clean test with-doxy
