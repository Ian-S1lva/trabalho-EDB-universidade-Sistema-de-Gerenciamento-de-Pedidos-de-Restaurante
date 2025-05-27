#ifndef PEDIDO_H
#define PEDIDO_H

#define TAM_NOME 100


typedef struct No2 {
    char *prato;
    struct No2* prox;
} No2;

typedef struct {
    int id;
    int qtd_pratos;

    No2* frente;
    No2* tras;
} Pedido; //Fila ligada



void inicializar_pedido(Pedido* p);
int pedido_vazio(Pedido* p);
void inserir(Pedido* p, char* prato);
int busca(Pedido* p, char* prato);
int remover(Pedido* p, char* prato);

void enviar(Pedido* p); //faz o link com pedido.h

void adicionar_prato();
void remover_prato();
void exibir_pedido();
void finalizar_pedido();


#endif