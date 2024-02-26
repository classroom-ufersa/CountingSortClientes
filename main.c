#include "cliente.h"

struct cliente
{
    char nome[50];
    char endereco[50];
    int cod_cliente;
};

int main()
{
    FILE *arq_clientes;
    Cliente *clientes;
    int *codigos_clientes;
    int num_linhas = 1;
    char caractere;
    int contador, contador_2;
    clock_t inicio;
    double tempo;

    // Abertura do arquivo .txt
    arq_clientes = fopen("clientes.txt", "r");
    if (arq_clientes == NULL)
    {
        printf("Erro ao tentar abrir arquivo!\n");
        exit(1);
    }
    else
    {
        printf("Arquivo aberto com sucesso!\n");
    }

    // Contagem do número de linhas do arquivo
    while ((caractere = fgetc(arq_clientes)) != EOF)
    {
        if (caractere == '\n')
        {
            num_linhas++;
        }
    }

    // Volta para o início do arquivo
    rewind(arq_clientes);

    // Alocação de memória do vetor clientes
    clientes = (Cliente *)malloc(num_linhas * sizeof(Cliente));
    if (clientes == NULL)
    {
        printf("Falha na alocacao de memoria do vetor: clientes!\n");
        exit(1);
    }

    // Alocação de memória do vetor codigos_clientes
    codigos_clientes = (int *)malloc(num_linhas * sizeof(int));
    if (codigos_clientes == NULL)
    {
        printf("Falha na alocacao de memoria do vetor: codigos_clientes!\n");
        exit(1);
    }

    // Preenche, com os dados do arquivo .txt, os vetores: clientes e codigos_clientes
    for (contador = 0; contador < num_linhas; contador++)
    {
        fscanf(arq_clientes, "%s %s %d",
               clientes[contador].nome, clientes[contador].endereco, &clientes[contador].cod_cliente);

        codigos_clientes[contador] = clientes[contador].cod_cliente;
    }

    // Tempo de execucao
    inicio = clock();
    countingSort(codigos_clientes, num_linhas);
    tempo = (double)(clock() - inicio) / CLOCKS_PER_SEC;
    tempo = tempo * 1000; // Milisegundos
    printf("Tempo de execucao: %f Milisegundos\n", tempo);

    // Fechamento e reabertura do arquivo .txt
    if (fclose(arq_clientes) != 0)
    {
        printf("Erro ao fechar o arquivo!\n");
        exit(1);
    }
    arq_clientes = fopen("clientes.txt", "w");
    if (arq_clientes == NULL)
    {
        printf("Erro ao tentar abrir arquivo!\n");
        exit(1);
    }

    // Atualizar o arquivo .txt com os dados ordenados
    for (contador = 0; contador < num_linhas; contador++)
    {
        for (contador_2 = 0; contador_2 < num_linhas; contador_2++)
        {
            if (clientes[contador_2].cod_cliente == codigos_clientes[contador])
            {
                fprintf(arq_clientes, "%s %s %d",
                        clientes[contador_2].nome, clientes[contador_2].endereco, clientes[contador_2].cod_cliente);

                // Adiciona uma nova linha se não for o último cliente
                if (contador != num_linhas - 1)
                {
                    fprintf(arq_clientes, "\n");
                }
                break;
            }
        }
    }

    printf("Ordenacao finalizada!\n");

    // Fechamento do arquivo
    if (fclose(arq_clientes) == 0)
    {
        printf("Aquivo fechado com sucesso!\n");
    }

    free(clientes);
    free(codigos_clientes);

    return 0;
}