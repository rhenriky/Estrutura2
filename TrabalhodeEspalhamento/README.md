# Estrutura de Dados 2
Repositório dados2

------------------------------------------------------
Projeto Espelhamento, Alunos: João Carlos, Rodrigo Henriky

# Visualização de Colisões em Tabelas Hash

## Descrição

Este projeto visa visualizar a dispersão de colisões em tabelas hash utilizando um conjunto de palavras da língua portuguesa. A visualização é feita na forma de uma matriz de cores, onde diferentes tonalidades indicam pontos de menor e maior colisão. O objetivo é comparar diferentes funções de hash para identificar a mais adequada para uma boa dispersão dos dados.

## Estrutura do Projeto

- `ListaDePalavrasPT.txt`: Arquivo de texto contendo uma lista de palavras em português.
- `arquivo.c`: Arquivo principal que executa o programa.
- `Hash.c` e `Hash.h`: Implementação e definição das funções da tabela Hash.
- `DoublyLinkedList.c` e `DoublyLinkedList.h`: Implementação e definição das funções de listas duplamente encadeadas.
- `hash_collisions.ppm`: Arquivo de saída gerado pelo programa que visualiza as colisões na tabela hash.

## Funções de Hash Implementadas

### Hash Linear

![Hash Linear](./imagem%20ppm/linear.png)


Conclusões: O hash linear, onde a função de hash utiliza `(i + 1)`, demonstrou o menor índice de colisão. A distribuição das colisões é mais uniforme, indicando que essa função é eficiente na dispersão das chaves pela tabela. Esse resultado sugere que a função de hash linear é eficaz para minimizar colisões e distribuir as palavras de forma mais equitativa na tabela.

### Hash Exponencial

![Hash Exponencial](./imagem%20ppm/peso%20exponencial.png)


Conclusões: O hash exponencial, onde a função de hash utiliza `(i^2)`, apresentou um grau médio de colisões, com vários espaços em branco na matriz. Isso indica que, embora essa função consiga dispersar algumas chaves eficientemente, ela ainda deixa muitas posições vazias, resultando em uma distribuição menos uniforme. A função de hash exponencial pode ser adequada para algumas aplicações, mas pode não ser a melhor escolha para garantir uma distribuição uniforme.

### Hash Sem Peso

![Hash Sem Peso](./imagem%20ppm/Hash%20sem%20peso.png.)


Conclusão: O hash sem peso, onde a função de hash simplesmente soma os valores ASCII dos caracteres, mostrou que as colisões estão mais concentradas no meio da matriz. Esse comportamento indica que a função de hash sem peso não é eficaz na dispersão das chaves, resultando em uma alta concentração de colisões em certas áreas da tabela. Portanto, esta função de hash pode não ser a melhor escolha quando se busca uma distribuição uniforme das chaves.

## Configuração e Execução

### Requisitos

- GCC (GNU Compiler Collection)
- Visualizador de imagens PPM ou ferramenta de conversão como ImageMagick

### Compilação

Para compilar o programa, use o seguinte comando:

```sh
gcc arquivo.c hash.c DoublyLinkedList.c -o arquivo

Para executar use make arquivo

[def]: ./Linear.png