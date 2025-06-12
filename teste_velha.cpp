/*
 * Arquivo: teste_velha.cpp
 * -------------------------
 * Este arquivo contém uma bateria de testes unitários escritos com o framework
 * Google Test (GTest) para validar a função `verificar_jogo`, responsável por 
 * analisar o estado de um tabuleiro de jogo da velha representado 
 * por uma matriz 3x3 e retornar um valor inteiro que representa:
 *
 *   - 1  -> Vitória do jogador X
 *   - 2  -> Vitória do jogador O
 *   - 0  -> Empate (jogo completo sem vencedor)
 *   - -1 -> Jogo ainda em andamento ou não iniciado
 *   - -2 -> Estado inválido do jogo (regras violadas)
 *
 * A função é testada contra dezenas de cenários, incluindo:
 *   - Vitórias válidas de X e O em todas as direções (linhas, colunas, diagonais)
 *   - Situações de empate
 *   - Jogos ainda em andamento (com jogadas faltando)
 *   - Situações inválidas, como:
 *       - Jogadores com número incorreto de jogadas
 *       - Ambos os jogadores vencendo ao mesmo tempo
 *       - Jogadas simultâneas ou em excesso
 *       - Diferença de jogadas maior que 1 entre os jogadores
 *       - Vencedor com contagem de jogadas incoerente
 *
 * Estes testes garantem que a lógica implementada na função `verificar_jogo`
 * esteja correta e robusta para qualquer entrada possível de estado do jogo.
 *
 * Para compilar os testes, é necessário:
 *   - Ter o Google Test instalado e configurado no projeto.
 *   - Incluir este arquivo em um executável de teste.
 *   - Comando para o Makefile: make full_check 
 *
 * Exemplo de compilação com g++:
 *   g++ -std=c++17 -I<gtest_path>/include -L<gtest_path>/lib \
 *       teste_velha.cpp -lgtest -lgtest_main -pthread -o test_velha
 *
 * Autora: Evelyn Soares Pereira
 * Data: 11/06/25
 */
#include "gtest/gtest.h"
#include "velha.hpp"

TEST(VerificarJogoTest, RegrasVioladasPorJogadorX) {
    jogoVelha violado_x = {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}
    };
    int resultado = verificar_jogo(violado_x);

    ASSERT_EQ(resultado, -2);
}

TEST(VerificarJogoTest, RegrasVioladasPorJogadorO) {
    jogoVelha violado_o = {
        {2, 2, 2},
        {2, 2, 2},
        {2, 2, 2}
    };
    int resultado = verificar_jogo(violado_o);

    ASSERT_EQ(resultado, -2);
}

TEST(VerificarJogoTest, O_MaiorQueX) {
    jogoVelha o_maior = {
        {2, 2, 1},
        {2, 2, 1},
        {1, 1, 2}
    };
    int resultado = verificar_jogo(o_maior);

    ASSERT_EQ(resultado, -2);
}

TEST(VerificarJogoTest, DiferencaAbsoluta) {
    jogoVelha dif_abs = {
        {2, 1, 2},
        {0, 0, 0},
        {2, 1, 2}
    };
    int resultado = verificar_jogo(dif_abs);

    ASSERT_EQ(resultado, -2);
}

TEST(VerificarJogoTest, Empate1) {
    jogoVelha empate1 = {
        {2, 1, 2},
        {2, 1, 1},
        {1, 2, 1}
    };
    int resultado = verificar_jogo(empate1);

    ASSERT_EQ(resultado, 0);
}

TEST(VerificarJogoTest, Empate2) {
    jogoVelha empate2 = {
        {1, 2, 2},
        {2, 1, 1},
        {1, 1, 2}
    };
    int resultado = verificar_jogo(empate2);

    ASSERT_EQ(resultado, 0);
}

TEST(VerificarJogoTest, XGanhaDiagonal) {
    jogoVelha xganha1 = {
        {1, 2, 0},
        {2, 1, 0},
        {0, 0, 1}
    };
    int resultado = verificar_jogo(xganha1);

    ASSERT_EQ(resultado, 1);
}

TEST(VerificarJogoTest, XGanhaDiagonal2) {
    jogoVelha xganha2 = {
        {2, 2, 1},
        {2, 1, 0},
        {1, 0, 1}
    };
    int resultado = verificar_jogo(xganha2);

    ASSERT_EQ(resultado, 1);
}

TEST(VerificarJogoTest, OGanhaDiagonal) {
    jogoVelha oganha1 = {
        {2, 1, 1},
        {1, 2, 1},
        {0, 0, 2}
    };
    int resultado = verificar_jogo(oganha1);

    ASSERT_EQ(resultado, 2);
}

TEST(VerificarJogoTest, OGanhaDiagonal2) {
    jogoVelha oganha2 = {
        {1, 1, 2},
        {1, 2, 0},
        {2, 0, 1}
    };
    int resultado = verificar_jogo(oganha2);

    ASSERT_EQ(resultado, 2);
}

TEST(VerificarJogoTest, XGanhaLinha1) {
    jogoVelha xganhaL1 = {
        {1, 1, 1},
        {0, 2, 2},
        {0, 0, 0}
    };
    int resultado = verificar_jogo(xganhaL1);

    ASSERT_EQ(resultado, 1);
}

TEST(VerificarJogoTest, XGanhaColuna1) {
    jogoVelha xganhaC1 = {
        {1, 1, 2},
        {0, 1, 2},
        {2, 1, 0}
    };
    int resultado = verificar_jogo(xganhaC1);

    ASSERT_EQ(resultado, 1);
}

TEST(VerificarJogoTest, OGanhaLinha3) {
    jogoVelha oganhaL3 = {
        {1, 0, 1},
        {0, 1, 1},
        {2, 2, 2}
    };
    int resultado = verificar_jogo(oganhaL3);

    ASSERT_EQ(resultado, 2);
}

TEST(VerificarJogoTest, OGanhaColuna3) {
    jogoVelha oganhaC3 = {
        {1, 0, 2},
        {0, 1, 2},
        {1, 1, 2}
    };
    int resultado = verificar_jogo(oganhaC3);

    ASSERT_EQ(resultado, 2);
}

TEST(VerificarJogoTest, EmAndamento) {
    jogoVelha andamento1 = {
        {1, 0, 2},
        {0, 0, 0},
        {0, 0, 0}
    };
    int resultado = verificar_jogo(andamento1);

    ASSERT_EQ(resultado, -1);
}

TEST(VerificarJogoTest, EmAndamento2) {
    jogoVelha andamento2 = {
        {1, 0, 2},
        {0, 2, 1},
        {0, 0, 1}
    };
    int resultado = verificar_jogo(andamento2);

    ASSERT_EQ(resultado, -1);
}

TEST(VerificarJogoTest, NaoComecou) {
    jogoVelha andamento3 = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    int resultado = verificar_jogo(andamento3);

    ASSERT_EQ(resultado, -1);
}

TEST(VerificarJogoTest, Empate3) {
    jogoVelha jogo = {
        {1, 2, 1},
        {2, 2, 1},
        {1, 1, 2}
    };
    ASSERT_EQ(verificar_jogo(jogo), 0);
}

TEST(VerificarJogoTest, Invalido1) {
    jogoVelha jogo = {
        {1, 2, 2},
        {0, 0, 0},
        {0, 0, 0}
    };
    ASSERT_EQ(verificar_jogo(jogo), -2);
}

TEST(VerificarJogoTest, Invalido2) {
    jogoVelha jogo = {
        {2, 1, 0},
        {2, 1, 0},
        {2, 1, 0}
    };
    ASSERT_EQ(verificar_jogo(jogo), -2);
}
TEST(VerificarJogoTest, Invalido3) {
    jogoVelha jogo = {
        {2, 2, 2},
        {1, 1, 1},
        {0, 0, 0}
    };
    ASSERT_EQ(verificar_jogo(jogo), -2);
}

TEST(VerificarJogoTest, Invalido4) {
    jogoVelha jogo = {
        {2, 1, 0},
        {2, 1, 0},
        {1, 2, 2}
    };
    ASSERT_EQ(verificar_jogo(jogo), -2);
}

TEST(VerificarJogoTest, InvalidoMaisDe5JogadasX) {
    jogoVelha jogo = {
        {1, 1, 1},
        {1, 1, 1},
        {0, 0, 0}
    };
    ASSERT_EQ(verificar_jogo(jogo), -2);
}

TEST(VerificarJogoTest, InvalidoMaisDe5JogadasO) {
    jogoVelha jogo = {
        {2, 2, 2},
        {2, 2, 2},
        {0, 0, 0}
    };
    ASSERT_EQ(verificar_jogo(jogo), -2);
}

TEST(VerificarJogoTest, InvalidoOJogouMaisQueX) {
    jogoVelha jogo = {
        {2, 2, 0},
        {1, 2, 0},
        {1, 0, 0}
    };
    ASSERT_EQ(verificar_jogo(jogo), -2);
}

TEST(VerificarJogoTest, InvalidoDiferencaTurnoMaiorQue1) {
    jogoVelha jogo = {
        {1, 1, 1},
        {1, 2, 0},
        {0, 0, 0}
    };
    ASSERT_EQ(verificar_jogo(jogo), -2);
}
TEST(VerificarJogoTest, InvalidoXVenceuComContagemErrada) {
    jogoVelha jogo = {
        {1, 1, 1},
        {2, 0, 0},
        {0, 0, 0}
    };
    ASSERT_EQ(verificar_jogo(jogo), -2);
}

TEST(VerificarJogoTest, InvalidoOVenceuComContagemErrada) {
    jogoVelha jogo = {
        {2, 1, 1},
        {1, 2, 1},
        {1, 0, 2}
    };
    ASSERT_EQ(verificar_jogo(jogo), -2);
}

TEST(VerificarJogoTest, InvalidoXGanhouDuasVezes) {
    jogoVelha jogo = {
        {1, 1, 1},
        {1, 2, 2},
        {1, 0, 0}
    };
    ASSERT_EQ(verificar_jogo(jogo), -2);
}

TEST(VerificarJogoTest, InvalidoOGanhouDuasVezes) {
    jogoVelha jogo = {
        {2, 2, 2},
        {2, 1, 1},
        {2, 0, 0}
    };
    ASSERT_EQ(verificar_jogo(jogo), -2);
}

TEST(VerificarJogoTest, XVenceCom5JogadasXEOCom4) {
    jogoVelha jogo = {
        {1, 1, 1},
        {2, 2, 0},
        {0, 0, 0}
    };
    ASSERT_EQ(verificar_jogo(jogo), 1);
}

TEST(VerificarJogoTest, OVenceComContagemInValida) {
    jogoVelha jogo = {
        {2, 2, 2},
        {1, 1, 0},
        {0, 0, 0}
    };
    ASSERT_EQ(verificar_jogo(jogo), -2);
}

TEST(VerificarJogoTest, OVenceComContagemValida) {
    jogoVelha jogo = {
        {2, 2, 2},
        {1, 1, 0},
        {1, 1, 0}
    };
    ASSERT_EQ(verificar_jogo(jogo), 2);
}

TEST(VerificarJogoTest, XGanhaDiagonalSecundaria) {
    jogoVelha jogo = {
        {2, 0, 1},
        {0, 1, 2},
        {1, 0, 0}
    };
    ASSERT_EQ(verificar_jogo(jogo), 1);
}

TEST(VerificarJogoTest, EmpateAlternado) {
    jogoVelha jogo = {
        {1, 2, 2},
        {2, 1, 1},
        {1, 1, 2}
    };
    ASSERT_EQ(verificar_jogo(jogo), 0);
}

TEST(VerificarJogoTest, EmAndamentoCom8Jogadas) {
    jogoVelha jogo = {
        {1, 2, 1},
        {2, 1, 2},
        {2, 1, 0}
    };
    ASSERT_EQ(verificar_jogo(jogo), -1);
}


TEST(TesteVerificarJogo, EmpateComEX) {
    jogoVelha jogo = {
        {1, 2, 1},
        {1, 2, 2},
        {2, 1, 1}
    };
    EXPECT_EQ(verificar_jogo(jogo), 0);
}

TEST(TesteVerificarJogo, VitoriaX) {
    jogoVelha jogo = {
        {1, 1, 1},
        {2, 2, 0},
        {0, 0, 0}
    };
    EXPECT_EQ(verificar_jogo(jogo), 1);
}

TEST(TesteVerificarJogo, VitoriaO) {
    jogoVelha jogo = {
        {2, 1, 1},
        {2, 1, 0},
        {2, 0, 0}
    };
    EXPECT_EQ(verificar_jogo(jogo), 2);
}

TEST(TesteVerificarJogo, EmAndamento) {
    jogoVelha jogo = {
        {1, 2, 1},
        {2, 0, 1},
        {1, 0, 2}
    };
    EXPECT_EQ(verificar_jogo(jogo), -1);
}

TEST(TesteVerificarJogo, Invalido) {
    jogoVelha jogo = {
        {1, 1, 1},
        {1, 1, 1},
        {2, 2, 2}
    };
    EXPECT_EQ(verificar_jogo(jogo), -2);
}

TEST(TesteVerificarJogo, EmAndamento2Ex) {
    jogoVelha jogo = {
        {1, 2, 1},
        {2, 0, 0},
        {1, 0, 0}
    };
    EXPECT_EQ(verificar_jogo(jogo), -1);
}

TEST(TesteVerificarJogo, EmAndamento3Ex) {
    jogoVelha jogo = {
        {1, 2, 0},
        {2, 0, 0},
        {1, 0, 0}
    };
    EXPECT_EQ(verificar_jogo(jogo), -1);
}

TEST(TesteVerificarJogo, InvalidoEx2) {
    jogoVelha jogo = {
        {1, 1, 1},
        {2, 2, 2},
        {2, 2, 2}
    };
    EXPECT_EQ(verificar_jogo(jogo), -2);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); // Inicializa o GTest
    return RUN_ALL_TESTS();                // Executa todos os testes
}