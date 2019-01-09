#include "Virus.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
using namespace std;

Virus::Virus()
{
	this->mDNA = new char[50];
}

Virus::Virus(const Virus & virus)
{
	this->mDNA = new char[50];
	strcpy_s(this->mDNA, 50, virus.mDNA);
	this->mResistance = virus.mResistance;
}

void Virus::LoadADNInformation()
{
	string line;
	ifstream myfile("adn.bin");
	if (myfile.is_open())
	{
		myfile >> this->mDNA;
	}
	myfile.close();
}

int& Virus::ReduceResistance(int medicine_resistance)
{
	
	this->mResistance -= medicine_resistance;
	return this->mResistance;
}

int Virus::getResistance()
{
	return mResistance;
}

void Virus::setResistance(int resistance)
{
	mResistance = resistance;
}

Virus::~Virus()
{
	delete this->mDNA;
}
