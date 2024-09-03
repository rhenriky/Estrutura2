 clear: 
	@rm -f ArvoreAVL

ArvoreAVL: clear
	@echo ==========================
	@echo      PROGRAMA ArvoreAVL
	@echo ==========================
	@echo Compilando o programa ArvoreAVL
	@gcc  ArvoreAVLTest.c ArvoreAVL.c ArvoreAVL.h -o ArvoreAVL
	@echo Tornando o programa ArvoreAVL executável
	@chmod +x ArvoreAVL > /dev/null 2>&1
	@echo Executando o programa ArvoreAVL
	@
	./ArvoreAVL
	@echo ======================================================


clear: 
	@rm -f ArvoreVermelhaNegra

ArvoreVermelhaNegra: clear
	@echo ==========================
	@echo      PROGRAMA ArvoreVermelhaNegra
	@echo ==========================
	@echo Compilando o programa ArvoreVermelhaNegra
	@gcc  ArvoreVermelhaNegraTest.c ArvoreVermelhaNegra.c ArvoreVermelhaNegra.h -o ArvoreVermelhaNegra
	@echo Tornando o programa ArvoreVermelhaNegra executável
	@chmod +x ArvoreVermelhaNegra > /dev/null 2>&1
	@echo Executando o programa ArvoreVermelhaNegra
	@
	./ArvoreVermelhaNegra
	@echo ======================================================


clear: 
	@rm -f Blockchain

Blockchain: clear
	@echo ==========================
	@echo      PROGRAMA Blockchain
	@echo ==========================
	@echo Compilando o programa Blockchain
	@gcc  BlockchainTest.c Blockchain.c Blockchain.h sha-256.h -o Blockchain
	@echo Tornando o programa Blockchain executável
	@chmod +x Blockchain > /dev/null 2>&1
	@echo Executando o programa Blockchain
	@
	./Blockchain
	@echo ======================================================


clear: 
	@rm -f arquivo

arquivo: clear
	@echo ==========================
	@echo      PROGRAMA arquivo
	@echo ==========================
	@echo Compilando o programa arquivo
	@gcc  DoublyLinkedList.c arquivo.c Hash.c Hash.h -o arquivo
	@echo Tornando o programa arquivo executável
	@chmod +x arquivo > /dev/null 2>&1
	@echo Executando o programa arquivo
	@
	./arquivo
	@echo ======================================================

clear:
	@rm -f Hash

Hash: clear
	@echo ==========================
	@echo      PROGRAMA Hash
	@echo ==========================
	@echo Compilando o programa Hash
	@gcc DoublyLinkedList.c DoublyLinkedList.h HashTest.c Hash.c Hash.h  -o Hash
	@echo Tornando o programa Hash executável
	@chmod +x Hash > /dev/null 2>&1
	@echo Executando o programa Hash
	@echo ======================================================

clear:
	@rm -f ponteiro	

ponteiro: clear
	@echo
	@echo ==========================
	@echo      PONTEIRO SIMPLES
	@echo ==========================
	@echo Compilando o programa ponteiros
	gcc ponteiro.c -o ponteiro
	@echo Tornando o arquivo executável
	chmod +x ponteiro
	@echo Executando o programa ponteiros
	@echo ======================================================
	./ponteiro


clear:
	@rm -f ponteiroduplo	

ponteiroduplo: clear
	@echo
	@echo ==========================
	@echo      PONTEIRO DUPLO
	@echo ==========================
	@echo Compilando o programa ponteiro duplo
	gcc ponteiroduplo.c -o ponteiroduplo
	@echo Tornando o arquivo executável
	chmod +x ponteiroduplo
	@echo Executando o programa ponteiro duplo
	@echo ======================================================
	@echo
	./ponteiroduplo
	
clear:
	@rm -f DoublyLinkedList

DoublyLinkedList: clear
	@echo ==========================
	@echo      PROGRAMA DoublyLinkedList
	@echo ==========================
	@echo Compilando o programa DoublyLinkedList
	@gcc DoublyLinkedList.c DoublyLinkedList.h DoublyLinkedListTest.c   -o DoublyLinkedList
	@echo Tornando o programa DoublyLinkedList executável
	@chmod +x DoublyLinkedList > /dev/null 2>&1
	@echo Executando o programa DoublyLinkedList
	@./DoublyLinkedList
	@echo ======================================================	

clear:
	@rm -f LinkedList

LinkedList: clear
	@echo ==========================
	@echo      PROGRAMA LinkedList
	@echo ==========================
	@echo Compilando o programa LinkedList
	@gcc LinkedList.c LinkedList.h LinkedListTest.c -o LinkedList
	@echo Tornando o programa DoublyLinkedList executável
	@chmod +x LinkedList > /dev/null 2>&1
	@echo Executando o programa LinkedList
	@./LinkedList
	@echo ======================================================

	clear:
	@rm -f LinkedList

GeneralizedLinkedList: clear
	@echo ==========================
	@echo      PROGRAMA GeneralizedLinkedList
	@echo ==========================
	@echo Compilando o programa GeneralizedLinkedList
	@gcc GeneralizedLinkedList.c GeneralizedLinkedList.h GeneralizedLinkedListTest.c -o GeneralizedLinkedList
	@echo Tornando o programa GeneralizedLinkedList executável
	@chmod +x GeneralizedLinkedList > /dev/null 2>&1
	@echo Executando o programa GeneralizedLinkedList
	@./GeneralizedLinkedList
	@echo ======================================================		