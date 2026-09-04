// Arquivo: ces11_pqueue.c
//
// [CES-11] T30.4: Lab01.II
// Ewerton Gomes da Silva Araujo Filho
// 9401

#include "ces11_pqueue.h"
#include "ces11_vector.h"
#include <string.h>

struct c11vector
{
    void *data_;
    int elemSize_;
    int count_;
    int capacity_;
};

c11pqueue* c11pqInit(int elemSize)
{
    return c11vInit(elemSize, 1);
}

void c11pqFree(c11pqueue *self)
{
    return c11vFree(self);
}

bool c11pqEmpty(c11pqueue *self)
{
    return c11vEmpty(self);
}

int c11pqSize(c11pqueue *self)
{
    return c11vSize(self);
}

void c11pqPush(c11pqueue *self, void *q, int (*compara)(void*, void*))
{
    int size = c11vSize(self);
    int low = 0;
    int high = size - 1;
    int insertIdx = size; // insere no final se for maior

    // algoritmo de busca binaria
    while (low <= high)
    {
        int mid = (low + high) / 2;
        void* elemMid = c11vAt(self, mid);

        if (compara(q, elemMid) <= 0) {
            insertIdx = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    void *slot = c11vInsert(self, insertIdx);
    memcpy(slot, q, self->elemSize_);
}

void c11pqPop(c11pqueue *self)
{
    c11vPopBack(self);
}

void* c11pqTop(c11pqueue *self)
{
    return c11vAt(self, c11pqSize(self) - 1);
}



