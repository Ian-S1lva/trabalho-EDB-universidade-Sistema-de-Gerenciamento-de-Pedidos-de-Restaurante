#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_de_pedidos.h"

// Aqui é onde os pedidos prontos do salão chegam pra peparação
Fila fila_cozinha;

// inicia com a cozinha sme nenhum pedido
void inicializar_fila(Fila* f) {
    f->frente = NULL;
    f->tras = NULL;
}

// tem pedido esperando?
int fila_vazia(Fila* f) {
    return f->frente == NULL;
}

// pedido novo vai p fim da fila
void enfileirar(Fila* f, Pedido p) {
    No* novo = (No*) malloc(sizeof(No));
    novo->pedido = p;
    novo->prox = NULL;

    // verifica se a fila tá vazia, se tiver, ele é o primeiro
    if (f->tras == NULL) {
        f->frente = novo;
        f->tras = novo;
    } else {
        // se não ta vazia, vai p fim
        f->tras->prox = novo;
        f->tras = novo;
    }
}

// pega o primeiro pedido
Pedido desenfileirar(Fila* f) {
    Pedido vazio = {.id = -1}; // se nao tiver nada, vai retornar falso
    if (fila_vazia(f)) return vazio;

    No* temp = f->frente;
    Pedido p = temp->pedido;
    f->frente = f->frente->prox;
    if (f->frente == NULL) f->tras = NULL;

    free(temp); // quando finalizar o pedido, libera memoria
    return p;
}

void exibir_lista_pedidos() {
    if (fila_vazia(&fila_cozinha)) {
        printf("Nenhum pedido em processamento.\n");
        return;
    }

    printf("Pedidos em processamento:\n");
    No* atual = fila_cozinha.frente;
    while (atual != NULL) {
        printf("Pedido #%d:\n", atual->pedido.id);
        for (int i = 0; i < atual->pedido.qtd_pratos; i++) {
            printf(" - %s\n", atual->pedido.pratos[i]);
        }
        atual = atual->prox;
        printf("\n");
    }
}

// quando de fato vai preparar o pedido
void processar_pedidos() {
    if (fila_vazia(&fila_cozinha)) {
        printf("Nenhum pedido para processar.\n");
        return;
    }

    Pedido p = desenfileirar(&fila_cozinha);
    printf("Processando Pedido #%d:\n", p.id);
    for (int i = 0; i < p.qtd_pratos; i++) {
        printf(" - %s\n", p.pratos[i]);
    }
    printf("Pedido #%d concluído.\n\n", p.id);
}
