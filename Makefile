# Variáveis
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude

# Diretórios
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

# Arquivos
SRC_FILES = $(wildcard $(SRC_DIR)/**/*.c $(SRC_DIR)/model/structs/*.c $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))
TARGET = $(BIN_DIR)/fein-store

# Regra padrão
all: $(TARGET)

# Regra para o binário final
$(TARGET): $(OBJ_FILES)
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@

# Regra genérica para arquivos objeto
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Limpeza
clean:
	rm -rf $(OBJ_DIR)/* $(BIN_DIR)/*

# Debug: Mostra variáveis
debug:
	@echo "SRC_FILES = $(SRC_FILES)"
	@echo "OBJ_FILES = $(OBJ_FILES)"