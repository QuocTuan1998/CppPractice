#include <iostream>
#include "DengueVirus.h"
#include <vector>
#include <cstring>
#include <cstdlib>

using namespace std;

DengueVirus::DengueVirus()
{
	this->mProtein = new char[4];
	Virus::LoadADNInformation();
}

DengueVirus::DengueVirus(const DengueVirus & den) : Virus(den)
{
	this->mProtein = new char[4];
	strcpy_s(this->mProtein, 4, den.mProtein);
}

void DengueVirus::DoBorn()
{
	this->InitResistance();
}

vector<Virus*> DengueVirus::DoClone()
{
	vector<Virus*> vDen;
	Virus* den = new DengueVirus(*this);
	Virus* den1 = new DengueVirus(*this);
	vDen.push_back(den);
	vDen.push_back(den1);
	return vDen;
}

void DengueVirus::DoDie()
{
	delete mProtein;
}

void DengueVirus::InitResistance()
{
	int n = rand() % ((3 - 1) + 1) + 1; // random kind of virus
	switch (n)
	{
	case 1:		//NS3
	{
		this->mProtein[0] = 'N';
		this->mProtein[1] = 'S';
		this->mProtein[2] = '3';
		this->mProtein[3] = '\0';
		this->setResistance(rand() % ((10 - 1) + 1) + 1);
		break;
	}
	case 2:		//NS5
	{
		this->mProtein[0] = 'N';
		this->mProtein[1] = 'S';
		this->mProtein[2] = '5';
		this->mProtein[3] = '\0';
		this->setResistance(rand() % ((20 - 11) + 1) + 11);
		break;
	}
		
	default:	// E
	{
		this->mProtein[0] = 'E';
		this->mProtein[1] = '\0';
		this->setResistance(rand() % ((30 - 21) + 1) + 21);
		break;
	}
	}
}

 DengueVirus::~DengueVirus()
{

}
