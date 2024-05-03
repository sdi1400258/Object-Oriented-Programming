#include "employee.h"

using namespace std;

employee::employee() : name("random upallilos No")
{
	static int x = 1;
	char *temp = tostr(x++);
	name.concat(temp);
	delete temp;
	cout << "Enas ipallilos dimiourgithike." << endl;

}

employee::employee(employee& a) : obj(a), name(*(a.getname())) 
{
	cout << "Enas ipallilos dimiourgithike." << endl;

}

employee::~employee()
{
	cout << "Enas ipallilos diagrafike." << endl;

}

bool employee::equal(obj &a)
{
	if(this->getid() == a.getid())
	{
		return 1;

	}
	return getname()->equal((str &)a);

}

str *employee::tostr()
{
	str *result = new str("id: ");
	char *temp = tostr(getid());
	str *temp2;
	result->concat(temp);
	delete temp;
	result->concat(", name: ");
	temp2 = name.tostr();
	result->concat(*temp2);
	delete temp2;
	return result;

}

securityemployee::securityemployee()
{
	cout << "Enas ergazomenos asfaleias dimiourgithike." << endl;

}

securityemployee::securityemployee(securityemployee& a) : employee(a)
{
	cout << "Enas ergazomenos asfaleias dimiourgithike. " << endl;

}

securityemployee::~securityemployee()
{
	cout << "Enas ergazomenos asfaleias diagrafike." << endl;

}

obj *securityemployee::clone()
{
	securityemployee *a = new securityemployee(*this);
	return a;

}

void securityemployee::workon(plane* p)
{
	for(int i = 0; i < p->getnoofpassengercompartments(); i++)
	{
		(p->getpassengercompartments())[i]->process(this);

	}
	p->getequipmentcompartment1()->process(this);
	p->getequipmentcompartment2()->process(this);
	p->getequipmentcompartment3()->process(this);
	p->getcargobay1()->process(this);
	report();

}

void securityemployee::workon(passengercompartment *p)
{
	cout << "O xoros epivatwn epexergazetai." << endl;
	if(NULL != p->getextraspace())
	{
		cout << "extra xoros: ";
		workon(p->getextraspace());
	}

}

void securityemployee::workon(equipmentcompartment *p)
{
	cout << "Xoros eksoplismou epexergazetai." << endl;

}

void securityemployee::workon(cargobay *p)
{
	cout << "O xoros emporevmatwn epexergazetai." << endl;

}

void securityemployee::report()
{
	getname()->print2();
	cout << " reports: ola okay." << endl;

}


employeemaintance::employeemaintance()
{
	cout << "Enas ergazomenos sintiris dimiourgithike." << endl;

}

employeemaintance::employeemaintance(employeemaintance& a) : employee(a)
{
	cout << "Enas ergazomenos sintiris dimiourgithike." << endl;

}

employeemaintance::~employeemaintance()
{
	cout << "ergazomenos sintiris diagrafike." << endl;

}

obj *employeemaintance::clone()
{
	employeemaintance *a = new employeemaintance(*this);
	return a;

}

void employeemaintance::workon(passengercompartment *p)
{

}

void employeemaintance::workon(plane* p)
{
	for(int i = 0; i < p->getnoofpassengercompartments(); i++)
	{
		(p->getpassengercompartments())[i]->process(this);

	}
	p->getequipmentcompartment1()->process(this);
	p->getequipmentcompartment2()->process(this);
	p->getequipmentcompartment3()->process(this);
	p->getcargobay1()->process(this);
	report();

}

void employeemaintance::workon(equipmentcompartment *p)
{
	cout << "Xoros eksoplismou epexergazetai." << endl;

}

void employeemaintance::workon(cargobay *p)
{
	cout << "Xoros emporevmatwn epexergazetai." << endl << "extraspace" ;
	workon(p->getextraspace());

}

void employeemaintance::report()
{
	getname()->print2();
	cout << " reports: Ola okay." << endl;

}


cleaningemployee::cleaningemployee()
{
	cout << "Enas ergazomenos kathariotitas dimiourgithike." << endl;

}

cleaningemployee::cleaningemployee(cleaningemployee& a) : employee(a)
{
	cout << "Enas ergazomenos kathariotitas dimiourgithike." << endl;

}

cleaningemployee::~cleaningemployee()
{
	cout <<" Enas ergazomenos kathariotitas diagrafike." << endl;

}


obj *cleaningemployee::clone()
{
	cleaningemployee *a = new cleaningemployee(*this);
	return a;

}

void cleaningemployee::workon(plane* p)
{
	for(int i = 0; i < p->getnoofpassengercompartments(); i++)
	{
		(p->getpassengercompartments())[i]->process(this);

	}
	p->getequipmentcompartment1()->process(this);
	p->getequipmentcompartment2()->process(this);
	p->getequipmentcompartment3()->process(this);
	p->getcargobay1()->process(this);
	report();

}

void cleaningemployee::workon(passengercompartment *p)
{
	cout << "O xoros epivatwn epexergazetai." << endl;
	if(NULL != p->getextraspace())
	{
		cout << "extraspace: ";
		workon(p->getextraspace());

	}

}

void cleaningemployee::workon(equipmentcompartment *p)
{

}

void cleaningemployee::workon(cargobay *p)
{
	cout << "O xoros emporevmatwn epexergazetai." << endl;

}

void cleaningemployee::report()
{
	getname()->print2();
	cout << "reports: Ola okay." << endl;
	
}