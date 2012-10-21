all : btree

btree : btree.c
	gcc -g -o btree btree.c
