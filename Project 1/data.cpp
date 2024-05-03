#include <iostream>
#include <ctime>
#include <cstdlib>

#include "data.h"
#include "random.h"

const string Data::Themata[20]
{
	"Thema1", "Thema2", "Thema3", "Thema4", "Thema5", "Thema6", "Thema7", "Thema8", "Thema9", "Thema10", 
	"Thema11", "Thema12", "Thema13", "Thema14", "Thema15", "Thema16", "Thema17", "Thema18", "Thema19", "Thema20"
};

const string Data::Dimiourgoi[10]
{
	"Dimiourgos1", "Dimiourgos2", "Dimiourgos3", "Dimiourgos4", "Dimiourgos5", "Dimiourgos6", "Dimiourgos7", "Dimiourgos8", "Dimiourgos9", "Dimiourgos10"
};

const string Data::Titloi[10]
{
	"Titlos1", "Titlos2", "Titlos3", "Titlos4", "Titlos5", "Titlos6", "Titlos7", "Titlos8", "Titlos9", "Titlos10"
};

const string Data::Keimena[20]
{
	"keimeno1", "keimeno2", "keimeno3", "keimeno4", "keimeno5", "keimeno6", "keimeno7", "keimeno8", "keimeno9", "keimeno10", 
	"keimeno11", "keimeno12", "keimeno13", "keimeno14", "keimeno15", "keimeno16", "keimeno17", "keimeno18", "keimeno19", "keimeno20"
};


const string Data::thema(int index) const
{
	return this->Themata[(index == 0) ? 0 : rand() % 20];
}

const string Data::dimiourgos() const
{
	return this->Dimiourgoi[rand() % 10];
}

const string Data::titlos() const
{
	return this->Titloi[rand() % 10];
}

const string Data::keimeno() const
{
	return this->Keimena[rand() % 20];
}
