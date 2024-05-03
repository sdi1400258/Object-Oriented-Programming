#include <iostream>

#include "planecomponents.h"

using namespace std;



planecomponent::planecomponent() : desc("Exartima Aeroplanou No")
{
	static unsigned int x = 1;
	desc.concat(tostr(x++))
	cout << "Ena Exartima Aeroplanou Dimiourgithike." << endl;

}

planecomponent::planecomponent(planecomponent& a) : obj(a), desc(*a.getdesc()) 
{
	cout << " Ena Exartima Aeroplanou Dimiourgithike." << endl;

}

planecomponent::~planecomponent()
{
	cout << " Ena Exartima Aeroplanou diagrafike." << endl;

}




passengercompartment::passengercompartment(int j) : extraspace(NULL)
{
	cout << " O thalamos twn epivatwn dimiourgithike." << endl;
	getdesc()->concat(" - Thalamos Epivatwn");
	if(0 != j)
	{
		extraspace = new passengercompartment(0);
	
	}

}

passengercompartment::passengercompartment() : extraspace(NULL)
{
	cout << "O thalamos twn epivatwn dimiourgithike." << endl;
	getdesc()->concat(" - Thalamos Epivatwn");
	if(0 == rand()%2)
	{
		extraspace = new passengercompartment(0);
	}

}

passengercompartment::passengercompartment(passengercompartment& a) : planecomponent(a)
{
	if(NULL == a.getextraspace())
	{
		extraspace = NULL;
	}
	else
	{
		extraspace = new passengercompartment(*(a.getextraspace()));
	}
	cout << "O thalamos twn epivatwn dimiourgithike." << endl;

}

passengercompartment::~passengercompartment()
{
	cout << "o thalamos epivatwn diagrafike." << endl;

}

void passengercompartment::readycheck()
{
	getdesc()->print2();
	cout << ": O thalamos twn epivatwn einai etoimos." << endl;
	if(NULL != extraspace)
	{
		cout << "extraspace: ";
		extraspace->readycheck();
	}
}

void passengercompartment::process(employee *e)
{
	e->workon(this);
}

bool passengercompartment::equal(obj &a)
{
	passengercompartment *b = ((passengercompartment *) &a);

	if(0 == getdesc()->equal(*(b->getdesc())))
	{
		return 0;
	}
	if(NULL == getextraspace())
	{
		if(NULL != b->getextraspace())
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	if(NULL == b->getextraspace())
	{
		if(NULL != getextraspace())
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	obj &c = *(b->getextraspace());
	if(0 == getextraspace()->equal(c))
	{
		return 0;
	}
	else
	{
		return 1;
	}

}

obj *passengercompartment::clone()
{
	passengercompartment *a = new passengercompartment(*this);
	return a;
}

str *passengercompartment::tostr()
{
	str *result = new str("ID: ");
	char *temp = tostr(getid());
	str *temp2;
	result->concat(temp);
	delete temp;
	result->concat(", desc: ");
	temp2 = getdesc()->tostr();
	result->concat(*temp2);
	delete temp2;
	result->concat(", extraspace: ");
	if(NULL != extraspace)
	{
		temp2 = extraspace->tostr();
		result->concat(*temp2);
		delete temp2;
	}
	else
	{
		result->concat("empty");
	}
	return result;

}



privatecompartment::privatecompartment()
{
	cout << "O xoros periosmenis prosvasis dimiourgithike." << endl;

}

privatecompartment::privatecompartment(privatecompartment& a) : planecomponent(a)
{
	cout << "O xoros periosmenis prosvasis dimiourgithike." << endl;

}

privatecompartment::~privatecompartment()
{
	cout << " O xoros periosmenis prosvasis diagrafike." << endl;

}

obj *privatecompartment::clone()
{


}


equipmentcompartment::equipmentcompartment()
{
	cout << " O xoros eksoplismou dimiourgithike." << endl;
	getdesc()->concat(" - Xoros periosmenis prosvasis - Xoros eksoplismou");

}

equipmentcompartment::equipmentcompartment(equipmentcompartment& a) : privatecompartment(a)
{
	cout << "O xoros eksoplismou dimiourgithike." << endl;

}

equipmentcompartment::~equipmentcompartment()
{
	cout << " O xoros eksoplismou diagrafike." << endl;

}

bool equipmentcompartment::equal(obj &a)
{
	passengercompartment *b = ((passengercompartment *) &a);
	return getdesc()->equal(*(b->getdesc()));

}

void equipmentcompartment::readycheck()
{
	getdesc()->print2();
	cout << ": O xoros eksoplismou einai etoimos." << endl;

}

void equipmentcompartment::process(employee *e)
{
	e->workon(this);

}

obj *equipmentcompartment::clone()
{
	equipmentcompartment *a = new equipmentcompartment(*this);
	return a;

}

str *equipmentcompartment::tostr()
{
	str *result = new str("id: ");
	char *temp = tostr(getid());
	str *temp2;
	result->concat(temp);
	delete temp;
	result->concat(", desc: ");
	temp2 = getdesc()->tostr();
	result->concat(*temp2);
	delete temp2;
	return result;

}

cargobay::cargobay()
{
	cout << "O xoros emporevmatwn dimiourgithike." << endl;
	getdesc()->concat(" - Xoros periosmenis prosvasis - Xoros emporevmatwn");

}

cargobay::cargobay(cargobay& a) : privatecompartment(a), extraspace(*(a.getextraspace()))
{
	cout << "o xoros emporevmatwn dimiourgithike." << endl;

}

cargobay::~cargobay()
{
	cout << "O xoros emporevmatwn diagrafike." << endl;

}

bool cargobay::equal(obj &a)
{
	cargobay *b = ((cargobay *) &a);
	if(0 == getdesc()->equal(*(b->getdesc())))
	{
		return 0;
	}
	else if(0 == getextraspace()->equal(*(b->getextraspace())))
	{
		return 0;
	}
	else
	{
		return 1;
	}

}

void cargobay::readycheck()
{
	getdesc()->print2();
	cout << ": xoros emporevmatwn einai etoimos." << endl;
	cout << "extra xoros : ";
	extraspace.readycheck();

}

void cargobay::process(employee *e)
{
	e->workon(this);

}

obj *cargobay::clone()
{
	cargobay *a = new cargobay(*this);
	return a;

}

str *cargobay::tostr()
{
	str *result = new str("id: ");
	char *temp = tostr(getid());
	str *temp2;
	result->concat(temp);
	delete temp;
	result->concat(", desc: ");
	temp2 = getdesc()->tostr();
	result->concat(*temp2);
	delete temp2;
	result->concat(", extraspace: ");
	temp2 = extraspace.tostr();
	result->concat(*temp2);
	delete temp2;


	return result;
	
}