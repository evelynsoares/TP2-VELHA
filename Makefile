# Nome do executável de teste que será gerado
TEST_EXEC = testa_velha

# Compilador (usamos g++ porque C++ é comum com Catch2/GTest)
CXX = g++

# Flags de compilação
# -g: Inclui informações de depuração para usar com o GDB
# -I.: Informa ao compilador para procurar arquivos de cabeçalho (.h) no diretório atual
CXXFLAGS = -g -I.

# Arquivos fonte
SOURCES = velha.c testa_velha.c

# Alvo padrão: make (sem argumentos) compila e linka o executável de teste
all: $(TEST_EXEC)

# Regra para criar o executável de teste
# Depende dos arquivos objeto (.o) correspondentes aos arquivos .c
$(TEST_EXEC): velha.o testa_velha.o
	$(CXX) velha.o testa_velha.o -o $@

# Regra para compilar velha.cpp em velha.o
velha.o: velha.cpp velha.hpp
	$(CXX) $(CXXFLAGS) -c velha.cpp -o $@

# Regra para compilar testa_velha.cpp em testa_velha.o
# Assume que testa_velha.cpp inclui velha.hpp e o seu framework de teste
testa_velha.o: testa_velha.cpp velha.hpp
	$(CXX) $(CXXFLAGS) -c testa_velha.cpp -o $@

# Regra para executar os testes
test: $(TEST_EXEC)
	./$(TEST_EXEC)

# Regra para limpar os arquivos gerados (executáveis e objetos)
clean:
	rm -f $(TEST_EXEC) *.o

# Define os alvos 'all', 'test' e 'clean' como "phony", ou seja, não são arquivos reais
.PHONY: all test clean