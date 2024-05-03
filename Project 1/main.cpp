#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>


#include "forum.h"
#include "random.h"

using namespace std;


int main()
{
	srand((unsigned int)time(NULL));
	{
		cout << "Askisi 1: " << endl;
		cout << "Erwtisi 1 " << endl;
		Forum forum1("Antikeimenostrafis programmatismos", rand() & threads + 1);
		cin.get();

		cout << "Erwtisi 2 " << endl;
		forum1.print(T_THEMA);
		cin.get();

		cout << "Erwtisi 3 " << endl;
		forum1.print(1);
		cin.get();

		cout << "Erwtisi 4 " << endl;
		unsigned int posts = forum1.get_posts();
		Random r_p(1, posts);
		unsigned int x = rand() & posts;
		cout << x << " apo " << posts << " posts exoun epilexthei tixaia" << endl;
		for(unsigned int i = 0; i < x; i++)
		{
			forum1.print((unsigned int)r_p.get());
		}
		cin.get();

	}
	cin.get();
	return 0;
	
}