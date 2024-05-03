#include <iostream>
#include <ctime>
#include <cstdlib>

#include "random.h"

using namespace std;

void inline Random::swap_(int& random1, int& random2)
{
	int r = random1;
	random1 = random2;
	random2 = r;
}

void Random::reset()
{
	int x = (max - min + 1);
	for(int i = 0; i < x; i++)
	{
		*values[i] = min + i;
	}
}

Random::Random(const unsigned int min, const unsigned int max) : min(min), max(max)
{
	if(max > min)
	{
		index = max - min + 1;
		values = new int*[index];
		for(int i = 0; i < index; i++)
		{
			values[i] = new int(min + i);
		}
		#if(OBJECT_RANDOM_MESSAGES)
		{
			cout << "Kataskeui enos tuxaiou antikeimenou me min timi: " << min << " kai max timi: " << max << endl;
		}
		#endif
	}
	else
	{
		cout << "Error" << endl;
		cin.get();
		exit(1);
	}

}


void Random::print() const
{
	int x = (max - min + 1);
	for(int i = 0; i < x; i++)
	{
		cout << "Times[" << i << "] = " << *values[i] << endl;
	}

}

const int Random::get()
{
	int x, arithmos = -1;
	if(index > 0)
	{
		x = rand() % index;
		arithmos = *values[x];
		swap_(*values[x], *values[--index]);
	}
	else
	{
		cout << "Error" << endl;
		cin.get();
		reset();
	}
	return arithmos;
}

Random::~Random()
{
	#if(OBJECT_RANDOM_MESSAGES)
	{
		cout << "Tuxaio antikeimeno diagrafike" << endl;
	}
	#endif
	int x = (max - min +1);
	for(int i =0; i < x; i++)
	{
		delete values[i];
	}
	delete[] values;
}
