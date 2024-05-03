#include <iostream>

#include "plane.h"

using namespace std;


plane::plane()
{
	cout << "Ena aeroplano dimiourgithike." << endl;
	static unsigned int x = 0;
	capacity = (rand()%10 + 1)*100;
	noofpassengercompartments = capacity/100;
	passengercompartments = new passengercompartment*[noofpassengercompartments];
	for(int i = 0; i < noofpassengercompartments; i++)
	{
		passengercompartments[i] = new passengercompartment;

	}
	char *temp = tostr(x++);
	desc.concat("Neo aeroplano No");
	desc.concat(temp);
	title.concat("Boeing ");
	title.concat(temp);
	delete temp;

}

plane::plane(plane& a) : obj(a), cargobay1(*a.getcargobay1()), equipmentcompartment1(*a.getequipmentcompartment1()),
						 equipmentcompartment2(*a.getequipmentcompartment2()),
						 equipmentcompartment3(*a.getequipmentcompartment3()),
						 title(*a.gettitle()), desc(*a.getdesc()), capacity(a.getcapacity()),
						 noofpassengercompartments(a.getnoofpassengercompartments())
{
	cout << "Ena aeroplano dimiourgithike. " << endl;
	passengercompartment = new passengercompartment*[noofpassengercompartments];
	for(int i = 0; i < noofpassengercompartments; i++)
	{
		passengercompartments[i] = new passengercompartment(*(a.getnoofpassengercompartments()[i]));

	}

}

plane::~plane()
{
	for(int i = 0; i < noofpassengercompartments; i++)
	{
		delete passengercompartments[i];
	}
	delete [] passengercompartments;
	cout << "Ena aeroplano diagrafike. " << endl;

}

bool plane::equal(obj& a)
{
	plane *b = ((plane*) &a);

	if(capacity != b->getcapacity())
	{
		return 0;
	}
	if(noofpassengercompartments != b->getnoofpassengercompartments())
	{
		return 0;
	}
	if(0 == title.equal(*(b->gettitle())))
	{
		return 0;
	}
	if(0 == desc.equal(*(b->getdesc())))
	{
		return 0;
	}
	if(0 == cargobay1.equal(*(b->getcargobay1())))
	{
		return 0;
	}
	if(0 == equipmentcompartment1.equal(*(b->getequipmentcompartment1())))
	{
		return 0;
	}
	if(0 == equipmentcompartment2.equal(*(b->getequipmentcompartment2())))
	{
		return 0;
	}
	if(0 == equipmentcompartment3.equal(*(b->getequipmentcompartment3())))
	{
		return 0;
	}

	for(int i = 0; i < noofpassengercompartments; i++)
	{
		if(0 == passengercompartments[i]->equal(*(b->getpassengercompartments()[i])))
		{
			return 0;
		}

	}

	return 1;
	
}

obj *plane::clone()
{
	plane *a = new plane(*this);
	return a;

}

str *plane::tostr()
{
	str *result = new str("id: ");
	char *temp = tostr(getid());
	result->concat(temp);
	delete temp;
	result->concat(", desc: ");
	result->concat(desc);
	result->concat(", title: ");
	result->concat(title);
	result->concat(", capacity: ");
	temp = tostr(capacity);
	result->concat(temp);
	delete temp;
	result->concat(", noofpassengercompartments: ");
	temp = tostr(noofpassengercompartments);
	result->concat(temp);
	delete temp;

	str *temp2;
	for(unsigned int i = 0; i < noofpassengercompartments; i++)
	{
		temp = tostr(i);
		result->concat(", passengercompartment");
		result->concat(temp);
		result->concat(": ");
		delete temp;
		temp2 = passengercompartments[i]->tostr();
		result->concat(*temp2);
		delete temp2;

	}

	result->concat(", equipmentcompartment1: ");
	temp2 = equipmentcompartment1.tostr();
	result->concat(*temp2);
	delete temp2;
	result->concat(", equipmentcompartment2: ");
	temp2 = equipmentcompartment2.tostr();
	result->concat(*temp2);
	delete temp2;
	result->concat(", equipmentcompartment3: ");
	temp2 = equipmentcompartment3.tostr();
	result->concat(*temp2);
	delete temp2;
	result->concat(", cargobay1: ");
	temp2 = cargobay1.tostr();
	result->concat(*temp2);
	delete temp2;

	return result;


}


void plane::process(employee* e)
{
	e->workon(this);

}

void plane::readycheck()
{
	for(int i = 0; i < noofpassengercompartments; i++)
	{
		passengercompartments[i]->readycheck();
	}
	equipmentcompartment1.readycheck();
	equipmentcompartment2.readycheck();
	equipmentcompartment3.readycheck();
	cargobay1.readycheck();

	cout << "To aeroplano einai etoimo gia apogiwsi." << endl;

	
}