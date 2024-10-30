# Nome do executável
TARGET = programa

# Arquivo principal
MAIN = sb.c

# Diretórios de cabeçalho
INCLUDES = -Iclientes -Iprodutos -Ipacks -Iassinaturas -Irelatorios

# Diretórios e arquivos-fonte
SOURCES = $(MAIN) clientes/clientes.c produtos/produtos.c packs/packs.c assinaturas/assinaturas.c relatorios/relatorios.c

# Compilador
CC = gcc

# Flags de compilação
CFLAGS = -Wall -g $(INCLUDES)

# Variável de detecção do SO
OS := $(shell uname -s)

# Definir comandos de remoção dependendo do sistema operacional
ifeq ($(OS),Linux)
	RM = rm -f
else
	RM = del /F /Q
endif

# Regra principal para construir o programa
$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

# Regra para executar o programa
run: $(TARGET)
	./$(TARGET)

# Limpeza dos arquivos gerados
clean:
	$(RM) $(TARGET)