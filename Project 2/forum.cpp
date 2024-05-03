#include <iostream>
#include <string>
#include <cstdlib>

#include "forum.h"

using namespace std;

//Const

Forum::Forum(const string titlos, const int threads = 0) : titlos(titlos), threads(threads)
{
		thread = new Thread*[this->threads];
		for(unsigned int i = 0; i < this->threads; i++)
		{
			thread[i] = new Thread(data, data.thema(i), data.dimiourgos(), rand() & posts + 1);
		}
		#if (OBJECT_FORUM_MESSAGES)
			cout << "Titlos Forum: " << this->titlos << " dimiourgithike." << endl;
		#endif

}

//antigrafi const

Forum::Forum(const Forum& forum) : titlos(forum.titlos), data(forum.data)
{
		threads = forum.threads;
		thread = new Thread*[forum.threads];
		for(unsigned int i = 0; i < forum.threads; i++)
		{
			thread[i] = new Thread(*forum.thread[i]);
		}
		#if (OBJECT_FORUM_MESSAGES)
			cout << "To Forum me titlo: " << forum.titlos << " antigrafike." << endl;
		#endif

}


const unsigned int Forum::get_posts()
{
	return Post::getlastid();
}


void Forum::print(const int action) const
{
	cout << " To Forum me titlo " << titlos << " \n Ta Nimata: " << endl;
	for(unsigned int i =0; i < threads; i++)
	{
		if (action == T_THEMA){
			thread[i]->print(T_THEMA);
			
		}
		else if(action == T_DIMIOURGOS){
			thread[i]->print(T_DIMIOURGOS);
			
		}
		else if(action == T_DATE){
			thread[i]->print(T_DATE);
			
		}
		else if(action == T_POSTS){
			thread[i]->print(T_POSTS);
			
		}
		else{
			thread[i]->print();
			
		}
	}
}

void Forum::print(const unsigned int selectedid) const{
	for(unsigned int i = 0; i < this->threads; i++){
		thread[i]->print(selectedid);
	}
}

void Forum::print(const string thema) const{
	cout << "Anazitisi gia : " << thema << " nima." << endl;
	for(unsigned int i=0; i < threads; i++)
	{
		if(thread[i]->get_thema().compare(thema) == 0)
		{
			thread[i]->print();
		}
	}
}

void Forum::print_taxinom(){
	dentro = new Dentro(*thread[0]);
	for(unsigned int i = 1; i < threads; i++)
	{
		Dentro dentro(*thread[i]);
		this->dentro->enhance(dentro);
	}
	this->dentro->print();
	delete dentro;
}

//destruct

Forum::~Forum()
{
	#if (OBJECT_FORUM_MESSAGES)
		cout << "To Forum me titlo: " << this->titlos << " tha diegrafei." << endl;
	#endif
		for(unsigned int i =0; i < threads; i++)
			delete thread[i];
		delete[] thread;
}