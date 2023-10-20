#pragma once
#include "IShape.h"

class Hyperbol :public IShape
{
private:
	float _XT;
	float _YT;
	float _A;
	float _B;
public:
	Hyperbol();
	Hyperbol(float XT, float YT, float A, float B);


	void plotShape();


	string toString();
};

