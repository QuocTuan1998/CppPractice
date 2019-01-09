#ifndef VIRUS_H
#define VIRUS_H
#include <vector>
using namespace std;

class Virus
{
private:
	char* mDNA;
	int mResistance;
public:
	Virus();
	// copy constructor
	Virus(const Virus& virus);
	// load adn from file
	void LoadADNInformation();
	//  calculate resistance
	int& ReduceResistance(int medicien_resistance);
	// getter and setter
	int getResistance();
	void setResistance(int resistance);
	void setDNA(char* dna);
	// pure virtual
	virtual void DoBorn() = 0;
	virtual vector<Virus*> DoClone() = 0;
	virtual void DoDie() = 0;
	virtual void InitResistance() = 0;
	virtual ~Virus();
};
#endif // !VIRUS_H
