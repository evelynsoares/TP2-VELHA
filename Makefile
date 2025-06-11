# Nome do executável de teste que será gerado
TEST_EXEC = teste_velha

# Compilador (g++ para C++)
CXX = g++

# Flags de compilação
# -g: Inclui informações de depuração para usar com o GDB
# -I.: Informa ao compilador para procurar arquivos de cabeçalho (.h ou .hpp) no diretório atual
# -I/mingw64/include: Caminho padrão para os cabeçalhos do GTest quando instalado via pacman no MSYS2/MinGW
# -ftest-coverage -fprofile-arcs: Flags ESSENCIAIS para gerar dados de cobertura de código para o gcov
CXXFLAGS = -g -I. -I/mingw64/include -std=c++17 -ftest-coverage -fprofile-arcs

# Flags para linkagem
# -L/mingw64/lib: Caminho padrão para as bibliotecas do GTest quando instalado via pacman no MSYS2/MinGW
# -lgtest -lgtest_main: Linka as bibliotecas principais do Google Test
# -lgcov: Linka a biblioteca gcov para suporte à cobertura de código
# -pthread: Necessário para o GTest e threads em alguns sistemas (especialmente MinGW)
LDFLAGS = -L/mingw64/lib -lgtest -lgtest_main -lgcov -pthread

# Alvo padrão: 'make' (sem argumentos) compila e linka o executável de teste
all: $(TEST_EXEC)

# Regra para criar o executável de teste
# Depende dos arquivos objeto (.o) correspondentes aos arquivos .cpp
$(TEST_EXEC): velha.o teste_velha.o
	$(CXX) velha.o teste_velha.o -o $@ $(LDFLAGS)

# Regra para compilar velha.cpp em velha.o
# Depende de velha.cpp e velha.hpp
velha.o: velha.cpp velha.hpp
	$(CXX) $(CXXFLAGS) -c velha.cpp -o $@

# Regra para compilar teste_velha.cpp em teste_velha.o
# Depende de teste_velha.cpp e velha.hpp
teste_velha.o: teste_velha.cpp velha.hpp
	$(CXX) $(CXXFLAGS) -c teste_velha.cpp -o $@

# Regra para executar os testes
# Primeiro, garante que o executável de teste esteja compilado e atualizado
# Depois, executa o executável
test: $(TEST_EXEC)
	./$(TEST_EXEC)

# Regra para gerar o relatório de cobertura de código com gcov
# Garante que os testes foram executados antes (para gerar os dados .gcda)
# Em seguida, para cada arquivo fonte (.cpp ou .c) que você quer analisar,
# ele roda o gcov para gerar o arquivo .gcov correspondente.
coverage: test
	@echo "Gerando relatórios de cobertura de código..."
	@gcov velha.cpp
	@gcov teste_velha.cpp 
	@echo "Relatórios .gcov gerados. Verifique os arquivos na pasta do projeto."

# Regra para rodar o verificador estático Cppcheck
# --enable=warning: Ativa a verificação de avisos (warnings)
# .: Analisa os arquivos no diretório atual
cppcheck:
	@echo "Executando Cppcheck para análise estática..."
	@cppcheck --enable=warning .
	@echo "Análise Cppcheck concluída. Verifique a saída acima."

# Nova regra para rodar o Cpplint (verificador de estilo Google C++)
# --filter: Permite desativar avisos específicos. Ajuste conforme sua necessidade.
# Inclui todos os arquivos .cpp e .h no diretório atual.
cpplint:
	@echo "Executando Cpplint para verificação de estilo..."
	@cpplint --filter=-whitespace,-legal/copyright velha.cpp velha.hpp teste_velha.cpp
	@echo "Verificação Cpplint concluída. Verifique a saída acima."

# Nova regra para rodar o Valgrind (verificador dinâmico)
# Depende do executável de teste para garantir que ele esteja compilado.
# --leak-check=full: Realiza uma verificação completa de vazamentos de memória.
# NOTA: Valgrind não é nativamente compatível com Windows. Ele é para Linux/Unix.
# Se você estiver no Windows, você precisará usar o WSL (Windows Subsystem for Linux)
# ou uma VM Linux para usar o Valgrind.
valgrind: $(TEST_EXEC)
	@echo "Executando Valgrind para análise dinâmica (vazamentos de memória)..."
	valgrind --leak-check=full ./$(TEST_EXEC)
	@echo "Análise Valgrind concluída. Verifique a saída acima."

# Nova regra para gerar a documentação do código usando Doxygen
# Requer um Doxyfile configurado no diretório raiz do projeto.
docs:
	@echo "Gerando documentação com Doxygen..."
	@doxygen
	@echo "Documentação gerada na pasta 'docs' (se configurado no Doxyfile). Abra docs/html/index.html."

# Nova regra para executar todas as verificações de uma vez
# Esta regra garante que todos os alvos listados sejam executados em sequência.
# A ordem aqui é importante: teste -> cobertura -> cppcheck -> cpplint -> docs -> valgrind ------------------ADICIONAR.
full_check: test coverage cppcheck docs # cpplint valgrind
	@echo "Todas as verificações (testes, cobertura, análise estática e documentação) foram concluídas."

# Regra para limpar os arquivos gerados
# Remove o executável de teste, os arquivos objeto (.o)
# e também artefatos do gcov (que são gerados para cobertura de código: .gcda, .gcno, .gcov)
clean:
	rm -f $(TEST_EXEC).exe *.o *.gcda *.gcno *.gcov docs/*

# .PHONY é uma convenção para indicar que estes alvos não são arquivos reais
# mas sim "tarefas" ou "ações". Isso evita que o make se confunda.
.PHONY: all test clean coverage cppcheck cpplint valgrind docs full_check