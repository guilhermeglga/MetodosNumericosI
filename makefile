# Só linux

CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -MMD -MP

INCLUDES = \
    -I ./deps/include

LDFLAGS = \
    -L ./deps/lib

# Nem precisa disso eu acho
ifeq ($(OS), Windows_NT)
	LDLIBS = -lraylib -lgdi32 -lwinmm
else
	LDLIBS = -lraylib # não sei se tá certo
endif

SRC := $(shell find src -name "*.cpp")
OBJ := $(SRC:.cpp=.o)
DEP := $(OBJ:.o=.d)

TARGET := build/main

all: $(TARGET)

$(TARGET): $(OBJ)
	mkdir -p build
	$(CXX) $(INCLUDES) $(OBJ) -o $@ $(LDFLAGS) $(LDLIBS)
	rm -f $(OBJ) $(DEP)

%.o: %.cpp
	$(CXX) $(INCLUDES) $(CXXFLAGS) -c $< -o $@ $(LDFLAGS) $(LDLIBS)

-include $(DEP)

clean:
	rm -f $(OBJ) $(DEP) $(TARGET)