#ifndef FLUVIRUS_H
#define FLUVIRUS_H
#include <vector>
#include "Virus.h"

using namespace std;

class FluVirus : public Virus
{
private:
	int mColor;
public:
	FluVirus();
	FluVirus(const FluVirus& fluVirus);
	int getColor();
	void DoBorn() override;
	vector<Virus*> DoClone() override;
	void DoDie() override;
	void InitResistance() override;
	 
	~FluVirus();
};

#endif // !FLUVIRUS_H
