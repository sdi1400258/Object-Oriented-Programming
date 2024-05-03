#include <cstdlib>

#include "post.h"
#include "random.h"

using namespace std;

unsigned int Post::idlast = 0;


//const

Post::Post(const string titlos, const string dimiourgos, const string keimeno) : titlos(titlos), dimiourgos(dimiourgos), keimeno(keimeno)
{
		id = ++idlast;
		date = new Date(rand() & day_secs);

		#if(OBJECT_POST_MESSAGES)
			cout << "Dimiourgithike ena Post me id: " << this->id << ", me titlo: " << this->titlos << ", Dimiourgo: " << this->dimiourgos 
			<< ", Hmerominia: " << date->get_str() << endl;
		#endif
}

Post::Post(const Post& post) : id(post.id), titlos(post.titlos), dimiourgos(post.dimiourgos), keimeno(post.keimeno)
{
		this->date = new Date(*post.date);
		#if(OBJECT_POST_MESSAGES)
			cout << "Post me titlo: " << post.titlos << " antigrafike me epitixia." << endl;
		#endif
}

string Post::get_dimiourgos() const
{
	return this->dimiourgos;
}

unsigned int Post::getid() const
{
	return this->id;
}

unsigned int Post::getlastid()
{
	return idlast;
}

void Post::print() const
{
	cout << "\n#" << this->id << " , " << this->titlos << "\nKeimeno: " << this->keimeno << "\n Dimiourgithike apo : " << this->dimiourgos
		 << " stis " << date->get_str() << endl;

}

//ektipwsi gia kathe kommati

void Post::print(const int kommati) const
{
	if(kommati == POST_TITLOS)
	{
		cout << "\n ' " << titlos << " ' " <<endl;
		
	}
	else if(kommati == POST_DIMIOURGOS)
	{
		cout << "\n ' " << dimiourgos << " ' " << endl;
		
	}
	else if(kommati == POST_DATE)
	{
		cout << endl ;
		date->print();
		
	}
	else if(kommati == POST_KEIMENO)
	{
		cout << "\n ' " << keimeno << " ' " << endl;
		
	}
	else
	{
		cout << "Den uparxoun ektipwseis." << endl;
		cin.get();
		
	}

}


//destuct

Post::~Post()
{
	#if(OBJECT_POST_MESSAGES)
		cout << "Post me id : " << this->id << " tha diagrafei. " << endl;
	#endif
		delete date;
}

