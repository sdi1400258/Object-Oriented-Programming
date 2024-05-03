#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;


#include "obj.h"
#include "planecomponents.h"
#include "plane.h"
#include "str.h"
#include "employee.h"


int main()
{
	srand(time(NULL));

	cout << time(NULL) << endl;

	securityemployee s;
	obj &y = s;

	encryptclonethenprint(y);

	plane x;
	securityemployee se;
	employeemaintance em;
	cleaningemployee ce;

	x.process(&se);
	x.process(&em);
	x.process(&ce);

	x.readycheck();
	encryptclonethenprint(y);
	return 0;
	
}