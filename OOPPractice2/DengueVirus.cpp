#include <iostream>
#include "DengueVirus.h"
#include <vector>
#include <cstdlib>
#include <time.h>

using namespace std;

DengueVirus::DengueVirus()
{
	Virus::LoadADNInformation();
}

DengueVirus::DengueVirus(const DengueVirus * den)
{
	*this = *den;
}

char DengueVirus::getProtein()
{
	return *this->mProtein;
}

void DengueVirus::setProtein(char *protein)
{
	this->mProtein = protein;
}

void DengueVirus::DoBorn()
{
	this->InitResistance();
}

vector<Virus*> DengueVirus::DoClone()
{
	vector<Virus*> vDen;
	Virus* den = new DengueVirus(this);		// same as flu virus
	Virus* den1 = new DengueVirus(this);
	vDen.push_back(den);
	vDen.push_back(den1);
	return vDen;
}

void DengueVirus::DoDie()
{
	delete this->mProtein;
	delete this->getDNA();
}

void DengueVirus::InitResistance()
{
	int n = rand() % ((3 - 1) + 1) + 1; // random kind of virus

	switch (n)
	{
	case 1:		//NS3
	{
		char pr[] = { 'N', 'S', '3', '\0' };
		char * p = pr;
		this->setProtein(p);
		this->setResistance(rand() % ((10 - 1) + 1) + 1);
		cout << this->mProtein << endl;
		break;
	}
	case 2:		//NS5
	{
		char pr[] = { 'N', 'S', '5', '\0' };
		char * p = pr;
		this->setProtein(p);
		this->setResistance(rand() % ((20 - 11) + 1) + 11);
		cout << this->mProtein << endl;
		break;
	}
		
	default:	// E
	{
		char pr[] = { 'E' , '\0'};
		char * p = pr;
		this->setProtein(p);
		this->setResistance(rand() % ((30 - 21) + 1) + 21);
		cout << this->mProtein << endl;
		break;
	}
	}
}

DengueVirus::~DengueVirus()
{
}
