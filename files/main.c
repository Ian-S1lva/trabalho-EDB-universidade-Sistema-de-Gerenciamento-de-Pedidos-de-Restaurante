//implementação da interface de usuario

#include <stdio.h>
#include <string.h>

int main(){

    int sair = 0;
    int TELA = 0;
    char c;

    while (sair == 0){

    exibe(TELA);
    printf("\nselecione:");
    scanf("%d",&TELA);    
    //scanf("%c", c);
    //seleciona_opcao(TELA,c);
    if(TELA == 4)
        sair = 1;
    
    }

    return 0;
}

