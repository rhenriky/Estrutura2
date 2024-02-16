all: clear lista

lista: clear
	@echo "copilando lista"
	gcc LinkedList.h LinkedList.c LinkedListTest.c -o lista

clear:
	rm -f lista > /dev/null 2>&1

help:
