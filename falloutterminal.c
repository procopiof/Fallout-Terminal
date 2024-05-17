#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//structs
typedef struct{
    char palavra[50];
    int acertos;
    int qntdLetras;
}palavrasStruct;

//funcoes
void util_removeQuebraLinhaFinal(char dados[]) {
    int tamanho;
    tamanho = strlen(dados);
    if ((tamanho > 0) && (dados[tamanho - 1] == '\n')) {
        dados[tamanho - 1] = '\0';
    }
}

bool verificaTamanhoPalavra(char palavra[], int qntdLetras){
    int qntdTeste;
    qntdTeste = strlen(palavra);
    if(qntdLetras==qntdTeste){
        return true;
    }else{
        return false;
    }
}
palavrasStruct palavraPrincipal(){
    int correto=0;
    do{
        palavrasStruct palavraInicial;
        printf("Digite a quantidade de letras: ");
        scanf("%d", &palavraInicial.qntdLetras);
        getchar();
        printf("Digite a primeira palavra que voce clicou: ");
        fgets(palavraInicial.palavra, 50, stdin);
        util_removeQuebraLinhaFinal(palavraInicial.palavra);
        bool verificador = verificaTamanhoPalavra(palavraInicial.palavra, palavraInicial.qntdLetras);
        if(verificador==false){
            printf("O tamanho da palavra nao corresponde a quantidade de letras!\n");
            printf("Tente NOVAMENTE, animal\n");
            continue;
        }
        printf("Digite o numero de acertos, dessa palavra: ");
        scanf("%d", &palavraInicial.acertos);
        getchar();
        if(palavraInicial.acertos==palavraInicial.qntdLetras){
            printf("Ue, voce ja acertou tudo?\n");
            printf("Tente NOVAMENTE, animal\n");
            continue;
        }
        printf("%s %d/%d\n", palavraInicial.palavra, palavraInicial.acertos, palavraInicial.qntdLetras);
        printf("Esta certo?\n1 - sim\n2 - nao\n");
        scanf("%d", &correto);
        getchar();
        if(correto==1){
            return palavraInicial;
        }
    }while(correto!=1);

}

void checadorDePalavras(palavrasStruct palavraIncial){
    do{
    printf("Digite a palavra que quer descobrir (digite 'sair' para sair): ");
    char palavraDescartavel[50];
    fgets(palavraDescartavel, 50, stdin);
    util_removeQuebraLinhaFinal(palavraDescartavel);
    char sair[]="sair";
    if(strcmp(palavraDescartavel, sair)==0){
        break; //funciona
    }
    if(verificaTamanhoPalavra(palavraDescartavel, palavraIncial.qntdLetras)==false){
        printf("Tamanho invalido, escreva outra palavra");
        continue;
    }
    int contadorLetrasCertas=0;
    for(int i=0; i<palavraIncial.qntdLetras; i++){
        if(palavraDescartavel[i]==palavraIncial.palavra[i]){
            contadorLetrasCertas++;
        }
    }
    if(contadorLetrasCertas==palavraIncial.acertos){
        printf("A palavra pode estar correta!!\n");
    }else{
        printf("ESSA PALAVRA ESTA ERRADA!\n");
    }
    }while(1);
}

//int main
int main(int argc, char* argv){
    printf("Bem vindo ao crackeador de terminal do fallout :)\n");
    palavrasStruct palavraInicial = palavraPrincipal();
    checadorDePalavras(palavraInicial);
    printf("Obrigado por usar o programa :)\n");
}