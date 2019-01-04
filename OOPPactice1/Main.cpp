#include <iostream>
#include "MyPoint.h"

using namespace std;

void main()
{
	MyPoint point1;
	point1.setX(16);
	point1.setY(25);
	MyPoint point2 = new MyPoint();
	point2.setX(4);
	point2.setY(9);

	cout << "distance between point1 and point 2 : " << point1.Distance(point2) << endl;

	point1.Display();
	cout << endl;
	system("pause");
}