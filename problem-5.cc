#include <iostream>
#include <cstdint>

struct Node
{
	uint64_t next_and_prev;	
	int value;

	Node(int v):next_and_prev(0),value(v){}
};

struct List
{
	Node *head;
	Node *tail;

	List():head(nullptr),tail(nullptr){}

	void Add(int value)
	{
		Node *new_node = new Node(value);
		if(head == nullptr)
		{
			head = new_node;
			tail = new_node;
			return;
		}
	}

private:
	Node *get_next_node()
	{

	}
};

int main()
{

}
