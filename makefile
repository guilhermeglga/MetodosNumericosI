# 1. Configurações
CXX = g++
# -Isrc ajuda a encontrar os headers (.h) que estão espalhados nas subpastas
CXXFLAGS = -Wall -g -Isrc -Iinclude
TARGET = meu_programa_cpp

# 2. Arquivos Fonte (A Mágica acontece aqui)
# Usa o comando 'find' para listar TODOS os .cpp dentro de src e subpastas
SRCS = $(shell find src -name "*.cpp")

# Gera a lista de objetos (.o) mantendo a estrutura de pastas
OBJS = $(SRCS:.cpp=.o)

# 3. Regra Principal
all: $(TARGET)

# 4. Linkagem
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# 5. Compilação Genérica
# O mkdir -p garante que a pasta do .o exista antes de compilar
%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 6. Limpeza
clean:
	rm -f $(OBJS) $(TARGET)
