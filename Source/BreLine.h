#pragma once
#include "IShape.h"

class BreLine :public IShape
{
private:
	float _X1;
	float _Y1;
	float _X2;
	float _Y2;
public:
	BreLine();
	BreLine(float X1, float Y1, float X2, float Y2);

	void plotShape();

	string toString();
};

