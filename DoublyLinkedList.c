#include <stdio.h>
#include <stdlib.h>
#include "DoublyLinkedList.h"


//Inicializando a lista
void init(DoublyLinkedList *list){
   
   
    //Reservando espaço com o malloc
    //convertendo para ponteiro do tipo Node
    Node  * trashNode = (Node *) (malloc(sizeof(Node)));

    //Verificando o sucesso da alocação
    //Tendo em vista que o malloc retorna NULL em caso de erro
    if(trashNode == NULL)printf("Erro ao alocar o trashNode");
     
    //Apontando o dado para NULL
    //E o next para ele mesmo
    trashNode->data = NULL;
    trashNode->next = trashNode;
    trashNode->previous = trashNode;

    //Tail aponta para o trashnode;
    list->tail = trashNode;

    list->size = 0;

}
//Verificar se a lista está vazia
bool isEmpty(DoublyLinkedList *list){

    //Se o tamanho é igual a zero a lista está vazia
    return (list->size == 0);
}

//inserir na fila
int enqueue(DoublyLinkedList *list, void *data){

    /*Adicina-se sempre no final, que é o tail.
    Quando deseja-se acessar o início, digita-se list->tail->next*/

    //Uma nova área da memória, suficiente para armazenar um nó
    //é  reservada usando malloc
    Node * new_node = (Node *)(malloc(sizeof(Node)));
    if(new_node == NULL) return -2;

        
        new_node->data = data;
        //new_node->next aponta para o início(trashNode)
        new_node->next = list->tail->next;

        //Previous aponta para o último
        new_node->previous = list->tail;
       
        //Next do penúltimo da fila, deixa de apontar para o ínicio
        //e aponta para o novo nó
        list->tail->next = new_node; 
        
        //tail aponta para o novo nó 
        //tail->next e tail->previous são atualizados 
        //com os endereços do next e previous
        //contido no novo nó
        list->tail = new_node;
        
        //O previous do início(trashNode) deixa de apontar
        //para o tail antigo e aponta para o novo,
        //que contém o novo nó.
        list->tail->next->previous = list->tail;
         
        list->size++;

    //Representa a quantidade de elementos inseridos
    return 1;
}

//remover da fila
void * dequeue(DoublyLinkedList *list){

       if(isEmpty(list))return NULL;
       
      /*Para remover, deve-se retirar do início*/
      Node * auxFirst;
      Node * trash;
      if(auxFirst == NULL)return NULL;
      if(trash == NULL)return NULL;

 
        //trash aponta para o inicio que possui o trashNode
        trash = list->tail->next;
        //o auxFirst aponta para o próximo Nó válido
        auxFirst = trash->next;
        //o next aponta para o elemento depois do auxFirst
        trash->next = auxFirst->next;
        //aux->next->previous aponta para o que está antes dele
        auxFirst->next->previous = trash;

        auxFirst->next = NULL;
        auxFirst->previous = NULL;

        //Cria-se um var data para liberar o ponteiro aux
        void* data = auxFirst->data;
        free(auxFirst);

        list->size--;
        return data;
}

int push(DoublyLinkedList *list, void *data){
    /*Como a função enqueue é igual a push*/
    return enqueue(list,data);
}

void * pop(DoublyLinkedList *list){

   //Remove sempre no final

    if(isEmpty(list)) return NULL;
        
        Node * remove;
        Node * aux;

        //remove aponta para o último
        remove = list->tail;
        //A vantagem é poder ter o endereço do anterior
        //sem transitar pela pilha
        aux = remove->previous;
        //O  next do penúltimo, aponta para o início
        aux->next = list->tail->next;
        //tail aponta o penúltimo, agora se torna o último
        list->tail = aux;

        //o previous do início aponta para o último
        list->tail->next->previous = list->tail;
        
        remove->next = NULL;
        remove->next = NULL;

        //nó é removido e o dado 
        //atribuido para outra variável
        void * data = remove->data;
        free(remove);
        
        list->size--;

          return data;
}

//consulta o último item da pilha
void* top(DoublyLinkedList *list){
    //Retorna NULL caso a lista esteja fazia
    //Senão retorna o endereço do dado
    return (isEmpty(list))?NULL:list->tail->data;
}

//consulta o primeiro item da lista
void* first(DoublyLinkedList *list){

    //Retorna NULL caso a lista esteja fazia
    //Senão retorna o endereço do dado
    return (isEmpty(list))?NULL:list->tail->next->next->data;
}
//Consulta o último item da lista
void* last(DoublyLinkedList *list){
    //Como o objetivo é retornar o último
    //a função Top é reaproveitada
    return top(list);

    
}

 int add(DoublyLinkedList *list, int pos, void *data){

        //Se a posição é menor ou igual a zero 
        //o valor já é inserido na primeira posição
        if(pos <= 0)return push(list,data);

        //senão, encontre-se o nó da posição anterior
        //da que foi informada
        Node * aux = getNodeByPos(list,(pos-1));
        if(aux == NULL)return 0;

        //Novo nó é alocado
        Node * new_node =(Node*) malloc(sizeof(Node));

        new_node->data = data;
        //O next do novo nó aponta para o next do aux
        //onde é a posição informada
        new_node->next = aux->next;
        //O anterior do nó apontado, agora aponta
        //para o novo nó
        aux->next->previous = new_node;
        //o anterior do novo nó aponta para o aux
        new_node->previous = aux;
        //o prox do aux aponta para o novo nó
        aux->next = new_node;

        list->size++;

        //corresponde ao número de elementos adicionados 
        return 1;
 }

  Node* getNodeByPos(DoublyLinkedList *list, int pos){

        //Se a lista estiver vazia ou a posição foi maior ou igual ao tamanho
        //retorna NULL
        if(isEmpty(list) || pos > list->size) return NULL;


        //Se caso não acontecer, continua-se e o aux aponta para o início
        //,ou seja, após o trashNode
        Node * aux = list->tail->next;

        //O contador é criado
        //enquanto a condição do meio acontecer o loop continua
        //Aux aponta para os nós e incrementa o count
        int count;   
        for(count = 0; (aux != list->tail && pos != count); count++, aux = aux->next);

    
        return aux;
 }

 void* getPos(DoublyLinkedList *list, int pos){
      //Nó é criado para receber o endereço do nó 
      //que será procurando pelo getNodeByPos
      Node * dataPos = getNodeByPos(list,pos);

      //retorna-se NULL caso o dado não foi encontrado
      //senão, retorna o dado do nó
        
      return (dataPos == NULL)? NULL: dataPos->data;
  }

//retorna o index do dado informado
 int indexOf(DoublyLinkedList *list, void *data, compare equal){
     
     //se a lista está vazia retorna -1
     if(isEmpty(list))return -1;
     
     //se o primeiro item do início(após o trashNode) 
     //é igual ao dado então retorna a pos 1
     if(equal(list->tail->next->next->data,data)) return 1;

     //Se é igual ao último então retorna o tamanho
     if(equal(list->tail->data,data)) return list->size;
     
     //Senão, o aux é criado e a lista é percorrida
     //a partir do segundo elemento.
     int i;

     Node * aux;
     //Aux aponta para o início(trashNode)
     aux = list->tail->next;
     aux = aux->next;
     aux = aux->next;
     
     //Percorre até o aux apontar para o início(trashNode)
     //ou até o valor for igual
     for(i=2;(aux != list->tail->next && !equal(aux->data,data)); i++, aux = aux->next);
    
    //Se o aux aponta o início, então percorreu a lista sem encontrar nada
    return (aux == list->tail->next)?-1:i;
 }

 //remove o nó baseado no dado
 


  int addAll(DoublyLinkedList *listDest, int pos, DoublyLinkedList *listSource){

         if(isEmpty(listDest) ||  pos > listDest->size) return -1;
         if(isEmpty(listSource) ||  pos > listSource->size) return -2;


         if(pos < 1)return -3;

            //Antes de tudo é necessário remover o trashNode do source
            Node * trashNodeSource = listSource->tail->next;

            listSource->tail->next = trashNodeSource->next;
            trashNodeSource->previous = listSource->tail;
            
            trashNodeSource->next = NULL;
            trashNodeSource->previous = NULL;
            free(trashNodeSource);

            
            Node * aux = getNodeByPos(listDest,(pos-1));
            Node * inicioSource = listSource->tail->next;

            listSource->tail->next = aux->next;
            listSource->tail->next->previous = aux;
            
            aux->next->previous = listSource->tail;
            aux->next = inicioSource;

        
     listDest->size += listSource->size;
     return listSource->size;
      
  }



void* removePos(DoublyLinkedList *list, int pos){
    
    if(isEmpty(list) || pos > list->size || pos < 1) return NULL;

    Node * aux = getNodeByPos(list,(pos-1));
    if(aux == NULL) return NULL;

    Node * removeData = aux->next;
    aux->next = removeData->next;
    removeData->next->previous = aux;
    if(pos == list->size)list->tail = aux;

    void *data = removeData->data;
    
    free(removeData);

    list->size--;
    return data;
}

bool removeData(DoublyLinkedList *list, void *data, compare equal){

     //testa se a lista está vazia
     if(isEmpty(list))return false;

    //Se o dado do inicio for igual 
     if(equal(list->tail->next->next->data,data)){

         Node * removeNode;
         //removeNode aponta para o início(Após trashNode)
         removeNode = list->tail->next->next;
         //next do início(trashNode) aponta para o próx nó
         list->tail->next->next = removeNode->next;
         removeNode->next->previous = list->tail->next;

         removeNode->next = NULL;
         free(removeNode->data);
         free(removeNode);

         list->size--;

         return true;
     }

        //senão
         Node * aux;
         Node * removeNode;

         aux = list->tail->next;

        //A lista é percorrida até chegar ao final ou até achar o dado
        for(int i = 0;(aux->next != list->tail->next && !equal(aux->next->data,data)); i++, aux = aux->next);

        //caso a lista for percorrida até voltar ao início, retorna-se falso   
        if(aux->next == list->tail->next)return false;
       
        //caso achou algum valor:
        removeNode = aux->next;

        //Se for o último, o Tail tem que apontar para o penúltimo
        if(aux->next == list->tail)list->tail = aux;
        removeNode->next->previous = aux;
        aux->next = removeNode->next;
        
       
        removeNode->next = NULL;
        free(removeNode->data);
        free(removeNode);
        list->size--;  

        return true;
 }

 void show(DoublyLinkedList *list, printNode print){

     Node * aux = list->tail->next->next;

     printf("\nImpressão dos dados de cada nó");
     printf("\n------------------------------\n");

     while(aux != list->tail->next){
          print(aux->data);
          aux = aux->next;
      }

     printf("------------------------------\n");
 }

 void showMem(DoublyLinkedList *list){

     Node * aux = list->tail->next->next;

     printf("\nImpressão dos endereços de cada nó");
     printf("\n-----------------------------------------------------------------\n");
    //  printf("%s -\t \t \t %s -\t \t \t \b %s ","Node", "Next", "Previous\n");
     printf("%5s  %22s  %12s %13s %7s %13s","Node:", "Next","-", "Previous","-","Data\n\n");
         while (aux != list->tail->next)
         {
             printf("%p:   \t %p   -\t %p -\t %p\n ",aux,aux->next,aux->previous,aux->data);
             aux = aux->next;
         }
      printf("\n-----------------------------------------------------------------\n");

 }