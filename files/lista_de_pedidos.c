#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_de_pedidos.h"

Fila fila_cozinha;

// inicia a fila
void inicializar_fila(Fila* f) {
    f->frente = NULL;
    f->tras = NULL;
}

// Verifica se a fila está vazia
int fila_vazia(Fila* f) {
    return f->frente == NULL;
}

// add um prato ao pedido
void adicionar_prato(Pedido* p, const char* nome_prato) {
    Prato* novo_prato = (Prato*)malloc(sizeof(Prato));
    strncpy(novo_prato->nome, nome_prato, TAM_NOME); 
    novo_prato->prox = NULL;

    if (!p->lista_pratos) {
        p->lista_pratos = novo_prato;
    } else {
        Prato* atual = p->lista_pratos;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novo_prato;
    }
}

// libera da memória todos os pratos de um pedido (pra evitar vazmento de memória)
void liberar_pedido(Pedido* p) {
    Prato* atual = p->lista_pratos;
    while (atual) {
        Prato* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    p->lista_pratos = NULL;
}

// add um pedido ao final da fila 
void enfileirar(Fila* f, Pedido p) {
    No* novo = (No*)malloc(sizeof(No));
    novo->pedido = p;
    novo->prox = NULL;

    if (f->tras == NULL) {
        f->frente = novo;
        f->tras = novo;
    } else {
        f->tras->prox = novo;
        f->tras = novo;
    }
}

// remove e retorna o priemiro pedid
Pedido desenfileirar(Fila* f) {
    Pedido vazio = {.id = -1, .lista_pratos = NULL};
    if (fila_vazia(f)) return vazio;

    No* temp = f->frente;
    Pedido p = temp->pedido;
    f->frente = f->frente->prox;
    if (f->frente == NULL) f->tras = NULL;

    free(temp); 
    return p;
}

//mostrar todos os pedidos que estão atualmente na fila da cozinha
void exibir_lista_pedidos() {
    if (fila_vazia(&fila_cozinha)) {
        printf("Nenhum pedido em processamento.\n");
        return;
    }

    printf("Pedidos em processamento:\n");
    No* atual = fila_cozinha.frente;
    while (atual != NULL) {
        printf("Pedido #%d:\n", atual->pedido.id);
        Prato* prato = atual->pedido.lista_pratos;
        while (prato != NULL) {
            printf(" - %s\n", prato->nome);
            prato = prato->prox;
        }
        atual = atual->prox;
        printf("\n");
    }
}

// vai processar o prox pedido dacozinha
void processar_pedidos() {
    if (fila_vazia(&fila_cozinha)) {
        printf("Nenhum pedido para processar.\n");
        return;
    }

    Pedido p = desenfileirar(&fila_cozinha);
    printf("Processando Pedido #%d:\n", p.id);

    Prato* prato = p.lista_pratos;
    while (prato != NULL) {
        printf(" - %s\n", prato->nome);
        prato = prato->prox;
    }
    printf("Pedido #%d concluído.\n\n", p.id);
    liberar_pedido(&p);
}
