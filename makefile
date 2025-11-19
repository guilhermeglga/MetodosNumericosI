# ToDo:
# Descobrir como suprimir as warnings da raygui

CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -MMD -MP

INCLUDES = \
    -I ./deps/include

LDFLAGS = \
    -L ./deps/lib

ifeq ($(OS), Windows_NT)
	LDFLAGS = \
    	-L ./deps/lib/windows

	LDLIBS = -lraylib -lgdi32 -lwinmm
else
	LDFLAGS = \
    	-L ./deps/lib

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