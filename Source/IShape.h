#pragma once
#include"Object.h"

class IShape :public Object
{
private:

public:
	string toString() = 0;
	virtual void plotShape() = 0;
};

