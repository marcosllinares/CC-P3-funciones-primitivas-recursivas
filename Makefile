CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude
LDFLAGS =

SRCDIR = src
INCDIR = include
BUILDDIR = build
BINDIR = bin

TARGET = $(BINDIR)/primitive-recursion

SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(SOURCES))
DEPS = $(OBJECTS:.o=.d)

all: $(TARGET)

$(TARGET): $(OBJECTS) | $(BINDIR)
	$(CXX) $(LDFLAGS) -o $@ $^

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp | $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

$(BINDIR):
	mkdir -p $(BINDIR)

$(BUILDDIR):
	mkdir -p $(BUILDDIR)

clean:
	rm -rf $(BUILDDIR) $(BINDIR)

.PHONY: all clean

-include $(DEPS)
