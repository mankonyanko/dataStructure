#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H
#include <iostream>
using namespace std;

struct d_node
{
	int value;
	d_node* prev;
	d_node* next;
};


class d_list
{
private:
	int node_cnt;
	d_node* head;
	d_node* tail;

public:
	d_list()
	{
		node_cnt = 0;
		head = NULL;
		tail = NULL;
	}
	d_node* make_node();
	void list_print();

	//idx is started from 1

	int list_cnt();
	void list_insert_head(int d_val);
	void list_insert_tail(int d_val);
	int list_insert_index(int d_val, int idx);

	void list_delete_head();
	void list_delete_tail();
	int list_delete_data(int d_val);
	int list_delete_index(int idx);

	d_node* list_search_index(int idx);
	d_node* list_search_data(int d_val);

	void list_clear();
	d_list* list_copy();
	void node_exchange(int idx);
};



#endif

