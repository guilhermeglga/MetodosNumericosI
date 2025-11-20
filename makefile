# Não consegui testar se tá tudo certo no linux

CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -MMD -MP -isystem deps/include

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

	LDLIBS = -lraylib
endif

SRC_DIR := src
BUILD_DIR := build

SRC := $(shell find $(SRC_DIR) -name "*.cpp")
OBJ := $(SRC:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)
DEP := $(OBJ:.o=.d)

TARGET := $(BUILD_DIR)/main

all: $(TARGET)

$(TARGET): $(OBJ)
	mkdir -p $(BUILD_DIR)
	$(CXX) $(INCLUDES) $(OBJ) -o $@ $(LDFLAGS) $(LDLIBS)
	# rm -f $(OBJ) $(DEP)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	mkdir -p $(dir $@)
	$(CXX) $(INCLUDES) $(CXXFLAGS) -c $< -o $@ $(LDFLAGS) $(LDLIBS)

-include $(DEP)

clean:
	rm -f $(OBJ) $(DEP) $(TARGET)