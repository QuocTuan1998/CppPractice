#include <iostream>
#include <vector>
#include "Virus.h"
#include "FluVirus.h"
#include "DengueVirus.h"
#include "Patient.h"
#include <iostream>
#include <time.h>
#include <vld.h>
using namespace std;

void main()
{
	srand(NULL);

	Patient *pat = new Patient();

	//cout << "patient resistance : " << pat->getResistance() << endl;
	char choice;

	while (pat->getState() == 1)
	{
		cout << "Take Medicine (0 = NO, 1 = YES) : ";
		cin >> choice;
		if (choice == '1')
		{
			int min = 1;
			int max = 10;
			int medicine = rand() % ((max - min) + 1) + min;
			pat->TakeMedicine(medicine);
			int listSize = pat->getListSize();
			if (listSize == 0) // leak here
			{
				cout << "patient alive, all virus are clear." << endl;
				break;
			}
			
		}
		else  {
			pat->TakeMedicine(0);
		}
	}

	if (pat->getState() == 0)
	{
		cout << "patient die" << endl;
	}

	pat->DoDie();
	delete pat;
	system("pause");

}