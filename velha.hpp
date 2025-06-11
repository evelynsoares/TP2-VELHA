#ifndef VELHA_HPP
#define VELHA_HPP

/*
definir matrix 3x3
0 - vazio
1 - X
2 - O
*/

// funcao principal
typedef int jogoVelha[3][3];

/*
retorno
1 - X vencedor
2 - O vencedor
0 - empate
-1 - indefinido
-2 - impossivel
*/

int verificar_jogo(jogoVelha jogo);

#endif // VELHA_HPP
