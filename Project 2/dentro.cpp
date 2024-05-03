#include "dentro.h"
#include "list.h"

using namespace std;

struct Dentro::Node
{
	string dimiourgos;
	Lista lista;
	Node * left;
	Node * right;
	Node(const string dimiourgos, Node * left = NULL, Node * right = NULL) : dimiourgos(dimiourgos), left(left), right(right)
	{
		#if(OBJECT_DENTRO_MESSAGES)
		{
			cout << "Dentro::Node[" << this << "] Node me dimiourgo: " << dimiourgos << " dimiourgithike " << endl;

		}
		#endif
	}
	Node(const Node& node) :dimiourgos(node.dimiourgos), lista(node.lista), left(NULL), right(NULL)
	{
		#if(OBJECT_DENTRO_MESSAGES)
		{
			cout << "Dentro::Node[" << this << "] Node me dimiourgo: " << dimiourgos << " dimiourgithike me antigrafi" << endl;

		}
		#endif
	}

};


void Dentro::Nodeprint(Node * n) const
{
	if(n != NULL)
	{
		Nodeprint(n->left);
		cout << "'" << n->dimiourgos << " exei " << n->lista.get_size() << " posts" << endl;
		n->lista.print();
		Nodeprint(n->right);
	}
}

void Dentro::insertRec(Node *n, const Post& post)
{
	const string dimiourgos = post.get_dimiourgos();
	if(n != NULL)
	{
		const int x = n->dimiourgos.compare(dimiourgos);
		if(x > 0)
		{
			if(n->left !=NULL)
			{
				insertRec(n->left, post);
			}
			else
			{
				n->left = new Node(dimiourgos);
			
				#if(OBJECT_DENTRO_MESSAGES)
				{
					cout << "left[" << n->left << "]. Neo Dentro::Node me dimiourgo: " << dimiourgos << "dimiourgithike" <<endl;
				}
				#endif
				n->left->lista.pushfront(post);
			}
		}
		else if(x == 0)
		{
			#if(OBJECT_DENTRO_MESSAGES)
			{
				cout << "Node me dimiourgo: " << dimiourgos << "iparxei idi! Lista::Insert post" << endl;

			}
			#endif
			n->lista.pushfront(post);
		}
	}
	else
	{
		root = new Node(dimiourgos);
		#if(OBJECT_DENTRO_MESSAGES)
		{
			cout < "Root[" << root << "] Ena neo Dentro::Node me dimiourgo: " << dimiourgos << "dimiourgithike" << endl;
		}
		#endif
		root->lista.pushfront(post);
	}
}


void Dentro::insertRec(Node *n, Node * target)
{
	const string dimiourgos = target->dimiourgos;
	if(n != NULL && target != NULL)
	{
		const int x = n->dimiourgos.compare(dimiourgos);
		if(x>0)
		{
			if(n->left != NULL)
			{
				insertRec(n->left, target);
			}
			else
			{
				n->left = new Node(*target);
				
				#if(OBJECT_DENTRO_MESSAGES)
				{
					cout << "Left[" << n->left << "] Ena neo Dentro::Node me dimiourgo: " << dimiourgos << "dimiourgithike" << endl;
				}
				#endif
			}
		}
		else if(x < 0)
		{
			if(n->right != NULL)
			{
				insertRec(n->right, target);
	
			}
			else
			{
				n->right = new Node(*target);
				#if(OBJECT_DENTRO_MESSAGES)
				{
					cout << "Right[" << n->right << "] Ena neo Dentro::Node me dimiourgo: " << dimiourgos << "dimiourgithike " << endl;
				}
				#endif
			}
		}
		else if(x == 0)
		{
			#if(OBJECT_DENTRO_MESSAGES)
			{
				cout << "Node me dimiourgo " << dimiourgos << " iparxei idi. [n->lista.append] gia " <<target->lista.get_size() << " post " << endl;
			}
			#endif
			n->lista.append(target->lista);
		}
	}
}



void Dentro::mergeRec(Node * target)
{
	if(target != NULL)
	{
		mergeRec(target->left);
		mergeRec(target->right);
		insertRec(this->root, target);
	}
}

void Dentro::diagrafi(Node * node)
{
	if(node != NULL)
	{
		diagrafi(node->left);
		diagrafi(node->right);
		delete node;
	}
}

Dentro::Dentro(const Thread& thread) : root(NULL)
{
	const unsigned int posts = thread.get_posts();
	for(unsigned int i = 0; i < posts; i++)
	{
		insertRec(root, thread.get_post(i));
	}
	#if(OBJECT_DENTRO_MESSAGES)
	{
		cout << " dimiourgithike ena dentro" << endl;
	}
	#endif
}

void Dentro::enhance(const Dentro& dentro)
{
	mergeRec(dentro.root);
}

void Dentro::print() const
{
	cout << "\n Ektipwsi twn dimiourgwn alfavitika " << endl;
	Nodeprint(this->root);
	cout << endl;
}

Dentro::~Dentro()
{
	diagrafi(root);
	#if(OBJECT_DENTRO_MESSAGES)
	{
		cout << "Diagrafike ena dentro" << endl;

	}
	#endif
}