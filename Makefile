clear: 
	@rm -f arquivo

arquivo: clear
	@echo ==========================
	@echo      PROGRAMA arquivo
	@echo ==========================
	@echo Compilando o programa arquivo
	@gcc hash.h hash.c arquivo.c -o arquivo
	@echo Tornando o programa arquivo executável
	@chmod +x arquivo > /dev/null 2>&1
	@echo Executando o programa arquivo
	@./arquivo
	@echo ======================================================
