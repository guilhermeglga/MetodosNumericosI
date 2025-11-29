CXX = g++
CXXFLAGS = -Wall -g -Isrc -Iinclude -I../deps/include
LIB_DIR = -L../deps/lib
LIBS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
TARGET = CalculadoraDeRaízesDePolinômios
BUILD_DIR = build

SRCS = $(shell find src -name "*.cpp")
OBJS = $(SRCS:%.cpp=$(BUILD_DIR)/%.o)

all: $(BUILD_DIR)/$(TARGET)

$(BUILD_DIR)/$(TARGET): $(OBJS)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS) $(LIB_DIR) $(LIBS)

$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)
