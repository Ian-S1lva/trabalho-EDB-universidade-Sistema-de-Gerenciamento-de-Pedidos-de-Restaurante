//implementação da interface de usuario

#include <stdio.h>
#include <string.h>
#include "menu.h"

int main(){
    
    int TELA = 0;
    char c[2]; 

    while (TELA != -1){

    exibe(TELA);
    printf("\nselecione:");   
    scanf("%s", c);
    seleciona_opcao(&TELA,c[0]); 
       
    }

    return 0;
}

