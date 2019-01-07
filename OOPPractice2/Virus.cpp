#include "Virus.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

Virus::Virus()
{
}

Virus::Virus(const Virus * virus)
{
}

void Virus::LoadADNInformation()
{
	string line;
	ifstream myfile("adn.bin");
	if (myfile.is_open())
	{
		this->mDNA = new char[100];
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

char * Virus::getDNA()
{
	return this->mDNA;
}

void Virus::setDNA(char * dna)
{
	this->mDNA = dna;
}

Virus::~Virus()
{
}
