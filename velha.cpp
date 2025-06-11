#include "velha.hpp"
#include <cmath>

// implementacao da verificacao do jogo------------------------------------------
int verificar_jogo(jogoVelha jogo){
    /**
     * Percorre a matriz 3x3 para cada estado de jogo.
     * 0 vazio, 1 X, 2 O
    */
    
    int count_vazio = 0;
    int count_x = 0;
    int count_o = 0;
    //int x_vertical, o_vertical = 0;


    for(int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++){
            if (jogo[i][j] == 0) count_vazio++;
            else if (jogo[i][j] == 1) count_x++;
            else if (jogo[i][j] == 2) count_o++;

        }


        //if (jogo[i][0] == 1) x_vertical++;
        //if (jogo[i][0] == 0) o_vertical++;
    }

    /// A diferença entre o número de Xs e Os não pode ser maior que 1
    /// O não pode ter mais peças que X (X começa a partida)
    if (count_o > count_x || std::abs(count_x-count_o > 1)) return -2;
    /**
     * Estado em que todos os espaços estão vazios indica que não começou: retorna -1
     * Se um jogador inseriu O ou X em mais de 5 posições as regras foram violadas: retorna -2
    */

    if (count_vazio == 9) return -1;
    if (count_x > 5 || count_o > 5) return -2;
    
    return -1;
}

/*
int main () {

    int jogo[3][3] = {
        {1, 1, 0},
        {1, 2, 2},
        {1, 2, 0}
    };

    verificar_jogo(jogo);
    return 0;
}
*/
