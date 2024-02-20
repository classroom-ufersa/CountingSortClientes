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

/*
void CoutingSort (int array[], int n) {
    int index, b[n];

    // Encontra o maior elemento do Vetor
    int max = array[0];
    for (index=1;index<n;index++){
        if (array[index]>max)
        max = array[index];
    }
    int count [max+1];

    // Inicializa o vetor Count com 0
    for (index=0;index<=max;index++){
        count[index]=0;
    }
    // Armazena o Número de Ocorrencias
    for (index=0;index<n;index++){
        count[array[index]]++;
    }
    // Atualiza o Update Contagem
    for (index=1;index<=max;index++){
        count[index]=count[index]+count[index-1];
    }
    // Encontra o contador de cada elemento e o lugar dos elementos no vetor de Output, Array B
    for (index=n-1;index>=0;index--){
        b[--count[array[index]]]=array[index];

    }
    // Copia os elementos sorteados do Copy the sorted elements into the original array b para o array de Sort
    for(index=0;index<n;index++){
        array[index]=b[index];
    }
}
*/

}