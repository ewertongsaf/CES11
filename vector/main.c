// Arquivo: main.c
//
// [CES-11] T30.4: Lab01.I
// Ewerton Gomes da Silva Araujo Filho
// 9401

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "ces11_vector.h"

//funcao que verifica se dado inteiro eh primo
bool isPrime(int n)
{
    if (n <= 1) return false;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }

    return true;
}

//funcao para imprimir na tela todos os elementos do vetor
void printVector(c11vector *vector, int type)
{
    for (size_t i = 0; i < c11vSize(vector); ++i) {
        if (type == 0)
            printf("%.1f " , *(float*)c11vAt(vector, i));
        if (type == 1)
            printf("%.1f " , *(double*)c11vAt(vector, i));
        if (type == 2)
            printf("%d " , *(int*)c11vAt(vector, i));
    }
}

int main(int argc, char *argv[])
{
    const int p = atoi(argv[1]);
    const int n = atoi(argv[2]);
    const int k = atoi(argv[3]);

    c11vector *vetor;

    //vetor tipo float
    if (p == 0)
    {
        //inicializacao
        vetor = c11vInit(sizeof(float), n);
        for (float i = 0; i < n; ++i)
        {
            *(float*)c11vPushBack(vetor) = i;
        }

        //0: rotacao para a esquerda
        for (float i = 0; i < k; ++i)
        {
            float tmp = *(float*)c11vAt(vetor, 0);
            c11vPopFront(vetor);
            *(float*)c11vPushBack(vetor) = tmp;
        }
    }

    //vetor tipo double
    else if (p == 1)
    {
        vetor = c11vInit(sizeof(double), n);
        for (double i = 0; i < n; ++i)
        {
            *(double*)c11vPushBack(vetor) = i;
        }

        //1: rotacao para a direita
        for (double i = 0; i < k; ++i)
        {
            double tmp = *(double*)c11vAt(vetor, c11vSize(vetor) - 1);
            *(double*)c11vInsert(vetor, 0) = tmp;
            c11vPopBack(vetor);
        }
    }

    //vetor tipo int
    else if (p == 2)
    {
        //inicializacao
        vetor = c11vInit(sizeof(int), n);
        for (int i = 0; i < n; ++i)
        {
            *(int*)c11vPushBack(vetor) = i;
        }

        //2: remove nao primos
        for (int i = 0; i < n; ++i) {
            if (isPrime(i))
                *(int*)c11vPushBack(vetor) = i;
            c11vPopFront(vetor);
        }
    }

    //imprime vetor na tela
    printVector(vetor, p);

    //libera a memoria apos a impressao
    c11vFree(vetor);

    return EXIT_SUCCESS;
}

