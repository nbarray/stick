# Initialization section #

CXX = clang++
LDFLAGS 	= -lsfml-system -lsfml-window -lsfml-graphics -lsfml-network\
						-lboost_system -lboost_filesystem
CXXFLAGS 	= -std=c++14 -g3 -Wall -Wextra -I./src/

SRCS = rhombus.cc\
			 printable.cc

SRC = $(addprefix src/stick/,$(SRCS))
OBJ = $(SRC:.cc=.o)

TARGET = libstick.so

# libstick.so section #

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) -shared -Wl,-soname,$@ $(OUTPUT_OPTION) $^ $(LDFLAGS)

%.o: %.cc %.hh
	$(CXX) $< $(CXXFLAGS) -fpic -c $(OUTPUT_OPTION)

# Cleaning section #

clean:
	$(RM) $(OBJ)
	$(MAKE) clean -C tests/stick

purge: clean
	$(RM) $(TARGET)
	$(MAKE) purge -C tests/stick

# Test suite section #

tests: $(TARGET)
	cp $(TARGET) tests/stick/lib
	$(MAKE) -C tests/stick

check: tests
	$(MAKE) check -C tests/stick

# Other section #

.PHONY: clean purge tests check
