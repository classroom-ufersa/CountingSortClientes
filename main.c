#include "cliente.h"
#include <stdio.h>
#include <stdlib.h>

//Constante Máxima de 10    
#define MAX 10
int main() {
    FILE * arq_clientes;
    Cliente * clientes;
    int arra[] = {1,4,3,5,1,7,18,15};
    int size = sizeof(array)/sizeof(array[0]);
    int num_linhas = 1;
    char caractere;

    // Abertura do arquivo 
    arq_clientes = fopen("clientes.txt", "r+");

    if(arq_clientes == NULL) {
        printf("Erro ao tentar abrir arquivo!\n");
        exit(1);
    } else {
        printf("Arquivo aberto com sucesso!\n");
    }

    coutingSort(array, size);
    // Contagem do número de linhas do arquivo
    while((caractere = fgetc(arq_clientes)) != EOF) {
        if(caractere == '\n') {
            num_linhas++;
        }
    }

    clientes = (Cliente *) malloc(num_linhas * sizeof(clientes));
    if(clientes == NULL) {
        printf("Erro na alocacao de memoria!\n");
        exit(1);
    }
    
    // Fechamento do arquivo 
    if(fclose(arq_clientes) == 0) {
        printf("Aquivo fechado com sucesso!\n");
    } 

    free(clientes);

    return 0;
}