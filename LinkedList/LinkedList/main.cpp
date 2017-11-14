#include <stdio.h>
#include "doubleLinkedList.h"

int main()
{

	
	d_list* mylist = new d_list;
	mylist->list_insert_head(10);
	mylist->list_insert_head(8);
	mylist->list_insert_head(7);
	mylist->list_insert_head(5);
	mylist->list_print();

	mylist->node_exchange(2);
	mylist->list_print();

}


