#ifndef DATA_H
#define DATA_H

#include <string>

using namespace std;

class Data
{
		static const string Themata[];
		static const string Dimiourgoi[];
		static const string Titloi[];
		static const string Keimena[];

	public:
		const string thema(int) const;
		const string dimiourgos() const;
		const string titlos() const;
		const string keimeno() const;

};

#endif