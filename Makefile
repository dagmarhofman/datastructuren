all:
	gcc -ggdb -c single_linked_list.c double_linked_list.c stack.c queue.c
	gcc -ggdb -c main.c
	gcc -ggdb -o dstruct main.o single_linked_list.o double_linked_list.o stack.o queue.o
clean:
	rm dstruct main.o single_linked_list.o double_linked_list.o stack.o queue.o
