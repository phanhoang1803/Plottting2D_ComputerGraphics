#pragma once
#include "IShape.h"

class Circle :public IShape
{
private:
	float _XT;
	float _YT;
	float _R;
public:
	Circle();
	Circle(float XT, float YT, float R);

	void plotShape();

	string toString();
};

