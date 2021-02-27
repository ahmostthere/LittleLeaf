

CC := g++
C11 := -std=c++11
# CC := clang --analyze # and comment out the linker last line for sanity
SRCDIR := src
BUILDDIR := build
TARGET := bin/main

 
SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))


CFLAGS := -g -Wall
# LIB := -L lib -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system
LIB := -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system
INC := -I include -I assets

TSTDIR := test
TSTTARG := bin/test
TSTSRC := $(shell find $(TSTDIR) -type f -name *.$(SRCEXT))
TSTOBJ := $(patsubst $(TSTDIR)/%,$(BUILDDIR)/%,$(TSTSRC:.$(SRCEXT)=.o))

$(TARGET): $(OBJECTS)
	@echo " Linking..."
	@echo " $(CC) $(C11) $^ -o $(TARGET) $(LIB)"; $(CC) $(C11) $^ -o $(TARGET) $(LIB)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(dir $(OBJECTS))
	@echo " $(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<
# $@ -- full name of current target 
# $$ -- name of first dependency

clean:
	@echo " Cleaning..."; 
	@echo " $(RM) -r $(BUILDDIR) $(TARGET) $(TSTTARG)"; $(RM) -r $(BUILDDIR) $(TARGET) $(TSTTARG)

# Tests
test: $(TSTOBJ)
	$(CC) $(C11) $^ -o $(TSTTARG) $(LIB)

$(BUILDDIR)/%.o: $(TSTDIR)/%.cpp
	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

.PHONY: clean