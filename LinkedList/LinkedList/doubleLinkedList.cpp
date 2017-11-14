#include "doubleLinkedList.h"

d_node* d_list::make_node()
{
	d_node* node = new d_node;
	node->value = 0;
	node->prev = NULL;
	node->next = NULL;
	return node;
}

/*
d_list* d_list::list_init()
{
d_list* list = new d_list;
list->node_cnt = 0;
list->head = NULL;
list->tail = NULL;
return list;
}
*/
void d_list::list_print()
{
	d_node* cursor = head;
	int cnt_temp = node_cnt;
	while (node_cnt != 0)
	{
		cout << cursor->value << ' ';
		cursor = cursor->next;
		node_cnt--;
	}
	node_cnt = cnt_temp;
	cout << "\ndone!" << endl;
}

int d_list::list_cnt()
{
	return node_cnt;
}

void d_list::list_insert_head(int d_val)
{
	d_node* New = make_node();
	New->value = d_val;

	if (node_cnt != 0)
	{
		head->prev = New;
		New->next = head;
		head = New;
	}
	else
	{
		head = New;
		tail = New;
	}
	node_cnt++;
}

void d_list::list_insert_tail(int d_val)
{
	d_node* New = make_node();
	New->value = d_val;

	if (node_cnt != 0)
	{
		tail->next = New;
		New->prev = tail;
		tail = New;
	}
	else
	{
		head = New;
		tail = New;
	}
	node_cnt++;
}

int d_list::list_insert_index(int d_val, int idx)
{
	d_node* New = make_node();
	New->value = d_val;

	d_node* cursor = NULL;

	if (node_cnt != 0)
	{
		cursor = head;
		for (int i = 0; i < idx - 1; i++)
		{
			if (cursor->next != NULL)
				cursor = cursor->next;
			else
			{
				cout << "can not found index in list" << endl;
				return 1;
			}
		}
		New->prev = cursor->prev;
		New->next = cursor;
		New->prev->next = New;
		New->next->prev = New;


	}
	else
	{
		cout << "blank list" << endl;
		return 1;
	}

	node_cnt++;
	return 0;
}

void d_list::list_delete_head()
{
	d_node* cursor = NULL;

	if (head != NULL)
	{
		if (head->next != NULL)
		{
			cursor = head;
			head = head->next;
			head->prev = NULL;
			delete cursor;
		}
		else
		{
			delete head;
			head = NULL;
			tail = NULL;
		}
	}
	else
		cout << "had no head :(" << endl;
	node_cnt--;
}

void d_list::list_delete_tail()
{
	d_node* cursor = NULL;

	if (head != NULL)
	{
		if (tail->prev != NULL)
		{
			cursor = tail;
			tail = tail->prev;
			tail->next = NULL;
			delete cursor;

		}
		else
		{
			delete tail;
			head = NULL;
			tail = NULL;
		}
	}
	else
		cout << "had no tail :(" << endl;
	node_cnt--;
}

int d_list::list_delete_data(int d_val)
{
	d_node* cursor = head;

	if (node_cnt != 0)
	{
		cursor = head;
		while (cursor != NULL)
		{
			if (cursor->value == d_val)
				break;
			else
				cursor = cursor->next;
		}

		if (cursor == NULL)
			return 1;

		if (cursor == head)
		{
			head = head->next;
			head->prev = NULL;
			delete cursor;
		}
		else if (cursor == tail)
		{
			tail = tail->prev;
			tail->next = NULL;
			delete cursor;
		}
		else
		{
			cursor->next->prev = cursor->prev;
			cursor->prev->next = cursor->next;
			delete cursor;
		}

	}
	else
		cout << "blank list" << endl;

	node_cnt--;
	return 0;
}

int d_list::list_delete_index(int idx)
{
	d_node* cursor = head;

	int i = 0;

	if (node_cnt != 0)
	{
		cursor = head;
		for (i = 0; i<idx - 1; i++)
		{
			if (idx > node_cnt && idx <= 0)
			{
				cout << "index is wrong" << endl;
				return 1;
			}
			else
				cursor = cursor->next;
		}

		if (cursor == head)
		{
			head = head->next;
			head->prev = NULL;
			delete cursor;
		}
		else if (cursor == tail)
		{
			tail = tail->prev;
			tail->next = NULL;
			delete cursor;
		}
		else
		{
			cursor->next->prev = cursor->prev;
			cursor->prev->next = cursor->next;
			delete cursor;
		}

	}
	else
		cout << "blank list" << endl;

	node_cnt--;

	return 0;
}

d_node* d_list::list_search_index(int idx)
{
	int i = 0;
	d_node* cursor = head;

	if (node_cnt != 0 && 0 < idx && idx <= node_cnt)
	{
		for (i = 0; i < idx - 1; i++)
			cursor = cursor->next;
	}
	else
	{
		cout << "blank list or wrong index" << endl;
		return NULL;
	}
	return cursor;
}

d_node* d_list::list_search_data(int d_val)
{
	d_node* cursor = head;

	if (node_cnt != 0)
	{
		while (cursor != NULL)
		{
			if (cursor->value == d_val)
				return cursor;
			else
				cursor = cursor->next;
		}
		cout << "cant search a node with input value" << endl;
		return NULL;
	}
	else
	{
		cout << "blank list" << endl;
		return NULL;
	}
}
void d_list::list_clear()
{
	d_node* cursor = tail;

	while (node_cnt != 1)
	{
		tail = cursor->prev;
		delete cursor;
		cursor = tail;
		node_cnt--;
	}
	delete head;

	head = NULL;
	tail = NULL;
	node_cnt = 0;

}

d_list* d_list::list_copy()
{
	d_list* copied = new d_list;
	d_node* cursor = head;

	while (cursor != NULL)
	{
		copied->list_insert_tail(cursor->value);
		cursor = cursor->next;
	}

	return copied;
}

void d_list::node_exchange(int idx)
{
	d_node* cursor = list_search_index(idx);

	if (cursor->next != tail)
	{
		cursor->next = cursor->next->next;
		cursor->next->prev->prev = cursor->prev;
		cursor->next->prev->next = cursor;
		cursor->prev = cursor->next->prev;
		cursor->next->prev = cursor;
		cursor->prev->prev->next = cursor->prev;

	}

}




