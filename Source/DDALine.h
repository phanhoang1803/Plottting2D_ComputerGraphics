#pragma once
#include "IShape.h"

class DDALine :public IShape
{
private:
	float _X1;
	float _Y1;
	float _X2;
	float _Y2;
public:
	DDALine();
	DDALine(float X1, float Y1, float X2, float Y2);

	void plotShape();

	string toString();
};

