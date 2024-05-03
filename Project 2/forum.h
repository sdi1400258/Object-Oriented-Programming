#ifndef FORUM_H
#define FORUM_H

#include "date.h"
#include "dentro.h"
#include "thread.h"

#define OBJECT_FORUM_MESSAGES 1

const unsigned int threads = 10;
const unsigned int posts = 10;

using namespace std;

class Forum
{
		Data data;
		string titlos;
		Thread ** thread;
		Dentro * dentro;
		unsigned int threads;
	public:
		Forum(const string, const int);
		Forum(const Forum&);
		const unsigned int get_posts();
		void print(const int) const;
		void print(const unsigned int ) const;
		void print(const string) const;
		void print_taxinom();
		~Forum();

};

#endif
