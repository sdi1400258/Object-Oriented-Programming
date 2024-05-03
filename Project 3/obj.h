#ifndef OBJ_H
#define OBJ_H


class obj
{
	public:
		obj();
		virtual ~obj();
		obj(obj&);
		inline int getid()
		{
			return id;
		}
		inline void setid(int newid)
		{
			id = newid;
		}
		inline virtual bool identical(obj &a)
		{
			return ((this == &a) ? 1 : 0);
		}
		virtual bool equal(obj &a) = 0;
		virtual obj *clone() = 0;
		virtual str *tostr() = 0;
	private:
		int id;
};


class str : public obj
{
	public:
		str();
		str(char *);
		str(str  &);
		virtual ~str();
		obj *clone();
		bool equal(obj &);
		str *tostr();
		inline int length()
		{
			return letters;
		}
		inline char *get()
		{
			return word;
		}
		void clear();
		void concat(char *);
		void concat(str &);
		void print();
		void print2();
		char at(int);
		void updateat(char, int);
	private:
		char *word;
		int letters;
};


char *tostr(unsigned int);
void encryptclonethenprint(obj&);



#endif