#ifndef PATIENT_H
#define PAITENT_H
#include "Virus.h"
#include <vector>

using namespace std;

class Patient
{
private:
	int mResistance;
	vector<Virus*> mListVirus;
	int mState;
public:
	Patient();
	int getState();
	vector<Virus*> getListVirus();
	void setResistance(int resistance);
	int getResistance();
	void InitResistance();
	void DoStart();
	void TakeMedicine(int medicine);
	int getListSize();
	void DoDie();
	~Patient();
};

#endif // !PATIENT_H