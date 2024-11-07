# Variáveis
CC = gcc
CFLAGS = -Iinclude -Wall -Wextra -g
SRC_DIR = src
BUILD_DIR = build
TARGET = program

# Buscar todos os arquivos .c no diretório src e subdiretórios
SRC_FILES := $(shell find $(SRC_DIR) -name '*.c')

# Gerar os arquivos objetos correspondentes
OBJ_FILES := $(SRC_FILES:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

# Regra principal (para compilar e linkar)
all: $(TARGET)

# Linkar os arquivos objeto para gerar o executável
$(TARGET): $(OBJ_FILES)
	$(CC) $(OBJ_FILES) -o $(BUILD_DIR)/$(TARGET)

# Regra para compilar arquivos .c em .o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)  # Cria o diretório de build se não existir
	$(CC) $(CFLAGS) -c $< -o $@

# Limpar os arquivos objetos e o executável
clean:
	rm -rf $(BUILD_DIR)/*

# Regras para apenas compilar arquivos .o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Regra para gerar arquivos de dependências (opcional)
depend: $(SRC_FILES)
	$(CC) -M $(SRC_FILES) > .depend

# Incluir dependências (se geradas)
-include .depend