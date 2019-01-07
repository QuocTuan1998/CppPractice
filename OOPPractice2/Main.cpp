#include <iostream>
#include <vector>
#include "Virus.h"
#include "FluVirus.h"
#include "DengueVirus.h"
#include "Patient.h"
#include <iostream>
#include <time.h>

using namespace std;

void main()
{
	srand(NULL);

	Patient pat;
	cout << "patient resistance : " << pat.getResistance() << endl;
	char choice;

	while (pat.getState() == 1)
	{
		cout << "Take Medicine (0 = NO, 1 = YES) : ";
		cin >> choice;
		if (choice == '1')
		{
			int min = 1;
			int max = 10;
			int medicine = rand() % ((max - min) + 1) + min;

			pat.TakeMedicine(medicine);

			if (pat.getListVirus().size() == 0)
			{
				cout << "patient alive, all virus are clear." << endl;
				break;
			}
		}
	}

	if (pat.getState() == 0)
	{
		cout << "patient die" << endl;
	}
	system("pause");

}