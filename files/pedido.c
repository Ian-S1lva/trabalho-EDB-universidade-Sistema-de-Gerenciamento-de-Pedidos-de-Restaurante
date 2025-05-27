//implementacao do codigo do salao
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pedido.h"

//uma lista contera todos os pratos possiveis o que cada variavel *prato aponta, é para os nomes dessa lista
char* CARDAPIO[] = {
    "Sopa de Cebola", "Salada Caesar", "Bruschetta", "Carpaccio de Carne", "Camarão ao Alho",
    "Lasanha à Bolonhesa", "Filé Mignon com Fritas", "Frango Grelhado com Legumes", "Bacalhau à Gomes de Sá", "Risoto de Cogumelos",
    "Tiramisu", "Cheesecake de Frutas Vermelhas", "Mousse de Chocolate", "Pudim de Leite", "Sorvete de Baunilha com Calda de Morango"
}; //aqui usando arrays dá pra usar ponteiros direto lá em inserir sem precisar de cópia manual (tipo cardapio[i])
Pedido pedido_salao;
int proximo_id = 1; //do jeito antigo n funciona, acho pq me lembro de ter visto algo sobre n poder atribuir valor fora de função se n for constante ***

void inicializar_pedido(Pedido* p) {
    p->frente = NULL;
    p->tras = NULL;
    p->qtd_pratos = 0;
    p->id = proximo_id++; 
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
    if (pedido_vazio(&pedido_salao)) return -1; //se a fila estiver vazia volte
    
    int i = 0;
    No2* atual = pedido_salao.frente;

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
   
    char nome_prato[50];
    printf("\nnome do prato: ");
    scanf("%s",nome_prato);

    int i;
    for(i=0;i<15;i++){
        if(strcmp(nome_prato,CARDAPIO[i]) == 0){
            inserir(&pedido_salao,CARDAPIO[i]);
            return;
        }
    }
    
    printf("\nprato %s não encontrado, tente novamente.\n", nome_prato);
} 

void remover_prato(){

    char nome_prato[50];
    printf("\nnome do prato: ");
    scanf("%s",nome_prato);
    if(remover(&pedido_salao,nome_prato) == -1){
        printf("\nnão foi possível remover o prato\n");
        return;
    }
    printf("\n 01 %s removido", nome_prato);
}

void exibir_pedido(){
       if (pedido_vazio(&pedido_salao)) {
        printf("Nenhum prato adicionado ainda.\n");
        return;
    }

    printf("Pedido pendente:\n");
    No2* atual = pedido_salao.frente;
    while (atual != NULL) {
        printf(" - %s\n", atual->prato);
        atual = atual->prox;
     
    }
} 

void finalizar_pedido(){ //uso de funcoes da lista_de_pedidos
    //em construcao
    enfileirar(&fila_cozinha,pedido_salao);
    
} 

int main(){
    return 0;
}