//testes com gtest
#include "gtest/gtest.h"
#include "velha.hpp"

TEST(VerificarJogoTest, JogoCom1_iniciio) {
    jogoVelha jogocom1 = {
        {1, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    int resultado = verificar_jogo(jogocom1);

    ASSERT_EQ(resultado, -1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); // Inicializa o GTest
    return RUN_ALL_TESTS();                // Executa todos os testes
}