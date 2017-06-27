all:
	gcc -ggdb -c single_linked_list.c double_linked_list.c
	gcc -ggdb -c unit_test.c
	gcc -ggdb -o dstruct unit_test.o single_linked_list.o double_linked_list.o
clean:
	rm dstruct unit_test.o single_linked_list.o double_linked_list.o
