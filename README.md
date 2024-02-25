# Grupo 12: Ordenção de clientes com Counting Sort
Projeto desenvolvido como parte da avaliação da segunda unidade da disciplina Estrutura de Dados II, administrada pela professora Rosana Cibely.
O projeto se consiste na realização de um algoritimo que manipula um tipo estruturado (Clientes) e mantém os clientes ordenados por meio de Counting Sort em um arquivo.
## Requisitos
O projeto deve:
- [x] Conter um tipo estruturados (Clientes) que possua os seguintes elementos: Nome, endereço, código do cliente.
- [x] O progrrama deve ordenar os clientes por código com o algoritmo Couting Sort.
- [x] Computar o tempo de execução do processo de ordenação.
- [x] Atualizar o arquivo texto para manter os clientes ordenados por código.
- [x] Informar a complexidade do algoritmo Counting Sort.
***
## Sumário
* [O que é o CountingSort](#o-que-é-o-counting-sort)
* [Como funciona o CountingSort](#como-funciona-o-counting-sort)
* [Fontes](#fontes)
* [Pseudocódigo](#pseudocódigo)
# O que é o Counting Sort?
Desenvolvido pelo cientista da computação Harold H. Sewarld em 1954, CoutingSort ou Ordenação por contagem é um algoritmo utilizado para ordenar um vetor de acordo com valores que são números inteiros positivos ou seja: é um algoritimo de Ordenar por inteiros.

Opera contando o número de objetos que possuem valores distintos e aplica a soma do prefixo nessas contagens para determinar as posições de cada valor na sequência de saída.
É bastante utilizado na sub-rotina do Radix Sort, outro algoritimo de classificação  
# Como funciona o Counting Sort?
1- Encontra-se o elemento máximo do vetor dado.
2- Inicializa-se um vetor novo considerando o elemento máximo anterior +1 com todos os elementos contidos dentro dele em 0. Esse vetor é utilizado para armazenar a conta dos elementos do vetor inicial. Esse novo vetor é o Vetor de Conta.
3- Em seguida, o Vetor de conta armazena a oconta de cada elemento de seu respectivo index. E soma se algum elemento do vetor orgiinal se repetir.
*Por exemplo, se o vetor dado na posição 1 tiver o número 10, o vetor de conta irá adicionar +1 na posição 10 dele. Se for encontrado o valor 10 novamente, então será adicionado novamente.
4- Encontra-se o contador de cada elemento do vetor original e do vetor de conta. 
*Caso o elemento 4 for encontrado, ele irá no index 4 do vetor de conta e irá subtrair 1, posicionando no local correspondente do vetor original.
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
O Pseudocódigo se consiste em um:
    - Um vetor contador com o número máximo (k) de elementos de um vetor que é analisado (input).
    - output que é um vetor de mesmo tamanho do vetor input e que será posto em retorno.
    - Um primeiro para (for) utilizado para ver as recorrencias do número do vetor original.
    - Um segundo para para armazenar o valor da contagem
    - Um terciero para atualizar os valores do vetor original. 
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

