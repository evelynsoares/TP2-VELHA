/**
 * @brief Verifica o estado atual de uma partida de Jogo da Velha.
 *
 * A função analisa um tabuleiro 3x3 e determina se a partida está:
 * - Em andamento
 * - Ganha pelo jogador X
 * - Ganha pelo jogador O
 * - Empatada
 * - Inválida, segundo as regras do jogo
 *
 * As regras consideradas incluem:
 * - X sempre começa a partida
 * - Um jogador não pode ter mais de 5 jogadas
 * - O número de jogadas de X deve ser igual ou exatamente 1 a mais que O
 * - Não é possível que ambos jogadores ganhem simultaneamente
 * - X só vence se jogou uma vez a mais que O
 * - O só vence se jogou o mesmo número ou uma a menos que X
 *
 * @param jogo Matriz 3x3 representando o tabuleiro:
 *        - 0: célula vazia
 *        - 1: jogada do jogador X
 *        - 2: jogada do jogador O
 *
 * @return int Código representando o estado da partida:
 *         -  1: Vitória do jogador X
 *         -  2: Vitória do jogador O
 *         -  0: Empate
 *         - -1: Jogo em andamento
 *         - -2: Estado inválido (regras violadas)
 */
#include "velha.hpp"
#include <cmath>

int verificar_jogo(jogoVelha jogo){
    /**
     * Percorre a matriz 3x3 para cada estado de jogo.
     * 0 vazio, 1 X, 2 O
    */

    int count_x = 0, count_o = 0;

    for(int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++){
            if (jogo[i][j] == 1) count_x++;
            else if (jogo[i][j] == 2) count_o++;
        }
    }

    /**
     * Se um jogador inseriu O ou X em mais de 5 posições as regras foram violadas: retorna -2
    */
    if (count_x > 5 || count_o > 5) return -2;

    /** 
     * A diferença entre o número de Xs e Os não pode ser maior que 1
     * O não pode ter mais peças que X (X começa a partida)
    */
    if (count_o > count_x || std::abs(count_x - count_o) > 1) return -2;


    /// Condicoes para ganhar
    int x_ganha = 0, o_ganha = 0;

    /// Linhas 
    for (int i = 0; i < 3; i++){
        if (jogo[i][0] == 1 && jogo[i][1] == 1 && jogo[i][2] == 1) x_ganha++;
        else if (jogo[i][0] == 2 && jogo[i][1] == 2 && jogo[i][2] == 2) o_ganha++;
    }

    /// Colunas
    for (int j = 0; j < 3; j++){
        if (jogo[0][j] == 1 && jogo[1][j] == 1 && jogo[2][j] == 1) x_ganha++;
        else if (jogo[0][j] == 2 && jogo[1][j] == 2 && jogo[2][j] == 2) o_ganha++;
    }

    /// Diagonais
    if (jogo[0][0] == 1 && jogo[1][1] == 1 && jogo[2][2] == 1) x_ganha++;
    else if (jogo[0][0] == 2 && jogo[1][1] == 2 && jogo[2][2] == 2) o_ganha++;
    else if (jogo[2][0] == 1 && jogo[1][1] == 1 && jogo[0][2] == 1) x_ganha++;
    else if (jogo[2][0] == 2 && jogo[1][1] == 2 && jogo[0][2] == 2) o_ganha++;

    /// Nao é possivei os dois ganharem
    if (x_ganha > 0 && o_ganha > 0) return -2;

    if (x_ganha > 0) {
        /// X só pode vencer se ele tiver uma jogada a mais
        if (count_x == count_o + 1) return 1;
        else return -2;
    }

    if (o_ganha > 0) {
        /// O só pode vencer se tiver jogado <= número de vezes que X 
        if (count_o == count_x || count_o == count_x - 1) return 2;
        else return -2;
    }

    /// Jogo empatado
    if ((count_x + count_o) == 9) return 0;

    /// Jogo em andamento
    return -1;
}
