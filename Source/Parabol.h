#pragma once
#include "IShape.h"

class Parabol :public IShape
{
private:
	float _XT;
	float _YT;
	float _P;
public:
	Parabol();
	Parabol(float XT, float YT, float P);


	void plotShape();


	string toString();
};

