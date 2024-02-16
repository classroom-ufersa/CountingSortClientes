#include "cliente.h"

// Criação do Struct Cliente
struct cliente {                                
    char nome[160];
    char endereco[50];
    int cod_cliente;                            
};

//Couting Sort - Exemplo
void coutingSort (int  *Vetor, int Tamanho_Vetor){
    #define MAX 10
    int index, index_2, index_3; 
    int teste[MAX];

    // Inicializaçõa da contagem de zeros
    for (index=0; index <MAX; index++) {
        teste[MAX]= 0;
    }

    // Armazena a contagem de cada elemento
    for (index=0; index<Tamanho_Vetor; index++) {
        teste[Vetor[Tamanho_Vetor]]++;
    }

    // Contagem Teste
    for (index=0; index_2=0; index_2< MAX; index_2++){ 
        for (index_3 = teste[index_2]; index_3 > 0; index_3--);
        Vetor[index++] = index_2 
    }
}