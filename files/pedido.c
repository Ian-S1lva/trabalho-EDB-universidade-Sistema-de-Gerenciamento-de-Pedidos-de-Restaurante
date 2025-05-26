//implementacao do codigo do salao
#include <stdio.h>
#include <string.h>
#include "pedido.h"

//uma lista contera todos os pratos possiveis o que cada variavel *prato aponta, é para os nomes dessa lista

Pedido pedido_salao;

void inicializar_pedido(Pedido* p) {
    p->frente = NULL;
    p->tras = NULL;
    p->qtd_pratos = 0;
    //adicionar id com base na qtd de pedidos na cozinha
}

//verifica se esta vazio
int pedido_vazio(Pedido* p) {
    return p->frente == NULL;
}

void inserir(Pedido* p, char* prato) {
    No2* novo = (No2*) malloc(sizeof(No2));
    novo->prato = prato; //prato aponta para o prato a ser inserido
    novo->prox = NULL;

    // verifica se a fila tá vazia, se tiver, ele é o primeiro
    if (p->tras == NULL) {
        p->frente = novo;
        p->tras = novo;
    } else {
        // se não ta vazia, vai p fim
        p->tras->prox = novo;
        p->tras = novo;
    }
    p->qtd_pratos++;
}

//busca a ocorrencia de um prato no pedido e retorna sua posicao
int busca(Pedido* p, char* prato){
    if (fila_vazia(&pedido_salao)) return -1; //se a fila estiver vazia volte
    
    int i = 0;
    while (atual != NULL) { //
        if(atual->prato == prato){//essa construcao compila?
            return i;
        }
        atual = atual->prox;
        i++;
        
    }
    return -1;
}

//busca e remove a 1 ocorrencia de um prato
void remover(Pedido* p, char* prato) {
   
    if (pedido_vazio(p)) return;

    int prato_na_lista = busca(p,prato);
    if(prato_na_lista == -1) return;

    if(prato_na_lista == 0){ //trata o caso pro primeiro da lista
        No2* temp = p->frente;
        p->frente = p->frente->prox;
        free(temp);
        return;
        }
    
        //trata o caso para posicao intermediaria ou final

    No2* atual = p->frente;
    for (int i = 0; i < prato_na_lista - 1 && atual->prox != NULL; i++) { //busca ponteiro anterior ao nó a ser removido
        atual = atual->prox;
    }

    No2* temp = atual->prox;
    atual->prox = temp->prox;
    free(temp);
}


  
   



void adicionar_prato(){
    //em construcao

    //ler nome
    //buscar em lista de pratos
    //se o nome existir
    //passar o ponteiro q aponta para lista de pratos em inserir()
} 

void remover_prato(){
    //em construcao

    //ler nome
    //passar o nome para remover();
    //caso remover() retorne -1 informar que nao foi possivel remover o prato
}

void exibir_pedido(){
       if (pedido_vazio(&pedido_salao)) {
        printf("Nenhum prato adicionado ainda.\n");
        return;
    }

    printf("Pedido:\n");
    No2* atual = pedido_salao.frente;
    while (atual != NULL) {
        printf(" - %s\n", atual->prato);
        atual = atual->prox;
     
    }
} 

void finalizar_pedido(){
    //em construcao
    //transferir para lista da cozinha
    //id++
} 