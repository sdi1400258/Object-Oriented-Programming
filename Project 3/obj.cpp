#include <iostream>

#include "obj.h"

using namespace std;


obj::obj()
{
	static int newid = 0;
	id = newid;
	cout << "Ena antikeimeno dimiourgithike." << endl;
	newid++;

}

obj::obj(obj& a) : id(a.getid())
{
	cout << " Ena antikeimeno dimiourgithike. " << endl;

}

obj::~obj()
{
	cout << "Ena antikeimeno diagrafike." << endl;

}

char *tostr(unsigned int number)
{
	unsigned int digits = 0, temp = number;
	char *result = NULL;
	if (0 == number)
	{
		result = new char[2];
		result[0] = '0';
		result[1] = 0;
		return result;

	}

	while(0 != temp)
	{
		digits++;
		temp /= 10;

	}
	result = new char[digits +1];
	result[digits--] = 0;
	while(0 != number)
	{
		result[digits--] = number%10 + '0';
		number /=10;

	}

	return result;

}

void encryptclonethenprint(obj &a)
{
	obj *b = a.clone();

	if(0 == a.equal(a))
	{
		cout << "not equal" << endl;

	}
	else
	{
		cout << " equal" << endl;
	}

	if(0 == a.identical(*b))
	{
		cout << "not identical " << endl;

	}
	else
	{
		cout << "identical " << endl;
	}
	str *str1 = a.tostr(), *str2 = b->tostr();

	int length = str1->length();
	int end = rand() & length + 1;
	for(int i = 0; i < end; i++)
	{
		str2->updateat(rand()% 26 + 'a', rand()%length);

	}

	str1->print();
	str2->print();



	str *str3 = new str(*str1);
	str3->concat(*str2);
	cout << "length: " << str3->length() << endl;
	cout << "meseoi xaraktires: " << str3->at(str3->length()/2);
	if(0 == str3->length()%2)
	{
		cout << str3->at(str3->length()/2 +1) << endl;
	}
	else
	{
		cout << endl;
	}

	str3->clear();
	cout << "length: " << str3->length() << endl;
	delete str1;
	delete str2;
	delete str3;
	
}