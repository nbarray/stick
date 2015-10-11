# Initialization section #

TEST = rhombus\
			 printable

SRC = $(addprefix src/stick/, $(addsuffix .cc,$(TEST)))
OBJ = $(SRC:.cc=.o)
TARGETS = $(addsuffix .test,$(TEST))

CXXFLAGS 	= -std=c++14 -g3 -Wall -Wextra -I../../src
LDFLAGS = -lboost_unit_test_framework\
					-lstick -Llib/\
					-lsfml-system -lsfml-graphics -lsfml-window

# Test suite section #

all: $(TARGETS)

%.test: src/stick/%.o
	$(CXX) $(OUTPUT_OPTION) $^ $(LDFLAGS)

# xXx DiRtY xXx
CHECK = $(addsuffix ;LD_LIBRARY_PATH=lib/,$(addprefix ./,$(TARGETS)))

check: all
	LD_LIBRARY_PATH=lib/ $(CHECK)

# Cleaning section #

clean:
	$(RM) $(OBJ)

purge:
	$(RM) $(OBJ) $(TARGETS) lib/libstick.so
