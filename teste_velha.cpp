//testes com gtest
#include "gtest/gtest.h"
#include "velha.hpp"

TEST(VerificarJogoTest, JogoCom1_inicio) {
    jogoVelha jogocom1 = {
        {1, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    int resultado = verificar_jogo(jogocom1);

    ASSERT_EQ(resultado, -1);
}

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
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    int resultado = verificar_jogo(violado_o);

    ASSERT_EQ(resultado, -2);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); // Inicializa o GTest
    return RUN_ALL_TESTS();                // Executa todos os testes
}