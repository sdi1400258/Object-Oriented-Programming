#ifndef RANDOM_H
#define RANDOM_H

#define OBJECT_RANDOM_MESSAGES 1

class Random{
		unsigned int min;
		unsigned int max;
		int ** values;
		int index;
		void inline swap_(int&, int&);
		void reset();
	public:
		Random(const unsigned int, const unsigned int);
		void print() const;
		const int get();
		~Random();
};

#endif