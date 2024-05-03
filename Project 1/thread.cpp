#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

#include "thread.h"

using namespace std;

//Const

Thread::Thread(const Data& data, const string thema, const string dimiourgos, const unsigned int posts) : thema(thema), dimiourgos(dimiourgos), posts(posts)
{
	date = new Date(rand() % day_secs);
	post = new Post*[posts];
	for (unsigned int i = 0; i < posts; i++)
	{
		post[i] = new Post(data.titlos(), (i == 0) ? dimiourgos : data.dimiourgos(), data.keimeno());
	}
	#if(OBJECT_THREAD_MESSAGES)
	{
		cout << "Nima me thema : " << thema << " dimiourgithike " << endl;
	}
	#endif

}

//copy const

Thread::Thread(const Thread& thread) : thema(thread.thema), dimiourgos(thread.dimiourgos), posts(thread.posts)
{
	date = new Date(*thread.date);
	post = new Post*[posts];
	for(unsigned int i = 0; i < thread.posts; i++)
	{
		this->post[i] = new Post(*thread.post[i]);
	}
	#if(OBJECT_THREAD_MESSAGES)
	{
		cout << "Nima me thema " << thread.thema << " Antigrafike me epitixia" << endl;
	}
	#endif
}

const string& Thread::get_thema() const
{
	return this->thema;
}

unsigned int Thread::get_posts() const
{
	return this->posts;
}

Post& Thread::get_post(unsigned int i) const
{
	if(i < 0 || i > posts)
	{
		cout << "Akiro post id : " << i << endl;
		cin.get();
		exit(1);
	}
	else
		return *post[i];
}

// Emfanisi gia ola ta kommatia tou nimatos

void Thread::print() const
{
	cout << "\n Nima me thema " << this->thema << " dimiourgithike apo " << this->dimiourgos << " stis " << date->get_str() << endl;
	print(T_POSTS);
}

//ektipwsi gia kathe kommati ksexwrista

void Thread::print(const int kommati = 0) const
{
	if(kommati == T_THEMA)
	{
		cout << "\n'" << thema << "'" << endl;
		
	}
	else if(kommati == T_DIMIOURGOS)
	{
		cout << "\n'" << dimiourgos << "'" << endl;
		
	}
	else if(kommati == T_DATE)
	{
		cout << endl;
		date->print();
		
	}
	else if(kommati == T_POSTS)
	{
		for(unsigned int i =0; i < posts; i++)
		{
			post[i]->print();
		}
		
	}
	else
	{
		cout << "Auto to kommati den uparxei " << endl;
		cin.get();
		exit(1);
		
	}
}

void Thread::print(const unsigned int selid) const
{
	for(unsigned int i = 0; i < this->posts; i++)
	{
		if(post[i]->getid() == selid)
		{
			post[i]->print();
		}
	}

}


//Destruct

Thread::~Thread()
{
	#if(OBJECT_THREAD_MESSAGES)
	{
		cout << "Nima me thema " << this->thema << " diagrafike" << endl;

	}
	#endif
	delete date;
	for(unsigned int i =0; i < posts; i++)
	{
		delete post[i];
	}
	delete[] post;
}

