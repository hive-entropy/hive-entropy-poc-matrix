#
# Makefile created with https://hiltmon.com/blog/2013/07/03/a-simple-c-plus-plus-project-structure/
#

CC := g++
SRCDIR := src
BUILDDIR := build
INCDIR := include
TARGET := bin/runner

SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
CFLAGS := -g -Wall
LIB := -lopenblas
INC := -I $(INCDIR)

$(TARGET): $(OBJECTS)
	@echo ' Linking...'
	@echo ' $(CC) $^ -o $(TARGET) $(LIB)'; $(CC) $^ -o $(TARGET) $(LIB)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	@echo ' $(CC) $(CFLAGS) $(INC) -c -o $@ $<'; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	@echo ' Cleaning...';
	@echo ' $(RM) -r $(BUILDDIR) $(TARGET)'; $(RM) -r $(BUILDDIR) $(TARGET)

.PHONY: clean
