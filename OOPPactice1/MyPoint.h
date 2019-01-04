#ifndef MYPOINT_H
#define MYPOINT_H


class MyPoint
{
private:
	int mPosX;
	int mPosY;

public:
	MyPoint();

	MyPoint(int x, int y);

	void Display();
	
	void setX(int x);

	int getX();

	void setY(int y);

	int getY();

	double Distance(MyPoint p);

	~MyPoint();
};

#endif // !MYPOINT_H
