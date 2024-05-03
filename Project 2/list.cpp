#include <iostream>
#include <string>

#include "list.h"

struct Lista::Node
{
	const Post& post;
	Node * epomeno;
	Node(const Post &post, Node * epomeno = NULL) : post(post), epomeno(epomeno)
	{
		#if(OBJECT_LISTA_MESSAGES)
			cout << "Lista::Node[" << this << "]: Node me post: " << post.getid() << " dimiourgithike." << endl;
		#endif
	}

	Node(const Node& node, Node * epomeno = NULL) : post(node.post), epomeno(epomeno)
	{
		#if(OBJECT_LISTA_MESSAGES)
			cout << "Lista::Node[" << this << "]: Node me post: " << post.getid() << " dimiourgithike me antigrafi." << endl;
		#endif
	}

};

Lista::Lista() : start(NULL), size(0)
{
	#if(OBJECT_LISTA_MESSAGES)
		cout << "Dimiourgithike mia lista" <<endl;
	#endif
}

Lista::Lista(const Lista& lista) :start(NULL), size(0)
{
	append(lista);
	#if(OBJECT_LISTA_MESSAGES)
		cout << "Dimiourgithike lista me antigrafi" << endl;
	#endif
}

const unsigned int Lista::get_size()
{
	return size;
}

void Lista::pushfront(Node * node)
{
	Node * n = new Node (*node, start);
	start = n;
	size++;
}

void Lista::pushfront(const Post& post)
{
	Node * node = new Node(post, start);
	start = node;
	size++;
}

const bool Lista::pop(const unsigned int index)
{
	if(index >= size)return false;
	if(index == 0)
	{
		Node * temp = start;
		start = start->epomeno;
		delete temp;
	}
	else
	{
		Node * temp = start;
		Node * temp2 = NULL;
		for(unsigned int s = 0; s <= index - 1; s++)
		{
			temp = temp->epomeno;
			temp2 = temp->epomeno;
			if(temp->epomeno != NULL)
				temp->epomeno = temp->epomeno->epomeno;
			else
				temp->epomeno = NULL;
		}
		delete temp2;

	}
	size--;
	return true;

}

void Lista::append(const Lista& list)
{
	Node * e = start;
	while (e != NULL)
	{
		pushfront(e);
		e = e->epomeno;
	}
}

void Lista::print()
{
	Node * e = start;
	for(unsigned int i = 0; i < size; i++)
	{
		if(e != NULL)
		{
			e->post.print();
			e = e->epomeno;
		}
	}
}

Lista::~Lista()
{
	Node * t1, *t2;
	t1 = start;
	while(t1 !=NULL)
	{
		t2 = t1;
		t1 = t1->epomeno;
		delete t2;
	}
	#if (OBJECT_LISTA_MESSAGES)
		cout << "Diagrafike i lista" << endl;
	#endif
}



