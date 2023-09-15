# Makefile 
# Serve para compilar todos os arquivos do projeto com um comando só (para funcionar, precisa estar no diretório raiz)
# Comando de compilação: 'make'
# Comando para rodar: 'make run'
# Comando de limpeza: 'make clean'
# Isso removerá os arquivos de objeto, mas manterá o executável. Execute o seguinte comando:

# Variáveis para especificar o compilador e as opções de compilação
CC = gcc

# Opções de compilação - Essa linha serve para configurações da Makefile
# -Wall: Ativa as opções de compilação para incluir avisos rigorosos.
# -Ilibs: Serve para especificar um diretório adicional para procurar por arquivos de cabeçalho. 
# Essa opção permite usar #include "meu_modulo.h" mesmo que o arquivo meu_modulo.h esteja localizado na pasta "libs"
CFLAGS = -Ilibs

# Diretório onde estão os arquivos-fonte
SRC_DIR = src

# Diretório onde os objetos serão gerados
OBJ_DIR = obj

# Diretório onde os arquivos de saída (executável) serão gerados
OUTPUT_DIR = output

#  Lista de todos os arquivos-fonte 
SRCS = $(wildcard $(SRC_DIR)/*.c)
# Essa é uma função do Makefile que lista todos os arquivos com a extensão .c no diretório especificado por SRC_DIR. 

# Lista de objetos correspondentes a cada arquivo-fonte
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
# Essa é uma função que cria uma lista de objetos correspondentes a cada arquivo-fonte. 
# Ela pega a lista de arquivos-fonte em SRCS, substitui o diretório de origem SRC_DIR pelo diretório de saída OUTPUT_DIR e troca a extensão .c por .o, 
# criando assim uma lista de arquivos de objeto correspondentes.

# O nome do executável final
EXECUTABLE = $(OUTPUT_DIR)/main.out

# Regra para construir o executável
$(EXECUTABLE): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^
# Essa é uma regra que descreve como construir o executável final ($(EXECUTABLE)) a partir dos arquivos de objeto ($(OBJS)). 
# Ela especifica que o executável depende dos objetos e usa o compilador $(CC) com as opções de compilação $(CFLAGS) para criar o executável.

# Regra para compilar os arquivos-fonte em objetos
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<
# Essa é uma regra que descreve como compilar os arquivos-fonte (.c) em objetos (.o). 
# Ela especifica que cada arquivo de objeto em $(OUTPUT_DIR)/%.o depende do arquivo-fonte correspondente em $(SRC_DIR)/%.c. 
# O compilador é usado para compilar o arquivo-fonte em um objeto com a opção -c, e o resultado é salvo em $@, que representa 
# o arquivo de objeto, e $<, que representa o arquivo-fonte.


# Comando para limpar os arquivos de objeto e o executável
clean:
	rm -f $(OBJS) $(EXECUTABLE)
# Essa é uma regra chamada "clean" que define um comando para limpar os arquivos de objeto ($(OBJS)) e o executável ($(EXECUTABLE)). 
# Isso remove os arquivos gerados durante a compilação, deixando apenas os arquivos-fonte e a Makefile.


# Comando para executar o programa
run: $(EXECUTABLE)
	$(EXECUTABLE)
# Essa é uma regra chamada "run" que define um comando para executar o programa. 
# Quando make run é executado, ele simplesmente executa o executável que foi gerado.