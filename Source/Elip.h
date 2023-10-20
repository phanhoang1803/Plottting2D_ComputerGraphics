#pragma once
#include "IShape.h"

class Elip :public IShape
{
private:
	float _XT;
	float _YT;
	float _A;
	float _B;
public:
	Elip();
	Elip(float XT, float YT, float A, float B);


	void plotShape();


	string toString();
};

