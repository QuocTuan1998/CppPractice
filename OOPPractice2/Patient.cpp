#include "Patient.h"
#include "Virus.h"
#include "DengueVirus.h"
#include "FluVirus.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <time.h>

using namespace std;

struct PatientStruct
{
	int numOfVirus = rand() % ((10 - 2) + 1) + 2; // random number of virus
	int patientResistance = rand() % ((9000 - 5000) + 1) + 5000; // random resistance
	int sumOfResistanceVirus = 0;
}st;

Patient::Patient()
{
	this->mState = 1; // alive 
	this->InitResistance();
	this->DoStart();
}

int Patient::getState()
{
	return this->mState;
}

vector<Virus*> Patient::getListVirus()
{
	return this->mListVirus;
}

void Patient::setResistance(int resistance)
{
	this->mResistance = resistance;
}

int Patient::getResistance()
{
	return this->mResistance;
}

void Patient::InitResistance()
{
	this->setResistance(st.patientResistance);					// set resistance
}

void Patient::DoStart()
{
	for (int i = 0; i < st.numOfVirus; i++)
	{
		// kind of virus
		int ran = rand() % 100;
		if (ran % 2 == 0) 
		{
			Virus * virus = new FluVirus();
			virus->DoBorn();
			this->mListVirus.push_back(virus);
		}
		else
		{
			Virus * virus = new DengueVirus();
			virus->DoBorn();
			this->mListVirus.push_back(virus);
			
		}
	}
}

void Patient::TakeMedicine(int medicine)
{
	cout << "num vr : " << st.numOfVirus << endl;

	for (int i = 0; i < st.numOfVirus; i++)
	{
		this->mListVirus[i]->ReduceResistance(medicine); // call virus reduce

		if (this->mListVirus[i]->getResistance() <= 0) // virus die
		{
			st.sumOfResistanceVirus += this->mListVirus[i]->getResistance();
			this->mListVirus[i]->setResistance(0);
		}
		else // not die
		{
			st.sumOfResistanceVirus += this->mListVirus[i]->getResistance();
			vector<Virus*> tmpVec = this->mListVirus[i]->DoClone();
			int m = tmpVec.size();
			for (int j = 0; j < m; j++)  // clone virus depend on what kind of virus
			{
				//this->mListVirus.insert(this->mListVirus.begin(), tmpVec[j]); // insert into list of virus
				this->mListVirus.push_back(tmpVec[j]);
			}
		}
	}
	
	if (st.sumOfResistanceVirus >= st.patientResistance)
	{
		this->mState = 0;
	}
	else if (st.sumOfResistanceVirus <= 0)
	{
		this->mListVirus.clear();
	}
	st.numOfVirus = this->mListVirus.size();
	cout << "num vr : " << st.numOfVirus << endl;
	cout << "sum of resistance virus : " << st.sumOfResistanceVirus << endl;
}

void Patient::DoDie()
{
	delete this;
}

Patient::~Patient()
{
}
