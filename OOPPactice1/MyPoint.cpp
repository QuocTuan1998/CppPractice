#include <iostream>
#include "MyPoint.h"

using namespace std;

MyPoint::MyPoint() {
	mPosX = 0;
	mPosY = 0;
}

MyPoint::MyPoint(int x, int y) : mPosX(x), mPosY(y)
{
	cout << "constructor"<< endl;
}

void MyPoint::Display()
{
	cout << "position x = " << MyPoint::getX() << "\nposition y = " << MyPoint::getY();
}

double MyPoint::Distance(MyPoint p)
{
	return sqrt(pow(mPosX - p.mPosX, 2) + pow(mPosY - p.mPosY, 2));
}

void MyPoint::setX(int x)
{
	mPosX = x;
}

int MyPoint::getX()
{
	return mPosX;
}

void MyPoint::setY(int y)
{
	mPosY = y;
}

int MyPoint::getY()
{
	return mPosY;
}

MyPoint::~MyPoint()
{
	cout << "Destroy!" << endl;
}
