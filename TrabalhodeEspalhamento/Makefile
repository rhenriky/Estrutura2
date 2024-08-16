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
	@./arquivo
	@echo ======================================================