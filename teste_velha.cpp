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



int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); // Inicializa o GTest
    return RUN_ALL_TESTS();                // Executa todos os testes
}