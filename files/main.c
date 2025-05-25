//implementação da interface de usuario

#include <stdio.h>
#include <string.h>
#include "menu.h"

int main(){
    
    int TELA = 0;
    char c[2]; //troquei c por c[] para usar %s e remover espacos

    while (TELA != -1){

    exibe(TELA);
    printf("\nselecione:");   
    scanf("%s", c);
    seleciona_opcao(&TELA,c[0]); //importa só o 1º char
       
    }

    return 0;
}

