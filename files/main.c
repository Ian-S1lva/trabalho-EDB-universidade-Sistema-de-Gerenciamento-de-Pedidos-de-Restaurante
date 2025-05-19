//implementação da interface de usuario

#include <stdio.h>
#include <string.h>


int main(){
    
    int TELA = 0;
    char c;

    while (TELA != -1){

    exibe(TELA);
    printf("\nselecione:");   
    scanf("%c", &c);
    seleciona_opcao(&TELA,c);
       
    }

    return 0;
}

