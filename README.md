# Grupo 12: Ordenção de clientes com Counting Sort
Projeto desenvolvido como parte da avaliação da segunda unidade da disciplina: Algoritmos e Estrutura de Dados I, administrada pela professora Rosana Cibely.
O projeto consiste na realização de um algoritimo que manipula um tipo estruturado (Cliente) e mantém os clientes ordenados por meio de Counting Sort em um arquivo.
## Requisitos
O projeto deve:
- [x] Conter um tipo estruturados (Cliente) que possua os seguintes elementos: Nome, endereço, código do cliente.
- [x] O programa deve ordenar os clientes por código com o algoritmo Couting Sort.
- [x] Computar o tempo de execução do processo de ordenação.
- [x] Atualizar o arquivo texto para manter os clientes ordenados por código.
- [x] Informar a complexidade do algoritmo Counting Sort.
***
## Sumário
* [O que é o CountingSort](#o-que-é-o-counting-sort)
* [Como funciona o CountingSort](#como-funciona-o-counting-sort)
* [Pseudocódigo](#pseudocódigo)
* [Implementação do Código](#implementação-do-código)
* [Complexidade de Tempo](#complexidade-de-tempo)
* [Complexidade de Espaço](#complexidade-de-espaço)
* [Vantagens e Desvantagens do CountingSort](#vantagens-e-desvatanges-de-counting-sort)
* [Fontes](#fontes)
# O que é o Counting Sort?
Desenvolvido pelo cientista da computação Harold H. Sewarld em 1954, CoutingSort ou Ordenação por contagem é um algoritmo utilizado para ordenar um vetor de acordo com valores que são números inteiros positivos, ou seja, é um algoritimo de ordenar por inteiros.

Opera contando o número de objetos que possuem valores distintos e aplica a soma do prefixo nessas contagens para determinar as posições de cada valor na sequência de saída.
É bastante utilizado na sub-rotina do Radix Sort, outro algoritimo de classificação.  
# Como funciona o Counting Sort?
1. Encontra-se o elemento máximo do vetor dado.
2. Inicializa-se um vetor novo considerando o elemento máximo anterior +1 com todos os elementos contidos dentro dele em 0. Esse vetor é utilizado para armazenar a conta dos elementos do vetor inicial. Esse novo vetor é o Vetor de Conta.
3. Em seguida, o vetor de conta armazena a conta de cada elemento de seu respectivo index, e soma +1 se algum elemento do vetor orginal se repetir.
    -Por exemplo, se o vetor dado na posição 1 tiver o número 10, o vetor de conta irá adicionar +1 na posição 10 dele. Se for encontrado o valor 10 novamente, então será adicionado novamente.
4. Encontra-se o contador de cada elemento do vetor original e do vetor de conta. 
    -Caso o elemento 4 for encontrado, ele irá no index 4 do vetor de conta e irá subtrair 1, posicionando no local correspondente do vetor original.
# Pseudocódigo
```
function CountingSort(input, k)
    
    count ← array of k + 1 zeros
    output ← array of same length as input
    
    for i = 0 to length(input) - 1 do
        j = key(input[i])
        count[j] = count[j] + 1

    for i = 1 to k do
        count[i] = count[i] + count[i - 1]

    for i = length(input) - 1 down to 0 do
        j = key(input[i])
        count[j] = count[j] - 1
        output[count[j]] = input[i]

    return output
```
O Pseudocódigo se consiste em:
    - Um vetor contador com o número máximo (k) de elementos de um vetor que é analisado (input).
    - output que é um vetor de mesmo tamanho do vetor input e que será posto em retorno.
    - Um primeiro para (for) utilizado para ver as recorrências dos valores do vetor original.
    - Um segundo para (for) para atualizar os valores do vetor de contagem.
    - Um terceiro para (for) para amazenar no vetor de saída os valores ordenados do vetor original. 
# Implementação do Código
```
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
        vetor_contagem[vetor[contador]]++; // n c9
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
```
# Complexidade de Tempo
Complexidade de tempo é a quantidade de tempo que o algoritimo leva para executar uma tarefa com uma entrada de tamanho N. Diferente de outros códigos de ordenação, o código do Couting Sort sempre se mantem em O(n+k) para todos os cenários pois depende de O(k) para o seu funcionamento. No melhor dos casos todos os itens tem o mesmo tamanho e K é igual a 1 (Tamanho mínimo), no pior dos casos o código cria o mais longo elemento de K possível.
* Melhor Caso   = O(N+K)
* Médio Caso    = O(N+K)
* Pior Caso     = O(N+K)
# Complexidade de Espaço
A Complexidade de espaço de um algoritimo é dita por S(n), onde n é o tamanhno da entrada. 
Considerando o código, a complexidade de espaço sempre irá depender da constante K (Número máximo de elementos), sendo assim a complexidade de tempo do algoritimo É O(k). Quanto maior o elemento, maior será o array de contagem e mais espaço ocupará.
# Vantagens e Desvatanges de Counting Sort
### Vantagens
- [x] Perfomar mais rapidamente me comaparação a outros algoritmos de ordenação, como merge sort e quicksort se o tamanho da entrada for a ordem do tamanho de entrada.
- [x] Algoritmo Estável.
### Desvantagens
- [x] Não funciona com valores decimais.
- [x] Não é eficiente em longos valores para se ordenar.
- [x] Não é um algoritimo "in-lace"(Que não requer nenhuma estrutura da data adicional). Utiliza espaço extra para classificar elementos de uma matriz.
# Fontes
* [Counting Sort - Brilliant](https://brilliant.org/wiki/counting-sort/#counting-sort)
* [Counting Sort - Wikipedia](https://en.wikipedia.org/wiki/Counting_sort)
* [Counting Sort Algorithm](https://www.programiz.com/dsa/counting-sort)
* [Counting Sort – Data Structures and Algorithms Tutorials](https://www.geeksforgeeks.org/counting-sort/)
* [Counting Sort Algorithm: Overview, Time Complexity & More](https://www.simplilearn.com/tutorials/data-structure-tutorial/counting-sort-algorithm#:~:text=Counting%20sort%20is%20an%20integer,prefix%20sum%20to%20those%20counts.)
## Desenvolvedores 
* [Fabio Queiroz Vieira](https://github.com/fabioqv)
* [Giovanni Willian Ferreira da Silva](https://github.com/GiovanniWillian)
* [Leonardo Augusto Silva de Sousa](https://github.com/LeonardAugusto)
* [Levitico Ramon Perez Andrade Alvez](https://github.com/LEVEL303)

