// Arquivo : ces11_vector.c
//
// [CES -11] T30.4: Lab01 .I
// Ewerton Gomes da Silva Araujo Filho
// 9401

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "ces11_vector.h"


typedef struct c11vector
{
    void *data_;
    int elemSize_;
    int count_;
    int capacity_;
} c11vector;

//Malloc seguro para alocacao dinamica
static void* safeMalloc(size_t size)
{
    void *tmp = malloc(size);
    if (!tmp) {
        fprintf(stderr, "Erro no malloc!");
        exit(EXIT_FAILURE);
    }
    return tmp;
}

//Aumenta dinamicamente o tamanho do vetor por 2 se cheio
static void increaseVector(c11vector* self)
{
    if (self->capacity_ == self->count_) {
        if (self->capacity_ == 0)
            self->capacity_ = 2;
        else self->capacity_ *= 2;
    }

    void *tmp = realloc(self->data_, (self->elemSize_) * (self->capacity_));
    if (!tmp) {
        fprintf(stderr, "Erro no realloc!");
        exit(EXIT_FAILURE);
    }

    self->data_ = tmp;
}

c11vector* c11vInit(const int elemSize, const int n)
{
    if (n < 0) {
        fprintf(stderr, "Tamanho de vetor invalido");
        exit(EXIT_FAILURE);
    }
    c11vector* vector = safeMalloc(sizeof(c11vector));

    if (n == 0) vector->data_ = NULL;
    else vector->data_ = safeMalloc(elemSize * n);
    vector->capacity_ = n;
    vector->count_ = 0;
    vector->elemSize_ = elemSize;

    return vector;
}

void c11vFree(c11vector* self)
{
    if (self)
        free(self->data_);
    free(self);
}

void* c11vAt(c11vector *self , const int i)
{
    return (unsigned char*)self->data_ + i * self->elemSize_;
}

bool c11vEmpty(c11vector *self)
{
    return !self->count_;
}

size_t c11vSize(c11vector *self)
{
    return self->count_;
}

void* c11vInsert(c11vector *self, const int pos)
{
    if (pos < 0 || pos > self->count_) {
        fprintf(stderr, "Posicao invalida dde insert");
        exit(EXIT_FAILURE);
    }
    if (self->capacity_ == self->count_) increaseVector(self);

    for (int i = self->count_ - 1; i >= pos; --i)
    {
        memcpy(c11vAt(self, i + 1), c11vAt(self, i), self->elemSize_);
    }
    self->count_++;
    void *pItem = c11vAt(self, pos);
    return pItem;
}

void* c11vPushBack(c11vector *self)
{
    return c11vInsert(self, self->count_);
}

void c11vPopFront(c11vector *self)
{
    if (c11vEmpty(self))
    {
        fprintf(stderr, "Erro no popFront!");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < self->count_ - 1; ++i)
    {
        memcpy(c11vAt(self, i), c11vAt(self, i + 1), self->elemSize_);
    }
    self->count_--;
}

void c11vPopBack(c11vector *self)
{
    if (c11vEmpty(self))
    {
        fprintf(stderr, "Erro no popBack!");
        exit(EXIT_FAILURE);
    }

    self->count_--;
}













