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
    int contador, ordenador[tamanho_vetor];    //c1

    // Encontra o maior elemento do vetor
    int maior_elemento = vetor[0];  //c2
    for (contador = 1; contador < tamanho_vetor; contador++) {// n-1 c3 
        if (vetor[contador] > maior_elemento) { // n-1 c4
            maior_elemento = vetor[contador]; // n-1 c5
        } 
    }   

    // Alocação do vetor de contagem
    int * vetor_contagem = (int *) calloc(maior_elemento + 1, sizeof(int));    // c6
    if(vetor_contagem == NULL) { // c7
        printf("Falha na alocacao de memoria do vetor: vetor_contagem!\n");    // c8
        exit(1);    //c9
    }

    // Armazena, no vetor de contagem, o número de ocorrências dos valores do vetor original
    for (contador = 0; contador < tamanho_vetor; contador++) {    //n c10
        vetor_contagem[vetor[contador]]++;    //n c11
    }   

    // Atualiza os valores do vetor de contagem
    for (contador = 1; contador <= maior_elemento; contador++) {    //n-1 c12
        vetor_contagem[contador] = vetor_contagem[contador] + vetor_contagem[contador - 1];    //n-1 c13
    }   

    // Encontra o contador de cada elemento e o lugar dos elementos no vetor ordenador
    for (contador = tamanho_vetor - 1; contador >= 0; contador--){     //n+1 c14
        ordenador[--vetor_contagem[vetor[contador]]] = vetor[contador];    //n+1 c15
    }   

    // Copia os elementos do vetor ordenador no vetor original
    for(contador = 0; contador < tamanho_vetor; contador++){    //n c16
        vetor[contador] = ordenador[contador];    //n c17
    }

    free(vetor_contagem);   //c18
}

//  t(n)= (c1+c2+c6+c7+c8+c9+c18) + (n-1)(c3+c4+c5+c12+c13) + (n)(c10+c11+c16+c17) + (n+1)(c14+c15)
//  t(n)= a + (n-1)*b + (n)*c + (n+1)*d
//  t(n)= (n-1) + (n) + (n+1)
//  t(n)= O(n)