# ============================================================================
# Makefile per il progetto di prenotazione biblioteca
# ============================================================================

# Compiler e flags
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -g
LDFLAGS =

# Directory
SRC_DIR = src
INCLUDE_DIR = include
OBJ_DIR = obj
BIN_DIR = .

# File sorgente e object
SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SOURCES))
EXECUTABLE = $(BIN_DIR)/program

# ============================================================================
# Target principali
# ============================================================================

.PHONY: all run clean distclean rebuild help

# Target di default
all: $(EXECUTABLE)
	@echo "✓ Compilazione completata: $(EXECUTABLE)"

# Esegui il programma
run: $(EXECUTABLE)
	@echo "► Avvio programma..."
	./$(EXECUTABLE)

# Aiuto
help:
	@echo "Target disponibili:"
	@echo "  make all          - Compila il programma completo"
	@echo "  make run          - Compila ed esegue il programma"
	@echo "  make clean        - Rimuove file object"
	@echo "  make distclean    - Rimuove object e eseguibile"
	@echo "  make rebuild      - Ricompila da zero"
	@echo ""
	@echo "Target moduli singoli:"
	@echo "  make item         - Compila item.o"
	@echo "  make list         - Compila list.o"
	@echo "  make studente     - Compila studente.o"
	@echo "  make prenotazione - Compila prenotazione.o"
	@echo "  make nonprenotato - Compila nonprenotato.o"
	@echo "  make main         - Compila main.o"

# ============================================================================
# Compilazione: Linking
# ============================================================================

$(EXECUTABLE): $(OBJECTS)
	@echo "► Linking oggetti..."
	$(CC) $(LDFLAGS) -o $@ $^

# ============================================================================
# Compilazione: Object files
# ============================================================================

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@echo "  Compilando $<..."
	$(CC) $(CFLAGS) -c $< -o $@

# ============================================================================
# Target per moduli singoli (per compilazione separata)
# ============================================================================

item: $(OBJ_DIR)/item.o
	@echo "✓ item.o compilato"

list: $(OBJ_DIR)/list.o
	@echo "✓ list.o compilato"

studente: $(OBJ_DIR)/studente.o
	@echo "✓ studente.o compilato"

prenotazione: $(OBJ_DIR)/prenotazione.o
	@echo "✓ prenotazione.o compilato"

nonprenotato: $(OBJ_DIR)/nonprenotato.o
	@echo "✓ nonprenotato.o compilato"

main: $(OBJ_DIR)/main.o
	@echo "✓ main.o compilato"

# ============================================================================
# Pulizia
# ============================================================================

# Rimuove solo i file object
clean:
	@echo "► Pulizia file object..."
	@rm -rf $(OBJ_DIR)
	@echo "✓ Fatto"

# Rimuove object e eseguibile
distclean: clean
	@echo "► Rimozione eseguibile..."
	@rm -f $(EXECUTABLE)
	@echo "✓ Fatto"

# Ricompila da zero
rebuild: distclean all
	@echo "✓ Ricompilazione completata"
