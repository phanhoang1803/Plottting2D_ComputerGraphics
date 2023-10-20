#pragma once
#include "IParsable.h"

class CircleParser :public IParsable
{
private:

public:
	Object* parse(string org);
	string toString() { return ""; };
};

