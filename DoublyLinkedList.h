 #ifndef DataStructure_DoublyLinkedList_h
    #define DataStructure_DoublyLinkedList_h

    enum boolean {
        true = 1, false = 0
    };

    typedef enum boolean bool;
    
    /* */
    typedef struct Node {
        void *data;
        struct Node *next;
        struct Node *previous;
    }Node;

    /*Tail aponta para o final da lista
    e para informar o tamanho foi criado a variável size 
    */
   
    typedef struct DoublyLinkedList {
        Node *first;
        Node *tail;
        int size;
    }DoublyLinkedList;

    /*Por questões de legidibilidade, algumas funções são reutilizadas*/
    //no DoublyLinkedListTest.c:]
    //Qualquer função que alguem implementar
    //que retorne boleano e os tipos
    //das funções sejam iguais 
    

    //Aqui:
    //Criando um ponteiro de função 
    //que recebe como parâmetros dois ponteiros void
    //retornando bool

    //OBS:
    //Quando utilizar esse tipo "compare",
    //suponhe-se que o usuário criou 
    //essa função com o objetivo de comparar
    //dois dados, a vantagem é que a biblioteca
    //serve para qualquer tipo de dado
    typedef bool (*compare)(void*,void*);
    typedef void (*printNode)(void*);

    //Inicializa a lista
    //Caso fosse 
    void init(DoublyLinkedList *list);
    int enqueue(DoublyLinkedList *list, void *data);
    void* dequeue(DoublyLinkedList *list);
    void* first(DoublyLinkedList *list);
    void* last(DoublyLinkedList *list);
    int push(DoublyLinkedList *list, void *data);
    void* pop(DoublyLinkedList *list);
    void* top(DoublyLinkedList *list);
    bool isEmpty(DoublyLinkedList *list);

    //IndexOf
    //Devolver a posição baseado no dado
    //Aqui trabalha somente com o endereço dos dados
    //quem usar a biblioteca, informa o tipo de dado
    //Para resolver esse problema é criado um ponteiro
    //de função para devolver a posição baseado no dado

    //Registrador Contador de instrução, guarda o endereço da próxima instrução
    //Aquele endereço de memória pode ter o endereço de um dado
    //ou de uma função
    int indexOf(DoublyLinkedList *list,void *data, compare equal);

    //Quer saber endereço do dado guardado
    //da posição escolhida
    void* getPos(DoublyLinkedList *list,int pos);
    
    //função utilitária internamente na lista
    //retorna o endereço do Node
    //pela posição informada 
    Node* getNodeByPos(DoublyLinkedList *list,int pos);

    //inserir na posição dada pelo usuário
    //deve-se percorrer até a pos-1 para conseguir 
    //adicionar o novo nó
    int add(DoublyLinkedList *list, int pos, void *data);

    //adiciona a lista de origem na lista destino 
    //ou seja o tail da lista origem vai no início da lista destino
    //Depois início do destino aponta para o final da lista origem 
    //importante incrementar o size na lista de destino 
    int addAll(DoublyLinkedList *listDest, int pos, DoublyLinkedList *listSource);

    //remove o elemento baseado na posição
    void* removePos(DoublyLinkedList *list, int pos);
    bool removeData(DoublyLinkedList *list, void *data, compare equal);

     //exibe os dados de todos os nós da lista;
     void show(DoublyLinkedList *list, printNode print);
     
     //exibe a organização na memória de todos os nós da lista.
     void showMem(DoublyLinkedList *list);
   
    #endif