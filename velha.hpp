/**
 * @file velha.hpp
 * @brief Declarações para o jogo da velha.
 *
 * Este arquivo define o tipo de dados para o tabuleiro do jogo da velha e declara
 * a função que verifica o estado atual do jogo, indicando se há um vencedor, empate,
 * estado indefinido ou impossível.
 */
#ifndef VELHA_HPP
#define VELHA_HPP

typedef int jogoVelha[3][3];

/**
 * @brief Verifica o estado atual do jogo da velha.
 * Esta função analisa uma matriz 3x3 que representa o tabuleiro do jogo da velha
 * e retorna um código indicando o vencedor, empate ou estado indefinido/impossível.
 * @param jogo Uma matriz 3x3 de inteiros representando o tabuleiro.
 * 0: Posição vazia, 
 * 1: X, 
 * 2: O.
 * @return int 
 * Um inteiro que indica o estado do jogo:
 * 1: Vencedor X
 * 2: Vencedor O
 * 0: Jogo empatado
 * -1: Jogo indefinido (jogo em andamento ou contagem de peças inválida)
 * -2: Jogo impossível (regras violadas, ex: todas as posições X)
*/
int verificar_jogo(jogoVelha jogo);

#endif // VELHA_HPP
