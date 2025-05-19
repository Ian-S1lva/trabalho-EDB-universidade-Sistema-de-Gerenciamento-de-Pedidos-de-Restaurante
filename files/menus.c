//implementação de telas 
#include <stdio.h>

#define BORDAS "-------------------------"

void adicionar_prato(){} //funcoes e assinaturas de funcoes temporariamente aqui
void remover_prato(){} //dps transferir para lista_de_pedidos.c, lista_de_pedidos.h,
void exibir_pedido(){} // pedido.c ou pedido.h
void finalizar_pedido(){}
void exibir_lista_pedidos(){}
void processar_pedidos(){}

void exibe(int tela){
    //tela 0 = menu principal
    //tela 1 = novo pedido
    //tela 2 = cozinha
    //tela 3 = cardapio
    switch (tela){
        case 0:
            printf("%s  SALÃO  %s", BORDAS, BORDAS);
            printf("\n");
            printf("1. novo pedido\n");
            printf("2. ir para cozinha\n");
            printf("3. sair\n");
            break;
        case 1:
            printf("%s  SALÃO  %s", BORDAS, BORDAS);
            printf("\n");
            printf("1. adicionar prato\n");
            printf("2. remover prato\n");
            printf("3. exibir pedido\n");
            printf("4. cardápio\n");
            printf("5. finalizar pedido e enviar para processamento\n");
            break;
        case 2:
            printf("%s COZINHA %s", BORDAS, BORDAS);
            printf("\n");
            printf("1. exibir lista de pedidos em processamento\n");
            printf("2. processar pedidos\n");
            printf("3. voltar ao salão\n");
            break;
        case 3:
                printf("%s CARDÁPIO %s", BORDAS, BORDAS);                
                printf("\n");
                printf("### Entradas\n");
                printf("\n");
                printf("1. Sopa de Cebola\n");
                printf("2. Salada Caesar\n");
                printf("3. Bruschetta\n");
                printf("4. Carpaccio de Carne\n");
                printf("5. Camarão ao Alho\n");
                printf("\n");
                printf("### Pratos Principais\n");
                printf("\n");
                printf("1. Lasanha à Bolonhesa\n");
                printf("2. Filé Mignon com Fritas\n");
                printf("3. Frango Grelhado com Legumes\n");
                printf("4. Bacalhau à Gomes de Sá\n");
                printf("5. Risoto de Cogumelos\n");
                printf("\n");
                printf("### Sobremesas\n");
                printf("\n");
                printf("1. Tiramisu\n");
                printf("2. Cheesecake de Frutas Vermelhas\n");
                printf("3. Mousse de Chocolate\n");
                printf("4. Pudim de Leite\n");
                printf("5. Sorvete de Baunilha com Calda de Morango\n");
                printf("\n");
                printf("V = Voltar");
            break;

    }

}

seleciona_opcao(int* TELA,char c){
    //tela -1 = sair
    //tela 0 = menu principal
    //tela 1 = novo pedido
    //tela 2 = cozinha
    //tela 3 = cardapio
    switch (*TELA){
        case 0:
            if(c == '1'){
                *TELA = 1;
            }
            else if(c == '2'){
                *TELA = 2;
            }
            else if(c == '3'){
                printf("saindo do programa...");
                *TELA = -1;
            }
            break;
        case 1:
            if(c == '1'){
                adicionar_prato();
            }
            else if(c == '2'){
                remover_prato();
            }
            else if(c == '3'){
                exibir_pedido();
            }
            else if(c == '4'){
                *TELA = 3;
            }
            else if(c == '5'){
                finalizar_pedido();
                *TELA = 0;
            }           
            break;
        case 2:
            if(c == '1'){
                exibir_lista_pedidos();
            }
            else if(c == '2'){
                processar_pedidos();
            }
            else if(c == '3'){
                *TELA = 0;
            }
            break;
        case 3:
            if(c == 'V'){
                *TELA = 1;
            }
            break;
    }

}