#include <iostream>
#include <cstring>

#include "str.h"

using namespace std;


obj *str::clone()
{
	str*b = new str(*this);
	return b;

}

bool str::equal(obj &a)
{
	str *b = ((str *)&a);

	if(this->length() != b->length())
	{
		return 0;
	}
	char *temp1 = get(), *temp2 = b->get();
	int templength = this->length();

	for(int i = 0; i < templength; i++)
	{
		if(temp1[i] != temp2[i])
		{
			return 0;
		}
	}

	return 1;

}

str::str()
{
	cout << "Mia sumvoloseira dimiourgithike." << endl;
	word = NULL;
	letters = 0;

}

str::str(char *original)
{
	cout << "Mia sumvoloseira dimiourgithike." << endl;
	letters = 0;
	for(int i = 0; '\0' != original[i]; i++)
	{
		letters++;

	}
	word = new char[letters + 1];
	memcpy(word, original, letters + 1);

}

str::str(str &original)
{
	cout << "Mia sumvoloseira dimiourgithike." << endl;
	char *temp = original.get();
	letters = original.length();
	word = new char[letters + 1];
	memcpy(word, temp, letters +1);

}

str::~str()
{
	cout << "Mia sumvoloseira diagrafike." << endl;
	if(NULL !=word)
	{
		delete word;

	}

}

void str::clear()
{
	delete word;
	word = NULL;
	letters = 0;

}

void str::concat(char *extension)
{
	char *temp = word;
	int length = 0;
	for(int i=0; '\0' != extension[i]; i++)
	{
		length++;
	}
	word = new char[letters + length +1];
	memcpy(word, temp, length);
	memcpy(word + letters, extension, length +1);
	delete temp;
	letters += length;

}

void str::concat(str &extension)
{
	char *temp = word, *temp2 = extension.get();
	if(NULL == temp2)
	{
		return;
	}
	int length = extension.length();
	word = new char[letters + length +1];
	memcpy(word, temp, letters);
	memcpy(word + letters, temp2, length +1);
	delete temp;
	letters += length;

}

void str::print()
{
	if(NULL == word)
	{
		cout << "NULL" << endl;
		return;
	}

	cout << word << endl;

}

void str::print2()
{
	if(NULL == word)
	{
		cout << "NULL";
		return;
	}
	cout  << word;

}

char str::at(int position)
{
	if(0 > position || letters <= position)
	{
		return '\0';
	}
	return word[position];

}

void str::updateat(char character, int position)
{
	if(0 > position || letters <= position)
	{
		return;
	}

	word[position] = character;

}


str *str::tostr()
{
	str *result = new str("word: ");
	result->concat(*this);
	result->concat(", letters: ");
	char *temp = tostr(letters);
	result->concat(temp);
	delete temp;
	return result;


}

