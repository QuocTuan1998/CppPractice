#ifndef DENGUEVIRUS_H
#define DENGUEVIRUS_H
#include <vector>
#include "Virus.h"

using namespace std;

class DengueVirus : public Virus
{
private:
	char* mProtein;

public:
	DengueVirus();
	DengueVirus(const DengueVirus * den);
	char getProtein();
	void setProtein(char *protein);
	void DoBorn() override;
	vector<Virus*> DoClone() override;
	void DoDie() override;
	void InitResistance() override;
	~DengueVirus();
};

#endif // !DENGUEVIRUS_H