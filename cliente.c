#include "cliente.h"
#include <stdlib.h>
#include <stdio.h>

// Criação da struct cliente
struct cliente {                                
    char nome[50];
    char endereco[50];
    int cod_cliente;                            
};

void countingSort(int * vetor, int tamanho_vetor) {
    int contador, ordenador[tamanho_vetor];

    // Encontra o maior elemento do vetor
    int maior_elemento = vetor[0];
    for (contador = 1; contador < tamanho_vetor; contador++) {
        if (vetor[contador] > maior_elemento) {
            maior_elemento = vetor[contador];
        }
    }

    // Alocação do vetor de contagem
    int * vetor_contagem = (int *) calloc(maior_elemento + 1, sizeof(int));
    if(vetor_contagem == NULL) {
        printf("Falha na alocacao de memoria do vetor: vetor_contagem!\n");
        exit(1);
    }

    // Armazena, no vetor de contagem, o número de ocorrências dos valores do vetor original
    for (contador = 0; contador < tamanho_vetor; contador++) {
        vetor_contagem[vetor[contador]]++;
    }

    // Atualiza os valores do vetor de contagem
    for (contador = 1; contador <= maior_elemento; contador++) {
        vetor_contagem[contador] = vetor_contagem[contador] + vetor_contagem[contador - 1];
    }

    // Encontra o contador de cada elemento e o lugar dos elementos no vetor ordenador
    for (contador = tamanho_vetor - 1; contador >= 0; contador--){
        ordenador[--vetor_contagem[vetor[contador]]] = vetor[contador];
    }

    // Copia os elementos do vetor ordenador no vetor original
    for(contador = 0; contador < tamanho_vetor; contador++){
        vetor[contador] = ordenador[contador];
    }

    free(vetor_contagem);
}