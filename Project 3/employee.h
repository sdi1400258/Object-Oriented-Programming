#ifndef EMPLOYEE_H
#define EMPLOYEE_H


#include "obj.h"
#include "planecomponents.h"
#include "plane.h"
#include "str.h"

class employee : public obj 
{
		public:
			employee();
			employee(employee&);
			~employee();
			virtual void workon(plane *) = 0;
			virtual void workon(passengercompartment *) = 0;
			virtual void workon(equipmentcompartment *) = 0;
			virtual void workon(cargobay *) = 0;
			virtual void report() = 0;
			inline str *getname() 
			{
				return &name;
			}
			bool equal(obj &);
			str *tostr();
		private:
			str name;
};

class securityemployee : public employee
{
		public:
			securityemployee();
			securityemployee(securityemployee &);
			~securityemployee();
			obj *clone();
			void workon(plane *);
			void workon(passengercompartment *);
			void workon(equipmentcompartment *);
			void workon(cargobay *);
			void report();
		private:
			
};

class employeemaintance : public employee
{
		public:
			employeemaintance();
			employeemaintance(employeemaintance &);
			~employeemaintance();
			obj *clone();
			void workon(plane *);
			void workon(passengercompartment *);
			void workon(equipmentcompartment *);
			void workon(cargobay *);
			void report();
		private:


};

class cleaningemployee : public employee
{
		public:
			cleaningemployee();
			cleaningemployee(cleaningemployee &);
			~cleaningemployee();
			obj *clone();
			void workon(plane *);
			void workon(passengercompartment *);
			void workon(equipmentcompartment *);
			void workon(cargobay *);
			void report();
		private:

};


#endif