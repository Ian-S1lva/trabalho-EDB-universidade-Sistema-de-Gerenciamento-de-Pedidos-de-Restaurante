#ifndef LISTA_DE_PEDIDOS_H
#define LISTA_DE_PEDIDOS_H

#define TAM_NOME 100

typedef struct Prato {
    char nome[TAM_NOME];
    struct Prato* prox;
} Prato;

typedef struct {
    int id;
    Prato* lista_pratos;
} Pedido;

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
void adicionar_prato(Pedido* p, const char* nome_prato);
void liberar_pedido(Pedido* p);

#endif
