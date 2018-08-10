

CC := g++
C11 := -std=c++11
# CC := clang --analyze # and comment out the linker last line for sanity
SRCDIR := src
BUILDDIR := build
TARGET := bin/main
 
SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
CFLAGS := -g # -Wall
# LIB := -L lib -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system
LIB := -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system
INC := -I include -I assets


$(TARGET): $(OBJECTS)
	@echo " Linking..."
	@echo " $(CC) $(C11) $^ -o $(TARGET) $(LIB)"; $(CC) $(C11) $^ -o $(TARGET) $(LIB)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	@echo " $(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<
# $@ -- full name of current target 
# $$ -- name of first dependency

clean:
	@echo " Cleaning..."; 
	@echo " $(RM) -r $(BUILDDIR) $(TARGET)"; $(RM) -r $(BUILDDIR) $(TARGET)

# Tests
test:
	$(CC) $(c11) $(CFLAGS) test/test.cpp $(INC)$(LIB) -o bin/test

.PHONY: clean