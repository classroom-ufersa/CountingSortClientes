#include "cliente.h"
#include <stdio.h>
#include <stdlib.h>

// Criação do Struct Cliente
struct cliente {                                
    char nome[160];
    char endereco[50];
    int cod_cliente;                            
};
//void coutingSort (int  *Vetor, int Tamanho_Vetor);

void CoutingSort (int array[], int Tamanho_Vetor) {
    int index, ordenador[Tamanho_Vetor];

    // Encontra o maior elemento do Vetor
    int max = array[0];
    for ( index = 1; index < Tamanho_Vetor; index++ ){
        if (array[index] > max)
            max = array[index];
    }

    int count [max+1];

    // Inicializa o vetor Count com 0
    for ( index = 0; index <= max; index++ ){
        count[index] = 0;
    }
    // Armazena o Número de Ocorrencias
    for ( index = 0; index < Tamanho_Vetor; index++ ){
        count[array[index]]++;
    }
    // Atualiza o Update Contagem
    for ( index = 1; index <= max; index++ ){
        count[index] = count[index] + count[index-1];
    }
    // Encontra o contador de cada elemento e o lugar dos elementos no vetor de Output, Array B
    for ( index = Tamanho_Vetor - 1; index >= 0; index--){
        ordenador[--count[array[index]]] = array[index];

    }
    // Copia os elementos sorteados do Copy the sorted elements into the original array b para o array de Sort
    for( index = 0; index < Tamanho_Vetor; index++ ){
        array[index] = ordenador[index];
    }

    for( index = 0; index < Tamanho_Vetor; index++){
        printf("%d",array[index]);
    }
}