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
	int patientResistance = rand() % ((500 - 1) + 1) + 1; // random resistance
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
	for (int i = 0; i < st.numOfVirus; i++)
	{
		this->mListVirus[i]->ReduceResistance(medicine); // call virus reduce
		st.sumOfResistanceVirus += this->mListVirus[i]->getResistance();
		if (this->mListVirus[i]->getResistance() > 0) // not die 
		{
			vector<Virus*> tmpVec = this->mListVirus[i]->DoClone(); 
			int m = tmpVec.size();
			for (int j = 0; j < m; j++)  // push clone virus into listvirus
			{
				this->mListVirus.push_back(tmpVec[j]);
			}
			
			for (auto it : tmpVec)
			{
				delete it;
			}
		}
		else
		{
			this->mListVirus[i]->DoDie();
		}
	}

	// remove virus if resistance <= 0
	for (int i = 0; i < this->mListVirus.size();i++)
	{
		if (this->mListVirus[i]->getResistance() <= 0)
		{		
			this->mListVirus.erase(this->mListVirus.begin() + i);
			i--;
		}
	}

	if (st.sumOfResistanceVirus >= st.patientResistance)
	{
		this->mState = 0;
		DoDie();
	}

	st.numOfVirus = getListSize();
}

int Patient::getListSize()
{
	return this->mListVirus.size();
}

void Patient::DoDie()
{
	 ///clear list
	for (auto it : this->mListVirus)
	{
		delete it;
	}

}

Patient::~Patient()
{
	
}
