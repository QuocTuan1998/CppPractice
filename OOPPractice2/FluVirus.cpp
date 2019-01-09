#include <iostream>
#include "FluVirus.h"
#include <stdlib.h>
#include <time.h>
using namespace std;

FluVirus::FluVirus()
{
	Virus::LoadADNInformation();
}

FluVirus::FluVirus(const FluVirus &fluVirus) : Virus(fluVirus)
{
	this->mColor = fluVirus.mColor;
}

int FluVirus::getColor()
{
	return this->mColor;
}

void FluVirus::DoBorn()
{
	// random red or blue color 1 : red, 2: blue
	int ran = rand();
	if (ran % 2 == 0)
	{
		this->mColor = 255;
	}
	else
	{
		this->mColor = 0;
	}
	
	InitResistance();	
}

vector<Virus*> FluVirus::DoClone()
{
	vector<Virus*> vFlu;
	Virus* flu = new FluVirus(*this); // create new virus like current virus
	vFlu.push_back(flu);
	return vFlu;
}

void FluVirus::DoDie()
{
} 

void FluVirus::InitResistance()
{
	if (this->mColor == 255) // Red (20 - 10)
	{
		FluVirus::setResistance(rand() % ((30 - 10) + 1) + 10);
	}
	else if (this->mColor == 0) // blue (15 - 10)
	{
		FluVirus::setResistance(rand() % ((20 - 10) + 1) + 10);
	}
}

FluVirus::~FluVirus()
{

}

