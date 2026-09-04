// Arquivo: ces11_pqueue.h
//
// [CES-11] T30.4: Lab01.II
// Ewerton Gomes da Silva Araujo Filho
// 9401


#ifndef CES11_PQUEUE_H
#define CES11_PQUEUE_H

#include <stdbool.h>

typedef struct c11vector c11pqueue;

/*
 * @brief Inicializa uma fila generica, capaz de armazenar elementos de
 *        tamanho elemSize.
 * @param [int] elemSize: tamanho, em bytes, de cada elemento a ser
 *        armazenado na fila de prioridades.
 * @return [c11pqueue *]: ponteiro para a fila recem-criada, ou NULL em
 *         caso de falha de alocacao.
 */
c11pqueue *c11pqInit(int elemSize);

/*
 * @brief Libera toda a memoria alocada para a fila de prioridades.
 * @param [c11pqueue *self]: fila a ser desalocada.
 */
void c11pqFree(c11pqueue *self);

/*
 * @brief Verifica se a fila possui elementos.
 * @param [c11pqueue *self]: fila de prioridades a ser verificada.
 * @return [bool]: verdadeiro se a fila esta vazia, falso caso contrario.
 */
bool c11pqEmpty(c11pqueue *self);

/*
 * @brief Retorna o numero de elementos atualmente armazenados na fila.
 * @param [c11pqueue *self]: fila a ser verificada.
 * @return [int]: quantidade de elementos armazenados.
 */
int c11pqSize(c11pqueue *self);

/*
 * @brief Insere o elemento apontado por q na posicao correta da fila, de
 *        acordo com sua prioridade. A posicao de insercao e localizada por
 *        busca binaria sobre o vetor, que se mantem ordenado por prioridade
 *        crescente (maior prioridade no fim).
 * @param [c11pqueue *self]: fila na qual o elemento sera inserido.
 * @param [void *q]: ponteiro para o item que sera armazenado na fila.
 * @param [int (*compare)(void *, void *)]: ponteiro para funcao que compara
 *        dois itens. Deve retornar valor negativo, zero ou positivo conforme
 *        o primeiro item tenha prioridade menor, igual ou maior que o segundo.
 */
void c11pqPush(c11pqueue *self, void *q, int (*compare)(void *, void *));

/*
 * @brief Remove o item de maior prioridade da fila. Como esse item ocupa a
 *        ultima posicao do vetor, a operacao se reduz a um popBack.
 * @param [c11pqueue *self]: fila da qual o elemento sera removido.
 */
void c11pqPop(c11pqueue *self);

/*
 * @brief Retorna o item de maior prioridade da fila, sem remove-lo
 *        (ultimo elemento do c11vector: funcao back).
 * @param [c11pqueue *self]: fila a ser consultada.
 * @return [void *]: ponteiro para o item de maior prioridade, ou NULL se a
 *         fila estiver vazia.
 */
void *c11pqTop(c11pqueue *self);

#endif /* CES11_PQUEUE_H */
