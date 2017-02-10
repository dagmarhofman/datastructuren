all:
	gcc -c main.c 
	gcc -c single.linked.list.c
	gcc -o datastructuren main.o single.linked.list.o -ggdb