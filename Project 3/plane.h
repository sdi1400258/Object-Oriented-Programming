#ifndef PLANE_H
#define PLANE_H


#include "obj.h"
#include "planecomponents.h"
#include "employee.h"
#include "str.h"

class plane : public obj
{
		public:
			plane();
			plane(plane &);
			~plane();
			bool equal(obj &);
			void readycheck();
			void process(employee *);
			obj *clone();
			str *tostr();
			inline str *getdesc()
			{
				return &desc;
			}
			inline str *gettitle()
			{
				return &title;
			}
			inline unsigned int getcapacity()
			{
				return capacity;
			}
			inline unsigned int getnoofpassengercompartments()
			{
				return noofpassengercompartments;
			}
			inline passengercompartment **getpassengercompartments()
			{
				return passengercompartments;
			}
			inline equipmentcompartment *getequipmentcompartment1()
			{
				return &equipmentcompartment1;
			}
			inline equipmentcompartment *getequipmentcompartment2()
			{
				return &equipmentcompartment2;
			}
			inline equipmentcompartment *getequipmentcompartment3()
			{
				return &equipmentcompartment3;
			}
			inline cargobay *getcargobay1()
			{
				return &cargobay1;
			}
			inline void settitle(str a)
			{
				title.clear();
				title.concat(a);
			}
			inline void setdesc(str a)
			{
				desc.clear();
				desc.concat(a);
			}
			inline void setpassengercompartments(passengercompartment **a)
			{
				passengercompartments = a;
			}
			inline void setcapacity(unsigned int a)
			{
				capacity = a;
			}
			inline void setnoofpassengercompartments(unsigned int a)
			{
				noofpassengercompartments = a;
			}
		private:
			passengercompartment **passengercompartments;
			cargobay cargobay1;
			equipmentcompartment equipmentcompartment1;
			equipmentcompartment equipmentcompartment2;
			equipmentcompartment equipmentcompartment3;
			str desc;
			str title;
			unsigned int capacity;
			unsigned int noofpassengercompartments;

};




#endif