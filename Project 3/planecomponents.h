#ifndef PLANECOMPONENTS_H
#define PLANECOMPONENTS_H


#include "obj.h"
#include "employee.h"
#include "plane.h"
#include "str.h"

class planecomponent : public obj
{
		public:
			planecomponent();
			planecomponent(planecomponent&);
			virtual ~planecomponent();
			virtual void readycheck() = 0;
			virtual void process(employee *) = 0;
			inline str *getdesc() 
			{
				return &desc;
			}
			inline void setdesc(str &newdesc)
			{
				desc.clear();
				desc.concat(newdesc);
			}
		private:
			str desc;
};

class passengercompartment : public planecomponent
{
		public:
			passengercompartment(int);
			passengercompartment();
			passengercompartment(passengercompartment&);
			virtual ~passengercompartment();
			obj *clone();
			bool equal(obj &);
			str *tostr();
			void readycheck();
			void process(employee *);
			inline passengercompartment *getextraspace()
			{
				return extraspace;
			}
			inline void setextraspace(passengercompartment *a)
			{
				extraspace = a;
			}
		private:
			passengercompartment *extraspace;
};

class privatecompartment : public planecomponent
{
		public:
			privatecompartment();
			privatecompartment(privatecompartment&);
			virtual ~privatecompartment();
			obj *clone();
};


class equipmentcompartment : public privatecompartment
{
		public:
			equipmentcompartment();
			equipmentcompartment(equipmentcompartment&);
			virtual ~equipmentcompartment();
			obj *clone();
			bool equal(obj &);
			str *tostr();
			void readycheck();
			void process(employee *);

};

class cargobay : public privatecompartment
{
		public:
			cargobay();
			cargobay(cargobay&);
			virtual ~cargobay();
			obj *clone();
			bool equal(obj &);
			str *tostr();
			void readycheck();
			void process(employee *);
			inline equipmentcompartment *getextraspace()
			{
				return &extraspace;
			}
		private:
			equipmentcompartment extraspace;
};


#endif