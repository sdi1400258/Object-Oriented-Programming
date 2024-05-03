#ifndef LIST_H
#define LIST_H

#define OBJECT_LISTA_MESSAGES 0

#include "post.h"

class Lista{
		struct Node;
		Node * start;
		unsigned int size;
	public:
		Lista();
		Lista(const Lista&);
		const unsigned int get_size();
		void pushfront(const Post& post);
		void pushfront(Node *);
		const bool pop(const unsigned int);
		void append(const Lista&);
		void print();
		~Lista();
};

#endif