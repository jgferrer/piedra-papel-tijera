# Makefile for Piedra, Papel o Tijera SGDK project
# Asegúrate de tener SGDK instalado y la variable GDK configurada

# Variables
PROJECTNAME = piedra-papel-tijera
SRCDIR = src
RESDIR = res
INCDIR = inc

# Regla por defecto
all: rom

# Compilar el ROM
rom:
ifeq ($(GDK),)
	@echo "Error: Variable GDK no está configurada"
	@echo "Configura la variable de entorno GDK que apunte a tu instalación de SGDK"
	@echo "Ejemplo: export GDK=/path/to/sgdk"
	@exit 1
endif
	@echo "Compilando $(PROJECTNAME)..."
	$(MAKE) -f $(GDK)/makefile.gen

# Limpiar archivos generados
clean:
ifeq ($(GDK),)
	@echo "Error: Variable GDK no está configurada"
	@exit 1
endif
	$(MAKE) -f $(GDK)/makefile.gen clean

# Mostrar ayuda
help:
	@echo "Makefile para $(PROJECTNAME)"
	@echo ""
	@echo "Comandos disponibles:"
	@echo "  make rom     - Compila el proyecto y genera rom.bin"
	@echo "  make clean   - Limpia archivos temporales"
	@echo "  make help    - Muestra esta ayuda"
	@echo ""
	@echo "Requisitos:"
	@echo "  - SGDK instalado"
	@echo "  - Variable GDK configurada"

.PHONY: all rom clean help