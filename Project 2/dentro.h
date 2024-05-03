#ifndef DENTRO_H
#define DENTRO_H

#include <iostream>
#include <string>

#define OBJECT_DENTRO_MESSAGES 0

#include "thread.h"

class Dentro{
		struct Node;
		Node * root;
		void Nodeprint(Node *) const;
		void insertRec(Node *, const Post&);
		void insertRec(Node *, Node *);
		void mergeRec(Node *);
		void diagrafi(Node *);
	public:
		Dentro(const Thread&);
		void enhance(const Dentro&);
		void print() const;
		~Dentro();
};

#endif