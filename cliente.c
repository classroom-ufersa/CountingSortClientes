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
    int contador, ordenador[tamanho_vetor]; //c1

    // Encontra o maior elemento do vetor
    int maior_elemento = vetor[0];  //c2
    for (contador = 1; contador < tamanho_vetor; contador++) { // (n-1) c3 
        if (vetor[contador] > maior_elemento) { // (n-1) c4
            maior_elemento = vetor[contador]; // (n-1) c5
        } 
    }   

    // Alocação do vetor de contagem
    int * vetor_contagem = (int *) calloc(maior_elemento + 1, sizeof(int)); // c6
    if(vetor_contagem == NULL) { // c7
        printf("Falha na alocacao de memoria do vetor: vetor_contagem!\n");
        exit(1);
    }

    // Armazena, no vetor de contagem, o número de ocorrências dos valores do vetor original
    for (contador = 0; contador < tamanho_vetor; contador++) { // n c8
        vetor_contagem[vetor[contador]]++; // n c9
    }   

    // Atualiza os valores do vetor de contagem
    for (contador = 1; contador <= maior_elemento; contador++) { // (n-1) c10
        vetor_contagem[contador] = vetor_contagem[contador] + vetor_contagem[contador - 1]; // (n-1) c11
    }   

    // Encontra o contador de cada elemento e o lugar dos elementos no vetor ordenador
    for (contador = tamanho_vetor - 1; contador >= 0; contador--){ // n c12
        ordenador[--vetor_contagem[vetor[contador]]] = vetor[contador]; // n c13
    }   

    // Copia os elementos do vetor ordenador no vetor original
    for(contador = 0; contador < tamanho_vetor; contador++){ // n c14
        vetor[contador] = ordenador[contador]; // n c15
    }

    free(vetor_contagem); // c16
}

//  t(n)= (c1+c2+c6+c7+c16) + (n-1)(c3+c4+c5+c10+c11) + (n)(c8+c9+c12+c13+c14+c15)
//  t(n)= a + (n-1)*b + (n)*c
//  t(n)= (n-1) + (n)
//  t(n)= O(n)