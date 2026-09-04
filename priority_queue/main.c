// Arquivo: main.c
//
// [CES-11] T30.4: Lab01.I
// Ewerton Gomes da Silva Araujo Filho
// 9401

#include "ces11_pqueue.h"
#include "ces11_vector.h"
#include <stdbool.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <stdio.h>


typedef struct {
    char descricao[40];
    int prioridade;
} Tarefa;

struct c11vector
{
    void *data_;
    int elemSize_;
    int count_;
    int capacity_;
};

int comparaTarefas(void *a, void *b)
{
    // conversao void* - Tarefa*
    Tarefa *t1 = (Tarefa*)a;
    Tarefa *t2 = (Tarefa*)b;

    // comparacao das prioridades
    return t1->prioridade - t2->prioridade;
}

int main(int argc, char **argv)
{
    // abertura dos arquivos de entrada e saida
    FILE *arqIn = fopen(argv[1], "r");
    FILE *arqOut = fopen("saida1.txt", "w");

    // impressao no arquivo de saida
    // cabecalho
    fprintf(arqOut, "Agenda Eletronica\n");
    fprintf(arqOut, "``O que habita no esconderijo do Altissimo e\n");
    fprintf(arqOut, "descansa `a sombra do Onipotente diz ao Senhor: Meu\n");
    fprintf(arqOut, "refugio e meu baluarte, Deus meu, em quem confio.``\n");
    fprintf(arqOut, "\n");

    // respostas das consultas
    fprintf(arqOut, "--------------------------------------------------\n");
    fprintf(arqOut, "RESPOSTAS DAS CONSULTAS\n");
    fprintf(arqOut, "--------------------------------------------------\n");

    // declaracao da priority queue
    c11pqueue *pq;
    pq = c11pqInit(sizeof(Tarefa));

    char linha[71];

    // leitura do arquivo de entrada
    while (true)
    {
        char tarefaTipo[8];

        // ignora primeiras linhas
        fgets(linha, 70, arqIn);
        if (linha[0] == '#') continue;

        sscanf(linha, "%7s ", tarefaTipo);

        // identifica tarefa nova, pula linha ou finaliza
        if (strcmp(tarefaTipo, "FIM") == 0) break;

        if (strcmp(tarefaTipo, "PROXIMA") == 0) {
            // imprime tarefa de maior prioridade
            fprintf(arqOut, "%2d       ", ((Tarefa*)c11pqTop(pq))->prioridade);
            fprintf(arqOut, "%s\n", ((Tarefa*)c11pqTop(pq))->descricao);

            c11pqPop(pq); // retira item impresso da lista
        }
        else if (strcmp(tarefaTipo, "NOVA") == 0) {
            Tarefa tarefa;
            sscanf(linha, "%*s %d %39[^\n]", &tarefa.prioridade, tarefa.descricao);

            c11pqPush(pq, &tarefa, comparaTarefas);
        }
    }

    // fica para o dia seguinte
    fprintf(arqOut, "\n");
    fprintf(arqOut, "--------------------------------------------------\n");
    fprintf(arqOut, "FICA PARA O DIA SEGUINTE\n");
    fprintf(arqOut, "--------------------------------------------------\n");


    while (!c11pqEmpty(pq))
    {
        fprintf(arqOut, "%2d       ", ((Tarefa*)c11pqTop(pq))->prioridade);
        fprintf(arqOut, "%s\n", ((Tarefa*)c11pqTop(pq))->descricao);
        c11pqPop(pq);
    }

    c11pqFree(pq);

    fclose(arqIn);
    fclose(arqOut);

    return EXIT_SUCCESS;
}
