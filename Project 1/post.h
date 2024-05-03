#ifndef POST_H
#define POST_H

#include <iostream>
#include <string>

#include "data.h"
#include "date.h"

#define OBJECT_POST_MESSAGES 1

#define POST_TITLOS 1
#define POST_DIMIOURGOS 2
#define POST_DATE 3
#define POST_KEIMENO 4

using namespace std;

class Post{
		unsigned int id;
		static unsigned int idlast;
		string titlos;
		string dimiourgos;
		Date * date;
		string keimeno;
	public:
		Post(const string, const string, const string);
		Post(const Post&);
		string get_dimiourgos() const;
		unsigned int getid() const;
		static unsigned int getlastid();
		void print() const;
		void print(const int) const;
		~Post();
};

#endif