# Estrutura de Dados 2

Este repositório contém materiais, exemplos de código e implementações relacionadas à disciplina de **Estrutura de Dados 2**. A disciplina explora estruturas de dados avançadas e técnicas para manipulação eficiente de dados. Abaixo, você encontrará uma visão geral dos principais conceitos abordados.

## Conteúdos

### 1. Ponteiros
Ponteiros são variáveis que armazenam o endereço de memória de outra variável. Eles permitem a manipulação direta de memória, essencial para criar estruturas de dados dinâmicas, como listas encadeadas e árvores. Compreender ponteiros é fundamental para entender a alocação dinâmica de memória e como as estruturas de dados funcionam internamente.

### 2. Ponteiros Duplos
Ponteiros duplos são ponteiros que armazenam o endereço de outros ponteiros. Eles são frequentemente usados para manipular estruturas de dados complexas e para funções que precisam modificar o valor de um ponteiro passado como argumento. Por exemplo, em listas encadeadas, ponteiros duplos são utilizados para gerenciar a cabeça da lista dentro de funções que inserem ou removem elementos.

### 3. Doubly Linked List (Lista Duplamente Encadeada)
A **Lista Duplamente Encadeada** é uma estrutura onde cada nó contém um valor e dois ponteiros: um para o próximo nó e outro para o nó anterior. Isso permite a navegação em ambas as direções, facilitando operações de inserção e remoção de elementos em qualquer posição da lista. Essa estrutura é útil em situações onde é necessário um acesso bidirecional eficiente.

### 4. Generalized Linked List (Lista Encadeada Generalizada)
Uma **Lista Encadeada Generalizada** estende as listas encadeadas tradicionais ao permitir que cada elemento seja um átomo (um valor indivisível) ou uma sublista. É útil para representar dados hierárquicos e recursivos, como expressões matemáticas ou sistemas de arquivos.

### 5. Hashing e Tabelas Hash
**Hashing** é uma técnica para mapear dados de tamanho arbitrário para um tamanho fixo. **Tabelas Hash** utilizam funções de hash para indexar dados, permitindo buscas, inserções e remoções em tempo constante (O(1)) na maioria dos casos. Técnicas de tratamento de colisões, como encadeamento separado e endereçamento aberto, são cruciais para manter a eficiência.

### 6. Blockchain
**Blockchain** é uma estrutura de dados distribuída e imutável que armazena uma sequência de blocos encadeados, cada um contendo transações ou dados. Cada bloco possui um hash do bloco anterior, garantindo a integridade e segurança dos dados. Essa tecnologia é a base de criptomoedas como Bitcoin, mas tem aplicações em diversas outras áreas.

### 7. Árvore AVL
A **Árvore AVL** é uma árvore binária de busca autobalanceada onde a diferença de altura entre as subárvores de qualquer nó é, no máximo, 1. Esse balanceamento garante que as operações de busca, inserção e remoção sejam realizadas em tempo O(log n), tornando-a ideal para aplicações que exigem alta eficiência.

### 8. Árvore Binária
Uma **Árvore Binária** é uma estrutura de dados onde cada nó tem, no máximo, dois filhos. É a base para várias outras estruturas de dados, como árvores binárias de busca, árvores AVL e árvores rubro-negras. Árvores binárias são amplamente utilizadas em algoritmos de busca e ordenação.

### 9. Árvore Rubro-Negra
A **Árvore Rubro-Negra** é uma árvore binária de busca autobalanceada com regras adicionais que garantem um balanceamento flexível. Cada nó é rotulado como "vermelho" ou "preto", e o balanceamento é mantido com base em regras que limitam o número de nós vermelhos consecutivos. Isso assegura operações eficientes em tempo O(log n) com menos reestruturações do que as árvores AVL.

## Como Usar

### Compilação com Makefile

Este repositório inclui um `Makefile` para facilitar a compilação dos códigos. 


