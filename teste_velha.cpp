//testes com gtest
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

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); // Inicializa o GTest
    return RUN_ALL_TESTS();                // Executa todos os testes
}