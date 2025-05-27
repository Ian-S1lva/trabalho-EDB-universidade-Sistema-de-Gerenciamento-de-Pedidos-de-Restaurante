#ifndef LISTA_DE_PEDIDOS_H
#define LISTA_DE_PEDIDOS_H
#include "pedido.h"
#define TAM_NOME 100

typedef struct No {
    Pedido pedido;
    struct No* prox;
} No;

typedef struct {
    No* frente;
    No* tras;
} Fila;

void inicializar_fila(Fila* f);
int fila_vazia(Fila* f);
void enfileirar(Fila* f, Pedido p);
Pedido desenfileirar(Fila* f);
void exibir_lista_pedidos();
void processar_pedidos();
void liberar_pedido(Pedido* p); 

#endif
